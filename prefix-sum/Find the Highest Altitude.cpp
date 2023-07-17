// https://leetcode.com/problems/find-the-highest-altitude/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0,last=0;
        for(int i=0;i<gain.size();i++){
            last=gain[i]+last;
            ans=max(ans,last);
        }
        return ans;
    }
};
