#include <common.hpp>
#include <limits>
#include <matcher.hpp>
#include <opencv2/core/types.hpp>
#include <vector>

SeqHarrisKeyPointMatcher::SeqHarrisKeyPointMatcher(cv::Mat &image1,
                                                   cv::Mat &image2,
                                                   HarrisCornerOptions options)
    : image1_(image1), image2_(image2), options_(options) {}

/**
 * @brief Match keypoints detected by Harris corner detector
 *
 * We typically take a patch around the keypoint and compare the distance
 *
 * @return std::vector<cv::DMatch> the matches
 */
std::vector<cv::DMatch>
SeqHarrisKeyPointMatcher::matchKeyPoints(std::vector<cv::KeyPoint> keypointsL,
                                         std::vector<cv::KeyPoint> keypointsR) {
  return seqHarrisMatchKeyPoints(keypointsL, keypointsR, image1_, image2_,
                                 options_, 0);
}
