#Assessment Interpolation: Using any language and plotting packages you like,
# interpolate the given point location values to a structured grid of longitude and latitude locations.
# This task will ask the candidate to implement a procedure that interpolates known grid points and values to a structured grid

import math
import os
import numpy as np
import plotly.graph_objects as go
f = open("data2.dat", "w")
x= [121.39,126.19,130.27,127.42,126.14,125.96,123.15,130.5,129.08,122.74]
y=[13.51,12.02,13.11,10.09,15.33,14,10.88,11.18,15.78,15.82]
z=[1.494,1.934,2.148,9.155,2.221,8.1,2.039,1.916,3.729,7.137]

def distance(x1, y1, x2, y2):
    return math.sqrt((x1-x2)**2 + (y1 -y2)**2)

def idw_npoint(xz, yz, n_point, p):
    r = 1  # block radius iteration distance
    nf = 0
    while nf < n_point:  # will stop when np reaching at least n_point
        x_block = []
        y_block = []
        z_block = []
        r += 1  # add 10 unit each iteration
        xr_min = xz - r
        xr_max = xz + r
        yr_min = yz - r
        yr_max = yz + r

        for i in range(len(x)):
            # condition to test if a point is within the block
            if ((x[i] >= xr_min and x[i] <= xr_max) and (y[i] >= yr_min and y[i] <= yr_max)):
                x_block.append(x[i])
                y_block.append(y[i])
                z_block.append(z[i])
        nf = len(x_block)  # calculate number of point in the block


    # calculate weight based on distance and p value
    w_list = []
    for j in range(len(x_block)):
        d = distance(xz, yz, x_block[j], y_block[j])
        if d > 0:
            w = 1 / (d ** p)
            w_list.append(w)
            z0 = 0
        else:
            w_list.append(0)  # if meet this condition, it means d<=0, weight is set to 0

    # check if there is 0 in weight list
    w_check = 0 in w_list
    if w_check == True:
        idx = w_list.index(0)  # find index for weight=0
        z_idw = z_block[idx]  # set the value to the current sample value
    else:
        wt = np.transpose(w_list)
        z_idw = np.dot(z_block, wt) / sum(w_list)  # idw calculation using dot product
    return z_idw

nx=70 #number of interpolation point for x and y axis
ny=50
x_min=121.0
x_max=131.0
y_min=10.0
y_max=16.0
w=x_max-x_min #width
h=y_max-y_min #length
wn=w/nx #x interval
hn=h/ny #y interval

#list to store interpolation point and elevation
y_init=y_min
x_init=x_min
x_idw_list=[]
y_idw_list=[]
z_head=[]

for i in range(nx):
    xz = x_init + wn * i
    x_idw_list.append(xz)
for i in range(ny):
    yz = y_init + hn * i
    y_idw_list.append(yz)
for i in range(nx):
    z_idw_list=[]
    for j in range(ny):
        xz=x_init+wn*j
        z_idw=idw_npoint(x_init + wn * i,y_init + hn * j,10,1.5) #min. point=10, p=1.5
        f.write(str(x_init + wn * i)+'   '+str(y_init + hn * j)+'   '+str(z_idw)+'\n')
        z_idw_list.append(z_idw)
    z_head.append(z_idw_list)

f.close()