// https://leetcode.com/problems/maximum-score-from-removing-stones/

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int mx=max({a,b,c});
        if(2*mx>a+b+c) return a+b+c-mx;
        return (a+b+c)/2;
    }
};
