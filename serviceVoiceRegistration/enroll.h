#ifndef ENROLL_H
#define ENROLL_H

#include "feat/wave-reader.h"
#include "base/kaldi-common.h"
#include "util/common-utils.h"
#include "feat/feature-mfcc.h"
#include "feat/feature-functions.h"
#include "matrix/kaldi-matrix.h"
#include "gmm/diag-gmm.h"
#include "gmm/full-gmm.h"
#include "hmm/posterior.h"
#include "gmm/am-diag-gmm.h"
#include "ivector/ivector-extractor.h"
#include "hmm/transition-model.h"
#include "ivector/plda.h"
#include "ivector/voice-activity-detection.h"
#include <sstream>
#include <stdio.h>
#include "messages/VoiceRegisterMessage.grpc.pb.h"

using namespace kaldi;
extern "C"
{
#include <fvad.h>
}
class Enroll
{
public:
    Enroll();
    ~Enroll();

    // Pre-trained mathematics
    bool process_vad(Vector<BaseFloat> wave_piece_buffer, Fvad *vad, size_t framelen);

    // Initialize the parameters for MFCC extracting
    void MfccInitiation(WaveData *wave, MfccOptions *op);

    // Append Deltas and double deltas to MFCCs, then apply CMVN
    void MfccProcess(Matrix<BaseFloat> *feats, Matrix<BaseFloat> *processed_feats);

    // Select Precompute Gaussian indices for pruning
    // For each frame, gives a list of the n best Gaussian indices sorted from best to worst
    void SelectPost(Matrix<BaseFloat> *feats, Posterior *post);

    // Extract i-vectors
    void ExtractIvectors(Matrix<BaseFloat> *feats, Posterior *post, Vector<BaseFloat> *ivector);

    // Update/Create speaker model for speaker id
    void UpdateSpkModel(std::string spkid, Vector<BaseFloat> *ivector, std::string ivPath, int requestType, VoiceRegisterResponseMsg* responseMsg);

    // Training process
    void TrainProcess(std::string spkid, Matrix<BaseFloat> *feats, std::string ivPath, int requestType, VoiceRegisterResponseMsg* responseMsg);

    void enrollVoice(std::string speakerid, std::string voiceDir, std::string fileName, int requestType, VoiceRegisterResponseMsg* responseMsg);

    bool removeFolder(std::string path);

    bool createFolder(std::string path);


private:
    DiagGmm gmm; // Diagonal covariance UBM, pre-trained model
    FullGmm fgmm; // Full covariance UBM, pre-trained model
    IvectorExtractor extractor; // I-vector extractor, pre-trained model
    Matrix<BaseFloat> transform; // LDA + WCCN compensation model, pre-trained model
    Vector<BaseFloat> mean; // Global mean of i-vectors, pre-trained model
    Plda plda; // PLDA, pre-trained model
};

#endif // ENROLL_H
