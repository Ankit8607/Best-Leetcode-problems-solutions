// https://leetcode.com/problems/power-of-four/?envType=daily-question&envId=2023-10-23

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return 0;
        int cnt=0;
        while(n%2==0){
            n/=2;
            cnt++;
        }
        if(n>1 || cnt%2) return 0;
        return 1;
    }
};
