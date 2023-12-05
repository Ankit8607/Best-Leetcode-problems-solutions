// https://leetcode.com/problems/count-of-matches-in-tournament/description/?envType=daily-question&envId=2023-12-05 

class Solution {
public:
    int numberOfMatches(int n) {
        if(n<=2) return n-1;
        return n/2+numberOfMatches(n/2+n%2); 
    }
};
