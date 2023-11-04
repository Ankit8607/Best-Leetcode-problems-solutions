// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/?envType=daily-question&envId=2023-11-04

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=0;
        for(auto &i: left) ans=max(ans,i);
        for(auto &i:right) ans=max(ans,n-i);
        return ans;
    }
};
