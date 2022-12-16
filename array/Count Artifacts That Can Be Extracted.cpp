// https://leetcode.com/problems/count-artifacts-that-can-be-extracted/description/

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int arr[n][n];
        memset(arr,0,sizeof(arr));
        for(auto &i:dig){
            arr[i[0]][i[1]]=1;
        }
        int ans=0;
        for(auto &k:artifacts){
            int x1=k[0],y1=k[1],x2=k[2],y2=k[3];
            int flag=1;
            for(int i=x1;i<=x2;i++){
                for(int j=y1;j<=y2;j++){
                    if(!arr[i][j]){
                        flag=0;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag) ans++;
        }
        return ans;
    }
};
