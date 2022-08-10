// https://leetcode.com/problems/reverse-integer/

/*

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1

*/


class Solution {
public:
    int reverse(int x) {
        int ans=0;
        int is_neg=1;
        if(x<0) is_neg=-1;
        while(x){
            int t=is_neg*(x%10);
            if(is_neg==-1 and (-1*ans)<(INT_MIN+t)/10) return 0;
            else if(ans>(INT_MAX-t)/10) return 0;
            ans*=10;
            ans+=t;
            x/=10;
        }
        return is_neg*ans;
    }
};
