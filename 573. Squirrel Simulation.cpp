/*
There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid. Your goal is to find the minimal distance for the squirrel to collect all the nuts and put them under the tree one by one. The squirrel can only take at most one nut at one time and can move in four directions - up, down, left and right, to the adjacent cell. The distance is represented by the number of moves.

Example 1:
Input: 
Height : 5
Width : 7
Tree position : [2,2]
Squirrel : [4,4]
Nuts : [[3,0], [2,5]]
Output: 12
Explanation:

*/

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int dis = 0;
        int m = INT_MAX;
        int sum = 0;
        vector<int> d(nuts.size(),0);
        vector<int> dk(nuts.size(),0);
        for(int i=0;i<nuts.size();i++){
            sum+= (abs(tree[0] - nuts[i][0]) + abs(tree[1] - nuts[i][1]))*2;
            d[i]=abs(tree[0] - nuts[i][0]) + abs(tree[1] - nuts[i][1]);
            dk[i]=abs(squirrel[0] - nuts[i][0]) + abs(squirrel[1] - nuts[i][1]);
        }
        for(int i=0;i<nuts.size();i++){
            m = min(sum-d[i]+dk[i],m);
        }
        return m;
    }

};