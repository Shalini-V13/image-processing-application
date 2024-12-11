# Image Processing Toolkit

This code demonstrates basic image processing techniques using the OpenCV library. It performs the following steps:

1. Load an Input Image
    Loads an image from a specified path and checks for successful loading.
        Replace the image path (C:/Users/user/image-processing-application/src/Resources/pattern.jpg) with the path to your image.

2. Convert to Grayscale
    Converts the loaded image to grayscale for simpler processing.

3. Apply Gaussian Blur
    Reduces noise in the image using a Gaussian blur filter.

4. Edge Detection
    Detects edges in the image using the Canny edge detection algorithm.

5. Contour Detection
    Identifies contours in the edges detected and displays them as overlays on the original image.

6. Display Results
    Shows the original image, grayscale image, edges detected, and contours in separate windows.

7. Output Information
    Logs the number of detected contours in the console.


Usage
Ensure OpenCV is installed and set up in your development environment. Run the program, and it will display the results in graphical windows. Use the imshow function to visualize each processing step.