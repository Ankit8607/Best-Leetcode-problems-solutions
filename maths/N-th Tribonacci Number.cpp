// https://leetcode.com/problems/n-th-tribonacci-number/

class Solution {
public:
    int tribonacci(int n) {
        if(n<2) return n;
        if(n==2) return 1;
        int one=0,two=1,three=1;
        for(int i=4;i<=n;i++){ 
            int tmp=three;
            three=one+two+three;
            one=two;
            two=tmp;
        }
        return one + two + three;
    }
};
