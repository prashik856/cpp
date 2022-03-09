/*
FLOOD FILL ALGORITHM
https://www.geeksforgeeks.org/flood-fill-algorithm-implement-fill-paint/
In MS-Paint, when we take the brush to a pixel and click, the color of the region of that pixel is 
replaced with a new selected color. Following is the problem statement to do this task. 
Given a 2D screen, location of a pixel in the screen and a color, 
replace color of the given pixel and all adjacent same colored pixels with the given color.
*/
/*
Solution Approach:
Given a value of x and y coordinate, and a given colour value n. 
if the colour at x,y is z. Then we first find all the coordinates connect to x,y with same
value as z. We will have to replace all these coordinates to value of n.
*/