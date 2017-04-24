/*
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.size()==0) return ret;
        int row=matrix.size(),col=matrix[0].size();

        int x=0,y=0,d=1;
        for(int i=0;i<row*col;++i){
            ret.push_back(matrix[x][y]);
            x-=d;
            y+=d;
            if(y>=col){y=col-1;x+=2;d=-d;}
            if(x>=row){x=row-1;y+=2;d=-d;}
            if(x<0){x=0; d=-d;}
            if(y<0){y=0; d=-d;}

            
        }
        return ret;
    }
};