// https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int t=1,dir=0;
        int right=n-1,left=0,up=0,down=n-1;
        vector<vector<int>> ans(n,vector<int>(n));
        while(t<=n*n){
            if(dir==0){
                for(int i=left;i<=right;i++)
                    ans[up][i]=t++;
                dir=1;
                up++;
            }
            else if(dir==1){
                for(int i=up;i<=down;i++)
                    ans[i][right]=t++;
                dir=2;
                right--;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--)
                    ans[down][i]=t++;
                dir=3;
                down--;
            }
            else {
                for(int i=down;i>=up;i--)
                    ans[i][left]=t++;
                dir=0;
                left++;
            }
        }
        return ans;
    }
};
