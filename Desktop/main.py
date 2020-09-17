#Additional import libraries
import pandas
import numpy as np
import open3d
import math


data_set = pandas.read_excel('dataset.xlsx') #dataset
f = open("data.xyz","w") 

# Changing to xyz coordinates with the raw data
for i in range(1,21):  
    x = data_set [data_set.columns[i]].iloc[0]
    for j in range(1,513): 
        data = data_set[data_set.columns[i]].iloc[j] 
        angle = (2*math.pi)/512*data_set[data_set.columns[0]].iloc[j] 
        y = data*math.sin(angle)/1000 
        if (angle>=0 and angle<=(math.pi/2)or(angle>=((math.pi*3)/2) and angle<=(2*math.pi))):
            z = -abs(data*math.cos(angle))/1000
        else:
            z = abs(data*math.cos(angle))/1000
        f.write(f"{x} {y} {z}\n") 
f.close() 

#Create the point cloud
pcd = open3d.io.read_point_cloud("demofile2dx4.xyz", format = 'xyz') 

#creating the list
lines = []

# Connecting all point on the same x coordinates
for col in range(19): 
    for row in range(512):
        if row==511:
            lines.append([row+col*512,col*512])
        else:
            lines.append([row+col*512,1+row+col*512])

# Connecting points along different x coordinates
for col in range(19): 
    for row in range(512):
        lines.append([row+col*512,row+col*512+512])

#Visualization          
line_set = open3d.geometry.LineSet(points=open3d.utility.Vector3dVector(np.asarray(pcd.points)), lines = open3d.utility.Vector2iVector(lines))
open3d.visualization.draw_geometries([line_set])
    
