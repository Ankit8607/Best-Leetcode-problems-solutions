// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/

class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(auto &i:n){
            int t=i-'0';
            ans=max(ans,t);
        }
        return ans;
    }
};
