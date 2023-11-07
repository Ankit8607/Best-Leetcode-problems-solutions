// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/?envType=daily-question&envId=2023-11-07

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        for(int i=0;i<dist.size();i++) dist[i]=(dist[i]+speed[i]-1)/speed[i];
        sort(dist.begin(),dist.end());
        int cnt=1;
        for(int i=1;i<dist.size();i++){
            if(dist[i]<=i) break;
            cnt++;
        }
        return cnt;
    }
};
