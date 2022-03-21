#include "shiftingonlinecachefeature.h"

//template<class C>
void ShiftingOnlineCacheFeature::GetFrame(int32 frame, VectorBase<BaseFloat> *feat) {
  KALDI_ASSERT(frame >= 0);
  if (static_cast<size_t>(frame) < cache_.size() && cache_[frame] != NULL) {
    feat->CopyFromVec(*(cache_[frame]));
  } else {
    if (static_cast<size_t>(frame) >= cache_.size())
      cache_.resize(frame + 1, NULL);
    int32 dim = this->Dim();
    cache_[frame] = new Vector<BaseFloat>(dim);
    // The following call will crash if frame "frame" is not ready.
    src_->GetFrame(frame, cache_[frame]);

    feat->CopyFromVec(*(cache_[frame]));
  }
}

//template<class C>
void ShiftingOnlineCacheFeature::ClearCache() {
  for (size_t i = 0; i < cache_.size(); i++)
    delete cache_[i];
  cache_.resize(0);
}
