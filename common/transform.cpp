//
// Created by cyberse on 18/01/2018.
//

#include "transform.h"

std::vector<std::vector<cv::Point> > convertToMat(std::vector<cv::Rect> input) {
        std::vector< std::vector< cv::Point > > result;
        for(auto rect : input){
            std::vector< cv::Point > mat;
            mat.push_back(cv::Point(rect.x,rect.y));
            mat.push_back(cv::Point(rect.x + rect.width,rect.y));
            mat.push_back(cv::Point(rect.x + rect.width,rect.y + rect.height));
            mat.push_back(cv::Point(rect.x,rect.y + rect.height));

            result.push_back(mat);
        }
        return result;
}

std::vector<cv::Rect> convertToRect(std::vector<std::vector<cv::Point> > input) {
    std::vector<cv::Rect> result;
    for(auto vpoint : input){
        cv::Rect rect;
        rect.x = 9999;
        rect.y = 9999;
        int rectRight = 0;
        int rectTop = 0;
        for(auto point : vpoint){
            if(point.x <= rect.x){
                rect.x = point.x;
            }
            if(point.y <= rect.y){
                rect.y = point.y;
            }
            if(point.x >= rectRight){
                rectRight = point.x;
            }
            if(point.y >= rectTop){
                rectTop = point.y;
            }
        }
        rect.width =  rectRight - rect.x;
        rect.height = rectTop - rect.y;
        result.push_back(rect);
    }
    return result;
}
