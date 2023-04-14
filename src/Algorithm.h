#pragma once
#include <opencv2/core.hpp>
#include <math.h>



namespace alg {
	using namespace cv;

	value struct resultStr {
		bool detection_flag;
		int result_score;
	};

	void img_prep(Mat& input_image, Mat& output_image)
	{
		Mat img, mask;
		std::vector<std::vector<cv::Point>> cont;
		resize(input_image, img, cv::Size(), 0.2, 0.2);
		threshold(img, mask, 0, 255,THRESH_OTSU);
		morphologyEx(mask, mask, MORPH_CLOSE, getStructuringElement(MORPH_ELLIPSE, cv::Size(10, 10)));
		findContours(mask, cont, RETR_LIST, CHAIN_APPROX_SIMPLE);
		int largest_area = 0, largest_contour_index = 0;
		for (int i = 0; i < cont.size(); i++) {// iterate through each contour.
			double a = contourArea(cont[i], false);  //  Find the area of contour
			if (a > largest_area) {
				largest_area = a;
				largest_contour_index = i;                //Store the index of largest contour
			}
		}
		Scalar color(rand() & 255, rand() & 255, rand() & 255);
		drawContours(img, cont, largest_contour_index, color, 1);
		//adaptiveThreshold(img, img, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 0);
		resize(img, img, cv::Size(2592, 1944), 0, 0);
		output_image = input_image;

	}

	void exor_images() {
			
	}

	void show(Mat& input_image, std::string name) {
		namedWindow(name, WINDOW_AUTOSIZE);
		imshow(name, input_image);
		waitKey(1);
	}

	void str2console(std::string& str) {
		System::String^ str2 = gcnew System::String(str.c_str());
		System::Diagnostics::Debug::WriteLine(str2);
	}

	resultStr alg_sobel(Mat& input_image, int p1x, int p1y, int p2x, int p2y, int filter, int thresh, bool calib_flag, int defect_type) {
		Mat cropped;
		Rect roi(p1x, p1y, p2x - p1x, p2y - p1y);
		int sx, sy, sw, sh;
		sx = 0.75 * roi.width / 4;
		sy = 0.75 * roi.height / 3;
		sw = 0.75 * roi.width / 2;
		sh = 0.75 * roi.height / 2;
		Rect roi_s(sx, sy, sw, sh);
		input_image(roi).copyTo(cropped);
		resize(cropped, cropped, cv::Size(), 0.75, 0.75);
		
		equalizeHist(cropped, cropped);
		GaussianBlur(cropped, cropped, cv::Size(11, 11), 0, 0);
		
		Mat grad_x, grad_y;
		Mat abs_grad_x, abs_grad_y;
		double absX, absY;
		cv::Size strClose, strOpen;
		Sobel(cropped, grad_x, CV_16S, 1, 0, 3);
		Sobel(cropped, grad_y, CV_16S, 0, 1, 3);
		convertScaleAbs(grad_x, abs_grad_x);
		convertScaleAbs(grad_y, abs_grad_y);
		switch (defect_type) {
			case 1:
				absX = 0.25;
				absY = 0.75;
				strClose = cv::Size(5, 3);
				strOpen = cv::Size(7, 3);
				break;
			case 2:
				absX = 0.5;
				absY = 0.5;
				strClose = cv::Size(5, 5);
				strOpen = cv::Size(5, 5);
				break;
			default:
				break;
		}
		addWeighted(abs_grad_x, absX, abs_grad_y, absY, 0, cropped);
		threshold(cropped, cropped, filter, 255, THRESH_BINARY);
		if (calib_flag) show(cropped, "1-) Filtre");
		morphologyEx(cropped, cropped, MORPH_CLOSE, getStructuringElement(MORPH_ELLIPSE, strClose));
		morphologyEx(cropped, cropped, MORPH_OPEN, getStructuringElement(MORPH_ELLIPSE, strOpen));
		if (calib_flag) show(cropped, "2-) Morfoloji");
		cropped(roi_s).copyTo(cropped);
		if (calib_flag) show(cropped, "3-) ROI");

		int result(countNonZero(cropped));
		str2console("Pixels: " + std::to_string(result));

		if (result > thresh) return resultStr{ true, result };
		else return resultStr{ false, result };
	}

	void draw_roi(Mat& input_image, char color_code, int p1x, int p1y, int p2x, int p2y) {
		Scalar color(0, 0, 0);
		switch (color_code)
		{
		case 'r':
			color[2] = 255; // Red Window
			break;
		case 'g':
			color[1] = 255; // Green Window
			break;
		case 'b':
			color[0] = 255; // Blue Window
			break;
		case 'k':
			break; // Black Window
		case 'w': {
			color[0] = 255;
			color[1] = 255;
			color[2] = 255; // White Window
			break;
			}
		default:
			break;
		}
			cv::Point p1(p1x, p1y);
			cv::Point p2(p2x, p2y);
			rectangle(input_image, p1, p2, color, 3);
	}

}