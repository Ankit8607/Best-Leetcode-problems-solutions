// https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/

class Solution {
public:
    int maxConsecutive(int l, int r, vector<int>& special) {
        sort(special.begin(),special.end());
        int ans=special[0]-l;
        for(int i=1;i<special.size();i++){
            ans=max(ans,special[i]-special[i-1]-1);
        }
        ans=max(ans,r-special[special.size()-1]);
        return ans;
    }
};
