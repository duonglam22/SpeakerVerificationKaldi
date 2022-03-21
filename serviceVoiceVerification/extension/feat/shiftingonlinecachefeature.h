#ifndef SHIFTINGONLINECACHEFEATURE_H
#define SHIFTINGONLINECACHEFEATURE_H

#include <string>
#include <vector>
#include "matrix/matrix-lib.h"
#include "util/common-utils.h"
#include "base/kaldi-error.h"
#include "feat/feature-functions.h"
#include "feat/feature-mfcc.h"
#include "extension/feat/ShiftingOnlineFeatureItf.h"

using namespace kaldi;

class ShiftingOnlineCacheFeature: public ShiftingOnlineFeatureInterface {
 public:
  virtual int32 Dim() const { return src_->Dim(); }

  virtual bool IsLastFrame(int32 frame) const {
    return src_->IsLastFrame(frame);
  }
  virtual BaseFloat FrameShiftInSeconds() const {
    return src_->FrameShiftInSeconds();
  }

  virtual int32 NumFramesReady() const { return src_->NumFramesReady(); }

  virtual int NumVadReady() const { return src_->NumVadReady(); }

  virtual void GetFrame(int32 frame, VectorBase<BaseFloat> *feat);

  virtual int GetVad(int frame){ return src_->GetVad(frame); }

  virtual ~ShiftingOnlineCacheFeature() { ClearCache(); }

  // Things that are not in the shared interface:

  void ClearCache();  // this should be called if you change the underlying
                      // features in some way.

  explicit ShiftingOnlineCacheFeature(ShiftingOnlineFeatureInterface *src): src_(src) { }
 private:

  ShiftingOnlineFeatureInterface *src_;  // Not owned here
  std::vector<Vector<BaseFloat>* > cache_;
};


#endif // SHIFTINGONLINECACHEFEATURE_H
