# BAM

To build: Download repo and open BAM_Solution/BAM_Solution.sln in Visual Studio (2017). Start up project ppmtest to create image similar to:
![alt text](https://raw.githubusercontent.com/doreiss/BAM/master/BAM_Solution/ppmtest/outfile.ppm)

Plans for this project: 

Want to create a built-from-ground-up physics engine and raytracer for simple 3D objects to help myself better understand the simulation side of animation pipeline. 

So far:
  - Some barebones math classes for vector algebra. 
  - Some barebones ray tracing built with the help of tutorial by Philip Shirley (http://in1weekend.blogspot.com/2016/01/ray-tracing-in-one-weekend.html). 

Next up: 
  - Implement triangular mesh scattering so can view more complex objects than spheres. 
  - Implement AABB hierarchy.
  - Implement directional and object lights. 
  
  - Implement simple forward or reverse kinematics and constraint equations to simulate first simple physics.
  - Implement motion blur and make simple animations of physics. 
  
