// https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/

class Solution {
public:
    int dp[5][1001][1025];
    int mod=1e9+7;
    int arr[6]={0,1,2,3,1,2};

    int rec(int i,int j,int mask,int n,int m,int last) {
        if(i==n) i=0,j++,last=mask%4;

        if(j==m) return 1;

        if(dp[i][j][mask]!=-1) return dp[i][j][mask];

        int ans=0;
        if(j==0){
            if(i==0) ans=(rec(i+1,j,3,n,m,3)+rec(i+1,j,1,n,m,1))%mod+rec(i+1,j,2,n,m,2);
            else ans=rec(i+1,j,mask+arr[last+1]*pow(4,i),n,m,arr[last+1])+rec(i+1,j,mask+arr[last+2]*pow(4,i),n,m,arr[last+2]);
        }
        else{
            int adj=mask%4;

            if(last==adj) ans=rec(i+1,j,mask/4+arr[last+1]*pow(4,n-1),n,m,arr[last+1])+rec(i+1,j,mask/4+arr[last+2]*pow(4,n-1),n,m,arr[last+2]);
            else ans=rec(i+1,j,mask/4+(6-last-adj)*pow(4,n-1),n,m,6-last-adj);
        }
        return dp[i][j][mask]=ans%mod;
    }
    int colorTheGrid(int n, int m) {
        memset(dp, -1, sizeof(dp));
        return rec(0,0,0,n,m,-1);
    }
};
