//name:durvesh kumar ; functions: stdfilt(), imfill() ; input argument : any image like - lena.jpg ; output will be an image ; 
/*
 * 
 * 
 * WORKING INTRODUCTION
 * 
 * 
 * 
  int the mail function to use imfill
  define an image and pass the parameters as follows
  
  Mat image2 = imfill(image, "gray"); here image is the image which contains a real 2D image and second argument contains the color of image you want -- right now only gray , white and black are supported
  imshow("Display window" , image2);
  
  for stdfilt function
  Mat image2 = stdfilt(image); here image is the image which contains a real 2D image
  imshow("Display window" , image2);

*/

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <cmath>

using namespace cv;
using namespace std;

Mat stdfilt(Mat image){
	Mat roi(image);
	int b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0,b8=0; // initialising the blue component of the surrounding pixels to be zero
	int g1=0,g2=0,g3=0,g4=0,g5=0,g6=0,g7=0,g8=0; // initialising the green component of the surrounding pixels to be zero
	int r1=0,r2=0,r3=0,r4=0,r5=0,r6=0,r7=0,r8=0; // initialising the red component of the surrounding pixels to be zero
	int avg = 0,var = 0;   //initialisig average and variance to zero
	for(int i = 0; i < roi.rows; i++)
      {
        for(int j = 0; j < roi.cols; j++)
         {
			 // accesssing all the surrounding pixels of the current pixel and storing it in the variables
			 if(i-1 >= 0 && j >= 0)
			 {
				 b1 = roi.at<cv::Vec3b>(i-1,j)[0];
				 g1 = roi.at<cv::Vec3b>(i-1,j)[1];
				 r1 = roi.at<cv::Vec3b>(i-1,j)[2];
			     //cout << b1 << " "; 	 
			 }
			 if(j >= 0 && i+1 < roi.rows)
			 {
				 b2 = roi.at<cv::Vec3b>(i+1,j)[0];
				 g2 = roi.at<cv::Vec3b>(i+1,j)[1];
				 r2 = roi.at<cv::Vec3b>(i+1,j)[2];
			 }
			 if(j+1 < roi.cols)
			 {
				 b3 = roi.at<cv::Vec3b>(i,j+1)[0];
				 g3 = roi.at<cv::Vec3b>(i,j+1)[1];
				 r3 = roi.at<cv::Vec3b>(i,j+1)[2];
			 }
			 if(j-1 >= 0)
			 {
				 b4 = roi.at<cv::Vec3b>(i,j-1)[0];
				 g4 = roi.at<cv::Vec3b>(i,j-1)[1];
				 r4 = roi.at<cv::Vec3b>(i,j-1)[2];
			 }
			 if(i+1 < roi.rows && j+1 < roi.cols)
			 {
				 b5 = roi.at<cv::Vec3b>(i+1,j+1)[0];
				 g5 = roi.at<cv::Vec3b>(i+1,j+1)[1];
				 r5 = roi.at<cv::Vec3b>(i+1,j+1)[2];
			 }
			 if(i-1 >= 0 && j+1 < roi.cols)
			 {
				 b6 = roi.at<cv::Vec3b>(i-1,j+1)[0];
				 g6 = roi.at<cv::Vec3b>(i-1,j+1)[1];
				 r6 = roi.at<cv::Vec3b>(i-1,j+1)[2];
			 }
			 if(j-1 >= 0 && i-1 >= 0)
			 {
				 b7 = roi.at<cv::Vec3b>(i-1,j-1)[0];
				 g7 = roi.at<cv::Vec3b>(i-1,j-1)[1];
				 r7 = roi.at<cv::Vec3b>(i-1,j-1)[2];
			 }
			 if(j-1 >= 0 && i+1 < roi.rows)
			 {
				 b8 = roi.at<cv::Vec3b>(i+1,j-1)[0];
				 g8 = roi.at<cv::Vec3b>(i+1,j-1)[1];
				 r8 = roi.at<cv::Vec3b>(i+1,j-1)[2];
			 }
			 //for blue color
			 avg = (b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8)/8 ;  //taking the average from all the blue pixels of the image 
			 var = (b1*b1 + b2*b2 + b3*b3 + b4*b4 + b5*b5 + b6*b6 + b7*b7 + b8*b8)/8; // finding varience of blue color of surrounding pixes
             var = var - avg*avg; // sigma^2 = summation(x^2)/n - average*average
             var = sqrt(var);   // Standard deviation = sqrt(sigma^2) = sqrt(summation(x^2)/n - average*average);
             roi.at<cv::Vec3b>(i,j)[0] = var;
             
             // for green color 
             avg = (g1 + g2 + g3 + g4 + g5 + g6 + g7 + g8)/8 ;
			 var = (g1*g1 + g2*g2 + g3*g3 + g4*g4 + g5*g5 + g6*g6 + g7*g7 + g8*g8)/8;
             var = var - avg*avg;
             var = sqrt(var);
             roi.at<cv::Vec3b>(i,j)[1] = var;
             
             // for red color
             avg = (r1 + r2 + r3 + r4 + r5 + r6 + r7 + r8)/8 ;
			 var = (r1*r1 + r2*r2 + r3*r3 + r4*r4 + r5*r5 + r6*r6 + r7*r7 + r8*r8)/8;
             var = var - avg*avg;
             var = sqrt(var);
             roi.at<cv::Vec3b>(i,j)[2] = var;
             
             //cout << var << " hi ";
         }
     }
	
	return roi;  // return newly generated image
}

Mat imfill(Mat image, string s){
	Mat roi(image);
	int b,g,r,avg; // initialising for blue, green , red and average
	if(s == "gray"){
		// visiting every pixel
	for(int i = 0; i < roi.rows; i++)
{
    for(int j = 0; j < roi.cols; j++)
    {
		// extracting the colors in a pixel
        b = roi.at<cv::Vec3b>(i,j)[0];
        g = roi.at<cv::Vec3b>(i,j)[1];
        r = roi.at<cv::Vec3b>(i,j)[2];
        // finding the average of colors
        avg = b + g + r;
        avg = avg/3;
        //cout << b << " ";
        // giving the pixels this average value
        roi.at<cv::Vec3b>(i,j)[0] = avg;
        roi.at<cv::Vec3b>(i,j)[1] = avg;
        roi.at<cv::Vec3b>(i,j)[2] = avg;
    }
}
}else if(s == "white"){
	for(int i = 0; i < roi.rows; i++)
{
    for(int j = 0; j < roi.cols; j++)
    {
        roi.at<cv::Vec3b>(i,j)[0] = 255;
        roi.at<cv::Vec3b>(i,j)[1] = 255;
        roi.at<cv::Vec3b>(i,j)[2] = 255;
    }
}
}else if(s == "black"){
   for(int i = 0; i < roi.rows; i++)
{
    for(int j = 0; j < roi.cols; j++)
    {
        roi.at<cv::Vec3b>(i,j)[0] = 0;
        roi.at<cv::Vec3b>(i,j)[1] = 0;
        roi.at<cv::Vec3b>(i,j)[2] = 0;
    }
}	
}
	
	return roi;  // return the newly generated image
}

int main( int argc, char** argv )
{
    if( argc != 2)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], IMREAD_COLOR); // Read the file

    if( image.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    
    //Mat image2 = imfill(image,"gray");
    Mat image3 = stdfilt(image);   // The function takes standard deviation from the surrounding pixels and then returns the image array.
    Mat image2 = imfill(image, "gray"); // function defined to get that color in the image. Only gray, white, back are supportred right now.
    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display window", image3 );                 // Show our image inside it.
    //cout << image3 << '\n';
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}
