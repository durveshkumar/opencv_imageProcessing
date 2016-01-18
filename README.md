# opencv_imageProcessing

I.   This assignment declares two matlab functions namely-<br /><br />
1. stdfilt <br />
2. imfill<br />
   These functions are defined and used on images.<br /><br />

   For this project to work:<br />
1. Install all the dependencies and then install opencv. Installing from this source is a lot easier -<br />
   http://rodrigoberriel.com/2014/10/installing-opencv-3-0-0-on-ubuntu-14-04/  <br />
2. After installation make a new project and make the DisplayImage.cpp file and then use the code in this repositories    
   file.<br />
3. Make a CMakeLists.txt file and paste the fillowing lines in it- <br />
   cmake_minimum_required(VERSION 2.8) <br />
   project( DisplayImage) <br />
   find_package( OpenCV REQUIRED ) <br />
   add_executable( DisplayImage DisplayImage.cpp ) <br />
   target_link_libraries( DisplayImage ${OpenCV_LIBS} ) <br />
4. After that to run the code go in the directory via the shell and write <br />
   $ cmake .  <br />
   $ make  <br />
5. A executable of name DisplayImage will be generated. <br />
6. Run it as: <br />
   $ ./DisplayImage lena.jpg   // The executable requires a photo as an argument so it have to be passed <br />
7. The functions are already defined in the .cpp file. They can be used as: <br />
   Mat image2 = imfill(image , "gray");<br />
   and <br />
   Mat image3 = stdfilt(image); <br />
   The images obtained can then be displayed.
   
      
