// https://leetcode.com/problems/surrounded-regions/description/

class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>&vis,int n,int m){
        vis[i][j]=1;
        if(i+1<n and board[i+1][j]=='O' and !vis[i+1][j]) dfs(i+1,j,board,vis,n,m);
        if(i-1>=0 and board[i-1][j]=='O' and !vis[i-1][j]) dfs(i-1,j,board,vis,n,m);
        if(j+1<m and board[i][j+1]=='O' and !vis[i][j+1]) dfs(i,j+1,board,vis,n,m);
        if(j-1>=0 and board[i][j-1]=='O' and !vis[i][j-1]) dfs(i,j-1,board,vis,n,m);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0] and board[i][0]=='O') dfs(i,0,board,vis,n,m);
            if(!vis[i][m-1] and board[i][m-1]=='O') dfs(i,m-1,board,vis,n,m);
        }
        for(int i=0;i<m;i++){
            if(!vis[0][i] and board[0][i]=='O') dfs(0,i,board,vis,n,m);
            if(!vis[n-1][i] and board[n-1][i]=='O') dfs(n-1,i,board,vis,n,m);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' and !vis[i][j]) board[i][j]='X';
            }
        }
    }
};
