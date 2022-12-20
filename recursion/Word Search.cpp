// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool dfs(int level,int i,int j,vector<vector<char>>& board, string &word,vector<vector<int>>&vis) {
        if(level==word.size()) return 1;
        vis[i][j]=1;
        int ans=0;
        if(i+1<board.size() and board[i+1][j]==word[level] and !vis[i+1][j]) ans|=dfs(level+1,i+1,j,board,word,vis);
        if(i-1>=0 and board[i-1][j]==word[level] and !vis[i-1][j]) ans|=dfs(level+1,i-1,j,board,word,vis);
        if(j+1<board[0].size() and board[i][j+1]==word[level] and !vis[i][j+1]) ans|=dfs(level+1,i,j+1,board,word,vis);
        if(j-1>=0 and board[i][j-1]==word[level] and !vis[i][j-1]) ans|=dfs(level+1,i,j-1,board,word,vis);
        vis[i][j]=0;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] and dfs(1,i,j,board,word,vis))
                    return 1;
            }
        }
        return 0;
    }
};
