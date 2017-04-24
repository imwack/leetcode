/*

Input: 

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

Output: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]


Input: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Click : [1,2]

Output: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]
*/    
    int hasM(vector<vector<char>>& board,int x,int y,int r,int c){
        int cnt=0;
        
        if(y-1>=0 && boadr[x][y-1]=='M') cnt++;
        if(y+1<c  && boadr[x][y+1]=='M') cnt++;

        if(x-1>=0 && y-1>=0 && boadr[x-1][y-1]=='M') cnt++;
        if(x-1>=0 && boadr[x-1][y]=='M') cnt++;
        if(x-1>=0 && y+1<c && boadr[x-1][y+1]=='M') cnt++;
        
        if(x+1<r && boadr[x+1][y]=='M') cnt++;
        if(x+1<r && y-1>=0 && boadr[x+1][y-1]=='M') cnt++;
        if(x+1<r && y+1<c && boadr[x+1][y+1]=='M') cnt++;
        return cnt;
    }
    void dfs(vector<vector<char>>& board,int x,int y,int r,int c){
        int cnt = hasM(board,x,y,r,c);
        if(cnt){ board[x][y]=cnt+'0'; return ;}
        else{
            board[x][y] = 'B';
            dfs(board)
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x=click[0],y=click[1];
        int row=board.size(),col=board[0].size();
        if(board[x][y]=='M') board[x][y]='X';
        else dfs(board,x,y,row,col);
        return board;
    }