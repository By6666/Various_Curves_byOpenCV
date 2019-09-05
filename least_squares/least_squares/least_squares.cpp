#include "least_squares.h"

void LeastSquarePolyFit(const std::vector<cv::Point>& pos_list,
                        int16_t multiplicity, cv::Mat* result) {
  /* 曲线拟合 计算 X * A = Y */
  /* 构造 X 矩阵*/
  cv::Mat x = cv::Mat::zeros(multiplicity + 1, multiplicity + 1, CV_64FC1);

  /* 计算第一行 */
  for (uint8_t i = 0; i <= multiplicity; ++i) {
    for (uint8_t k = 0; k < pos_list.size(); ++k) {
      x.at<double>(0, i) += pow(pos_list[k].x, i);
    }
  }
  /* 逐行赋值 节省计算次数 */
  for (uint8_t i = 1; i <= multiplicity; ++i) {
    for (uint8_t j = 0; j <= multiplicity; ++j) {
      if (j == multiplicity) {
        for (uint8_t k = 0; k < pos_list.size(); ++k) {
          x.at<double>(i, j) += pow(pos_list[k].x, i + j);
        }
      } else {
        x.at<double>(i, j) = x.at<double>(i - 1, j + 1);
      }
    }
  }
  std::cout << std::endl << x << std::endl;

  /* 构造 Y 矩阵 */
  cv::Mat y = cv::Mat::zeros(multiplicity + 1, 1, CV_64FC1);
  for (uint8_t i = 0; i <= multiplicity; ++i) {
    for (uint8_t k = 0; k < pos_list.size(); ++k) {
      y.at<double>(i, 0) += pos_list[k].y * pow(pos_list[k].x, i);
    }
  }
  std::cout << std::endl << y << std::endl;

  /* 构造 A 矩阵 */
  *result = cv::Mat::zeros(multiplicity + 1, 1, CV_64FC1);

  cv::solve(x, y, *result);

  std::cout << std::endl << *result << std::endl;

  std::cout << "poly result : " << std::endl;
  std::cout << " y = " << result->at<double>(0, 0);
  for (int16_t i = 1; i <= multiplicity; ++i) {
    std::cout << " + " << result->at<double>(i, 0) << " * x^" << i;
  }
  std::cout << std::endl;
}
