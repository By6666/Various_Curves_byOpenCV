#include <opencv2/opencv.hpp>

#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "least_squares/least_squares.h"

int main() {

  // cv::Mat im(500, 500, CV_8UC3, cv::Scalar(255, 255, 255));
  // // std::cout << im << std::endl;

  // cv::imshow("123", im);

  // cv::Mat imp;
  // imp = cv::imread("//home//by//Documents//opencv_draw//data//pic2.png");
  // cv::imshow("456", imp);

  // cv::Mat c = (cv::Mat_<int16_t>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
  // std::cout << c << std::endl;

  // cv::Point2f start, end;
  /* row=x,col=y */
  // start = cv::Point(25.0f, 5.0f);
  // end = cv::Point(250.0f, 250.5f);

  /* Mat代表矩阵，第一个参数为行数，第二个为列数 */
  // cv::Mat img(1200, 1600, CV_8UC3, cv::Scalar::all(0));
  // cv::line(img, cv::Point(25.0f, 5.0f), cv::Point(250.0f, 250.5f),
  //          cv::Scalar(0, 255, 255), 1, CV_AA, 0);

  // cv::line(img, cv::Point(300.0f, 300.0f), cv::Point(500.0f, 499.5f),
  //          cv::Scalar(0, 0, 255), 1, 8, 0);

  // /* 画出sin曲线 */
  // std::vector<cv::Point> poly_pos;
  // for (int16_t i = 0; i < 500; ++i) {
  //   double y = fabs(75 * sin(4 * (static_cast<double>(i) / 180)));
  //   std::cout << y << "  ";
  //   poly_pos.push_back(cv::Point(i, static_cast<int>(y)));
  // }
  // cv::polylines(img, poly_pos, false, cv::Scalar(0, 200, 0), 1, CV_AA, 0);

  // std::vector<cv::Point> poly_pos;
  // poly_pos.push_back(cv::Point(10, 10));
  // poly_pos.push_back(cv::Point(23, 16));
  // poly_pos.push_back(cv::Point(100, 99));
  // poly_pos.push_back(cv::Point(50, 250));
  // poly_pos.push_back(cv::Point(10, 300));
  // poly_pos.push_back(cv::Point(250, 350));
  // poly_pos.push_back(cv::Point(40, 450));

  // double a0 = 1.0, a1 = 0.05, a2 = 0.0, a3 = 0.0005;
  // for (int16_t i = 0; i < 100; ++i) {
  //   double y = a0 + a1 * static_cast<double>(i) +
  //              a2 * pow(static_cast<double>(i), 2.0) +
  //              a3 * pow(static_cast<double>(i), 3.0);
  //   poly_pos.push_back(cv::Point(i, static_cast<int>(y)));
  // }
  // cv::polylines(img, poly_pos, false, cv::Scalar(0, 200, 0), 1, CV_AA, 0);

  // /* 输出原始数据点 */
  // cv::Point data[] = {
  //     cv::Point(50, 120),  cv::Point(74, 110), cv::Point(98, 100),
  //     cv::Point(122, 100), cv::Point(144, 80), cv::Point(168, 80),
  //     cv::Point(192, 70),  cv::Point(214, 50), cv::Point(236, 40),
  //     cv::Point(262, 20),  cv::Point(282, 20), cv::Point(306, 30),
  //     cv::Point(328, 40),  cv::Point(356, 50), cv::Point(376, 50),
  //     cv::Point(400, 50),  cv::Point(424, 50), cv::Point(446, 40),
  //     cv::Point(468, 30)};

  int16_t poly_multip = 0;
  while (1) {
    std::cout << "Please input mutip : ";
    std::cin >> poly_multip;
    if (poly_multip < 0) {
      std::cout << "input error , Please input agin !!" << std::endl;
      continue;
    }

    cv::Mat img(1200, 1600, CV_8UC3, cv::Scalar::all(0));
    std::vector<cv::Point> orign_data;
    // orign_data.push_back(cv::Point(50, 58));
    // orign_data.push_back(cv::Point(100, 58));
    // orign_data.push_back(cv::Point(150, 70));
    // orign_data.push_back(cv::Point(200, 90));
    // orign_data.push_back(cv::Point(252, 140));
    // orign_data.push_back(cv::Point(300, 220));
    // orign_data.push_back(cv::Point(350, 400));

    orign_data.push_back(cv::Point(50, 120));
    orign_data.push_back(cv::Point(74, 110));
    orign_data.push_back(cv::Point(98, 100));
    orign_data.push_back(cv::Point(122, 100));
    orign_data.push_back(cv::Point(144, 80));
    orign_data.push_back(cv::Point(168, 80));
    orign_data.push_back(cv::Point(192, 70));
    orign_data.push_back(cv::Point(214, 50));
    orign_data.push_back(cv::Point(236, 40));
    orign_data.push_back(cv::Point(262, 20));
    orign_data.push_back(cv::Point(282, 20));
    orign_data.push_back(cv::Point(306, 30));
    orign_data.push_back(cv::Point(328, 40));
    orign_data.push_back(cv::Point(356, 50));
    orign_data.push_back(cv::Point(376, 50));
    orign_data.push_back(cv::Point(400, 50));
    orign_data.push_back(cv::Point(424, 50));
    orign_data.push_back(cv::Point(446, 40));
    orign_data.push_back(cv::Point(468, 30));


    // orign_data.push_back(cv::Point(200, 30));
    // orign_data.push_back(cv::Point(300, 30));
    // orign_data.push_back(cv::Point(200, 60));
    // orign_data.push_back(cv::Point(300, 60));

    for (uint8_t i = 0; i < orign_data.size(); ++i) {
      cv::circle(img, orign_data[i], 5, cv::Scalar(0, 0, 255), 1, CV_AA, 0);
    }
    // cv::polylines(img, orign_data, false, cv::Scalar(0, 0, 255), 1, CV_AA,
    // 0);

    cv::Mat result;
    LeastSquarePolyFit(orign_data, poly_multip, &result);
    std::vector<cv::Point> output_cruve;
    for (int16_t i = orign_data[0].x - 10; i <= orign_data.back().x + 10; ++i) {
      double y = 0.0;
      for (int16_t j = 0; j <= poly_multip; ++j) {
        y += result.at<double>(j, 0) * pow(i, j);
      }
      output_cruve.push_back(cv::Point(i, static_cast<int>(y)));
      // std::cout << "(" << i << "," << static_cast<int>(y) << ") ";
    }
    std::cout << std::endl;
    cv::polylines(img, output_cruve, false, cv::Scalar(0, 200, 0), 1, CV_AA, 0);

    std::string title = "Pic — ";
    title = title + std::to_string(poly_multip) + " 次多项式拟合";
    cv::imshow(title, img);
    break;
  }

  cv::waitKey(0);
}
