

#ifndef INSTRECLIB_SEGMENTATIONPROVIDER_H
#define INSTRECLIB_SEGMENTATIONPROVIDER_H

#include <memory>

#include "../../InfiniTAM/InfiniTAM/ITMLib/Objects/ITMView.h"
#include "InstanceSegmentationResult.h"

namespace instreclib {
namespace segmentation {

/// \brief Performs semantic segmentation on input frames.
class SegmentationProvider {
 public:
  virtual ~SegmentationProvider(){};

  /// \brief Performs semantic segmentation of the given frame.
  /// Usually uses only RGB data, but some segmentation pipelines may leverage
  /// e.g., depth as
  /// well.
  virtual std::shared_ptr<InstanceSegmentationResult> SegmentFrame(
      ITMUChar4Image *rgb) = 0;

  virtual ITMUChar4Image *GetSegResult() = 0;

  virtual const ITMUChar4Image *GetSegResult() const = 0;
};
}
}

#endif  // INSTRECLIB_SEGMENTATIONPROVIDER_H
