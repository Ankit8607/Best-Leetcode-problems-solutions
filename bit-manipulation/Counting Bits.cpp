//  https://leetcode.com/problems/counting-bits/?envType=daily-question&envId=2023-09-01

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        ans.push_back(0);
        int t=0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0) t=0;
            ans.push_back(1+ans[t++]);
        }
        return ans;
    }
};
