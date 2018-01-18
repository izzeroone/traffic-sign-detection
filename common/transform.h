//
// Created by cyberse on 18/01/2018.
//

#ifndef TRAFFIC_SIGN_DETECTION_TRANSFORM_H
#define TRAFFIC_SIGN_DETECTION_TRANSFORM_H

#include <opencv2/core/types.hpp>

std::vector<cv::Rect> convertToRect(std::vector< std::vector< cv::Point > > input);
std::vector< std::vector< cv::Point > > convertToMat(std::vector<cv::Rect> input);



#endif //TRAFFIC_SIGN_DETECTION_TRANSFORM_H
