# README #

[![Ocean Waves](http://img.youtube.com/vi/0LwcttYFld8/0.jpg)](https://www.youtube.com/watch?v=0LwcttYFld8 "Ocean Waves")

The code in this repository implements the ocean wave algorithm from Jerry Tessendorf using Qt, OpenGL 3.3 and FFTW. To run the application, an OpenGL 3.3 capable graphics card is needed.
Further the following packages need to be installed:

  * Qt (>=4.5)
  * OpenGL (>=3.3)
  * GLM 
  * FFTW (>=3.0)
  
The repository is build by issuing qmake inside of the root of the repository followed by a make. Make sure the Shaders directory is in the same directory as the executable to get a rendering.
To move in the scene, the WASD keys are used. To rotate the camera, the arrow keys are used. Clicking on the compass widget and applying the changes, changes the wind direction. Have fun and play
with the options given by the GUI. 

A video of the application can be found at https://www.youtube.com/watch?v=0LwcttYFld8&feature=youtu.be
