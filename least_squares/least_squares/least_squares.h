#ifndef LEAST_SQUARES_H
#define LEAST_SQUARES_H

#include <opencv2/opencv.hpp>

#include <iostream>

/* 最小二乘法拟合多项式 */
void LeastSquarePolyFit(const std::vector<cv::Point>& pos_list,
                        int16_t multiplicity, cv::Mat* result);

#endif