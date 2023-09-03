// https://leetcode.com/problems/unique-paths/?envType=daily-question&envId=2023-09-03

class Solution {
public:
    int uniquePaths(int m, int n) {
        double res = 1;
        for (int i=1; i<min(n,m); ++i)
            res = res * (n+m-i-1) / i;
        return (int)res;
    }
};
