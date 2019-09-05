#include <opencv2/opencv.hpp>

#include <cmath>
#include <iostream>
#include <vector>

// 一阶bezier curve
std::vector<cv::Point2d> OneOrder(int pos_num, const cv::Point2d& start,
                                  const cv::Point2d& goal) {
  std::vector<cv::Point2d> result_bezier;
  result_bezier.reserve(pos_num);

  double t = 0.0;
  for (int16_t i = 0; i < pos_num; ++i) {
    t = static_cast<double>(i) / static_cast<double>(pos_num);
    cv::Point2d temp;
    temp.x = (1.0 - t) * start.x + t * goal.x;
    temp.y = (1.0 - t) * start.y + t * goal.y;
    result_bezier.push_back(temp);
  }
  return result_bezier;
}

// 二阶bezier curve
std::vector<cv::Point2d> SecOrder(int pos_num, const cv::Point2d& start,
                                  const cv::Point2d& goal,
                                  const cv::Point2d& mid) {
  std::vector<cv::Point2d> result_bezier;
  result_bezier.reserve(pos_num + 1);

  double t = 0.0;
  for (int16_t i = 0; i <= pos_num; ++i) {
    t = static_cast<double>(i) / static_cast<double>(pos_num);
    cv::Point2d temp;
    temp.x = pow((1.0 - t), 2.0) * start.x + 2.0 * t * (1.0 - t) * mid.x +
             pow(t, 2.0) * goal.x;
    temp.y = pow((1.0 - t), 2.0) * start.y + 2.0 * t * (1.0 - t) * mid.y +
             pow(t, 2.0) * goal.y;
    result_bezier.push_back(temp);
  }
  return result_bezier;
}

int main() {
  cv::Point2d start(10.0, 10.0);
  cv::Point2d mid(40.0, 290.0);
  cv::Point2d goal(150.0, 180.0);

  std::vector<cv::Point2d> result = SecOrder(20, start, goal, mid);

  cv::Mat img(300, 200, CV_8UC3, cv::Scalar::all(255));

  cv::circle(img, start, 3, cv::Scalar(0, 255, 0), 1, cv::LINE_AA);
  cv::circle(img, goal, 3, cv::Scalar(0, 255, 0), 1, cv::LINE_AA);
  cv::circle(img, mid, 3, cv::Scalar(0, 255, 0), 1, cv::LINE_AA);

  cv::line(img, start, mid, cv::Scalar::all(0), 1, cv::LINE_AA);
  cv::line(img, goal, mid, cv::Scalar::all(0), 1, cv::LINE_AA);

  std::cout << "result size : " << result.size() << std::endl;
  for (auto& elem : result) {
    cv::circle(img, elem, 1, cv::Scalar(255, 0, 0), 1, cv::LINE_AA);
  }

  cv::namedWindow("one order", cv::WINDOW_NORMAL);
  cv::imshow("one order", img);

  cv::waitKey(0);

  return 0;
}
