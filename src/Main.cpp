#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Load the input image
    string imagePath = "C:/Users/user/image-processing-application/src/Resources/pattern.jpg"; // Replace with the path to your image
    Mat inputImage = imread(imagePath, IMREAD_COLOR);

    if (inputImage.empty()) {
        cerr << "Error: Unable to load image. Check the file path." << endl;
        return -1;
    }

    // Convert to grayscale
    Mat grayImage;
    cvtColor(inputImage, grayImage, COLOR_BGR2GRAY);

    // Apply Gaussian Blur to reduce noise
    Mat blurredImage;
    GaussianBlur(grayImage, blurredImage, Size(5, 5), 0);

    // Perform edge detection using Canny
    Mat edges;
    Canny(blurredImage, edges, 100, 200);

    // Find contours
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(edges, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

    // Draw contours on the original image
    Mat outputImage = inputImage.clone();
    for (size_t i = 0; i < contours.size(); i++) {
        Scalar color = Scalar(0, 255, 0); // Green color
        drawContours(outputImage, contours, static_cast<int>(i), color, 2, LINE_8, hierarchy, 0);
    }

    // Display number of detected contours
    cout << "Number of contours detected: " << contours.size() << endl;

    // Show results
    imshow("Original Image", inputImage);
    imshow("Gray Image", grayImage);
    imshow("Edges", edges);
    imshow("Contours", outputImage);

    // Wait for a key press
    waitKey(0);

    return 0;
}
