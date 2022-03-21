#ifndef IDENTIFYSPEAKER_H
#define IDENTIFYSPEAKER_H

//#include <pthread.h>
#include <stdio.h>
#include <vector>

#include "base/kaldi-common.h"
#include "matrix/kaldi-matrix.h"
#include "ivector/plda.h"
#include "feat/feature-mfcc.h"
#include "ivector/ivector-extractor.h"
#include "extension/feat/ShiftingOnlineGenericBaseFeature.h"
#include "extension/feat/shiftingonlinecachefeature.h"
#include "feat/wave-reader.h"
#include "messages/VoiceVerificationMessage.grpc.pb.h"


using namespace kaldi;
using namespace std;

extern "C"
{
  #include <fvad.h>
}

class IdentifySpeaker
{
public:
    IdentifySpeaker();
    ~IdentifySpeaker();

    bool process_vad(Vector<BaseFloat> wave_piece_buffer, Fvad *vad, size_t framelen);

    // bring the last two flags to the front, and add the new vad result to the last index
    void UpdateVadFlag(std::vector<int> *vad_result_flag, bool vadres);

    // Copy MFCC features from OnlineFeatureInterface* to Matrix<BaseFloat>*
    void GetSpeechMfcc(ShiftingOnlineFeatureInterface *a, Matrix<BaseFloat> *output, std::vector<int> *vad_result_buffer);

    // Update mfcc_feats_buffer(800), discard the first 320 frames and move the last 480 frames to the beginning of buffer.
    // The last 320 frames of updated buffer are 0s
    void UpdateMFCCBuffer(Matrix<BaseFloat> *feats, std::vector<int> *vad_result_buffer);

    void SelectVadFrames(Matrix<BaseFloat> *feats, std::vector<int> *vad_result_buffer, Matrix<BaseFloat> *mfcc_selected_buffer);

    // Initialize the parameters for MFCC extracting
    void MfccInitiation(WaveData *wave, MfccOptions *op);

    // Append Deltas and double deltas to MFCCs, then apply CMVN
    void MfccProcess(Matrix<BaseFloat> *feats, Matrix<BaseFloat> *processed_feats);

    // Select Precompute Gaussian indices for pruning
    // For each frame, gives a list of the n best Gaussian indices sorted from best to worst
    void SelectPost(Matrix<BaseFloat> *feats, Posterior *post);

    // Extract i-vectors
    void ExtractIvectors(Matrix<BaseFloat> *feats, Posterior *post, Vector<BaseFloat> *ivector);

    // Apply length normalization, LDA and WCCN to i-vectors
    void IvectorProcess(Vector<BaseFloat> *ivector, Vector<BaseFloat> *processed_ivector);

    // Compare a processed i-vector to all registered speaker models
    float ComputeScore(Vector<BaseFloat> *ivector, std::string pathFolderTrained);

    // Process a 800 frame feature buffer
    int TestProcess(Matrix<BaseFloat> *feats, std::string pathFolderTrained);

    // Thread_Process, processing 800-frame (8 seconds) feature buffer every 3.2 seconds
//    void* Thread_Process(void*);
    void Thread_Process(std::string pathFolderTrained, VoiceVerificationResponseMsg* responseMsg);

    // Thread_Read, read 10ms audio segments and extract MFCCs
//    void* Thread_Read(void*);
    void Thread_Read();

    bool fexists(const char *filename);

    int identify(std::string pathFile, std::string pathTrain, VoiceVerificationResponseMsg* response);


private:
    // lock and global var shared between threads
    pthread_mutex_t m_wave = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t m_mfcc = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t cv_wave = PTHREAD_COND_INITIALIZER;
    pthread_cond_t cv_mfcc = PTHREAD_COND_INITIALIZER;
    // notification flags between threads
    bool newAudio_ready = false;
    bool newTest_ready = false;
    bool file_finish = false;
    bool enough_vad = false;
    // Set parameters
    int32 segment_shift = 320; // segment shift, a new decision is made every 320 frames (~ 3.2 seconds)
    int32 segment_size = 800; //segment length, decisions are made based on 800 frames (~ 8 seconds)
    float accept_threshold = 50.0; // threshold, can be adjust due to different system sensitivity, default 15
    Fvad *vad = NULL; // create vad
    bool vadres;
    BaseFloat score;
    int sampling_rate;
    // Initialize audio and feature buffers
    Matrix<BaseFloat> mfcc_feats_buffer{Matrix<BaseFloat>(segment_size, 20, kSetZero)}; // Feature buffer (800 * 20) initalized with zeros,
                                                                         // 20 is the dimension of MFCC
    Matrix<BaseFloat> mfcc_selected_buffer;
    Vector<BaseFloat> wave_piece_buffer; // Audio buffer, store 10ms audio
    std::vector<int> vad_result_flag{std::vector<int>(3, 0)};
    std::vector<int> vad_results_buffer{std::vector<int>(segment_size, 0)};
    // Initialize parameters and pre-trained models
    MfccOptions op_mfcc; // MFCC parameters
    DiagGmm gmm; // Diagonal covariance UBM, pre-trained model
    FullGmm fgmm; // Full covariance UBM, pre-trained model
    IvectorExtractor extractor; // I-vector extractor, pre-trained model
    Matrix<BaseFloat> transform; // LDA + WCCN compensation model, pre-trained model
    Vector<BaseFloat> mean; // Global mean of i-vectors, pre-trained model
    Plda plda; // PLDA, pre-trained model

};

#endif // IDENTIFYSPEAKER_H
