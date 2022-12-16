// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        int cnt[n][120];
        memset(cnt, 0, sizeof(cnt));

        for(int i=0;i<n;i++){
            for(int j=0;j<garbage[i].size();j++)
                cnt[i][garbage[i][j]]++;
        }
        int ans=0;
        for(auto &tar:"MPG"){
            int last_time=0;
            for(int i=0;i<garbage.size();i++){
                if(i) last_time+=travel[i-1];
                if(cnt[i][tar]!=0){
                   ans+=last_time+cnt[i][tar];
                   last_time=0;
                }
            }
        }
        return ans;
    }
};
