// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        int arr[n];
        for(int i=0;i<n;i++) {
            int j=n-1;
            arr[i]=0;
            while(j>=0 and grid[i][j--]==0) arr[i]++;
        }
        int pre[n];
        memset(pre,0,sizeof(pre));
        int demand=n-1;
        int ans=0;
        for(int i=0;i<n-1;i++){
            int cnt=0;
            int flag=0;
            for(int j=0;j<n;j++){
                if(pre[j]==0) cnt++;
                if(pre[j]==0 and arr[j]>=demand){
                    ans+=cnt-1;
                    pre[j]=1;
                    demand--;
                    flag=1;
                    break;
                }
            }
            if(flag==0) return -1;
        }
        return ans;
    }
};
