// https://leetcode.com/problems/find-the-pivot-integer/description/?envType=daily-question&envId=2024-03-13

class Solution {
public:
    int pivotInteger(int n) {
        int sum=n*(n+1)/2;
        long long t=sqrt(sum);
        if(t*t==sum) return sqrt(sum);
        return -1;
    }
};
