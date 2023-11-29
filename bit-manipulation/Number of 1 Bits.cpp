// https://leetcode.com/problems/number-of-1-bits/description/?envType=daily-question&envId=2023-11-29

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n){
            if(n%2) ans++;
            n=(n>>1);
        }
        return ans;
    }
};
