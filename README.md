# opencv_imageProcessing
This assignment declares two matlab functions namely-
1. stdfilt
2. imfill
These functions are defined and used on images.

For this project to work:
1. Install all the dependencies and then install opencv. Installing from this source is a lot easier -
  http://rodrigoberriel.com/2014/10/installing-opencv-3-0-0-on-ubuntu-14-04/
2. After installation make a new project and make the DisplayImage.cpp file and then use the code in this repositories file.
3. Make a CMakeLists.txt file and paste the fillowing lines in it-
  cmake_minimum_required(VERSION 2.8)
  project( DisplayImage )
  find_package( OpenCV REQUIRED )
  add_executable( DisplayImage DisplayImage.cpp )
  target_link_libraries( DisplayImage ${OpenCV_LIBS} )

4. After that to run the code go in the directory via the shell and write
   $ cmake .
   $ make
5. A executable of name DisplayImage will be generated.
6. Run it as:
   $ ./DisplayImage lena.jpg   // The executable requires a photo as an argument so it have to be passed
7. The functions are already defined in the .cpp file. They can be used as:
   Mat image2 = imfill(image , "gray");
   and
   Mat image3 = stdfilt(image);
   The images obtained can then be displayed.
   
      
