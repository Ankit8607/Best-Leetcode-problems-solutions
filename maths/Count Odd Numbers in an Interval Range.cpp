// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

class Solution {
public:
    int countOdds(int low, int high) {
        return (high-low+1)/2+((high-low+1)%2?(low%2):0);
    }
};
