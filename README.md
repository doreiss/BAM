# BAM

To build: Download repo and open BAM_Solution/BAM_Solution.sln in Visual Studio (2017). Start up project ppmtest to create image similar to:
![alt text](https://raw.githubusercontent.com/doreiss/BAM/master/BAM_Solution/ppmtest/random_scene_4kx2k.png)

Plans for this project: 

Want to create a built-from-ground-up physics engine and raytracer for simple 3D objects to help myself better understand the simulation side of animation pipeline. 

So far:
  - Some barebones math classes for vector algebra. 
  - Some barebones ray tracing built following tutorial by Philip Shirley (http://in1weekend.blogspot.com/2016/01/ray-tracing-in-one-weekend.html). 
  - Started basic physics engine following Millington. 
  - Added some very basic interface between physics and graphics.

Next up: 
  - Implement triangular mesh scattering so can view more complex objects than spheres.
  - Implement directional and object lights. 
  - Implement collision detection and correction. 
  
