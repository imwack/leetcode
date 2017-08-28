/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        int x1=0,y1=0,x2=row-1,y2=col-1; //4 corner
        while(x1<x2&&y1<y2){
            for(int i=0;i<x2-x1;++i){
                int temp = matrix[x1][y1+i];
                matrix[x1][y1+i] = matrix[x2-i][y1];
                matrix[x2-i][y1] = matrix[x2][y2-i];
                matrix[x2][y2-i] = matrix[x1+i][y2];
                matrix[x1+i][y2] = temp;
            }
            x1++;y1++;x2--;y2--;
        }

    }
};