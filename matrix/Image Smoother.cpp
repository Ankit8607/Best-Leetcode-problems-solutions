// https://leetcode.com/problems/image-smoother/description/?envType=daily-question&envId=2023-12-19

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size(),m=img[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        int dx[]={0,0,-1,-1,-1,1,1,1};
        int dy[]={1,-1,1,0,-1,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=img[i][j],cnt=1;
                for(int k=0;k<8;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(x>=0 and y>=0 and x<n and y<m) cnt++,sum+=img[x][y];
                }
                ans[i][j]=sum/cnt;
            }
        }
        return ans;
    }
};
