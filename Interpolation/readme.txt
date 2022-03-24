data.dat is the given points.
data2.dat is the interpolated points.

gnu script is runable with gnuplot by "open script file" gnu script with data.dat and data2.dat in the same folder as gnu script.

plot.png is an example plot using gnuplot.  
The green x's are the interpolated points and the large red stars are the given points.

interpolation.py is a python program that can make data2.dat.  The given points are within the code and therefore it does not need data.dat with it.

In interpolation.py I used the interpolation method of Inverse Distance Weighted or IDW.
The Inverse Distance Weighting interpolation assumes that each input point has a local weight that diminishes with distance.
I chose IDW interpolation for a number a reasons, but the main reason was that the number of points given were small only 10 and these 10 points were not close enough together for me to get a clear picture of what exactly the shape was suposed to be generated.  In addision, besides the fact that the x and y corrdinites were longitude  and latitude, the z corrdinites only had value writen for them making me unable to determine exactly what I was expecting that value to be.  Making determining the shape to be even more difficult.  Therefore, I chose IDW interpolation due to the advantage that it can increase or decrease amount of sample points to influence cell values.  From the final shaped formed it seems like a spline could have served just as well, however, do to the small number of points I was unable to determine if more points in the future would or wouldn't indicate cliffs or fault lines and therefore I used the IDW interpolation for safety.
