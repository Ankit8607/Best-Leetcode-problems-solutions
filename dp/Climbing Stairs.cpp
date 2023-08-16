// https://leetcode.com/problems/climbing-stairs/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=1;
        n--;
        while(n--){
            int tmp=b;
            b=a+b;
            a=tmp;
        }
        return b;
    }
};
