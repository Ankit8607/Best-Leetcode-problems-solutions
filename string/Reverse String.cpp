// https://leetcode.com/problems/reverse-string/description/?envType=daily-question&envId=2024-06-02

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};


// In python

// class Solution:
//     def reverseString(self, s: List[str]) -> None:
//         """
//         Do not return anything, modify s in-place instead.
//         """
//         s.reverse()


// In javascript

// /**
//  * @param {character[]} s
//  * @return {void} Do not return anything, modify s in-place instead.
//  */
// var reverseString = function(s) {
//     s.reverse()
// };
