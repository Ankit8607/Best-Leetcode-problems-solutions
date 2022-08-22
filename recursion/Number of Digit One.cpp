// https://leetcode.com/problems/number-of-digit-one/

/*

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

 

Example 1:

Input: n = 13
Output: 6
Example 2:

Input: n = 0
Output: 0
 

Constraints:

0 <= n <= 109

*/


 class Solution {
    public:
        int countDigitOne(int n) {
            if (n <= 0)
                return 0;
            
            long long count = 0;    //It may cause integer overflow
            
            long long factor = 1;
            
            while (n / factor) {
                int lowerNum = n - (n / factor) * factor;
                int currentDigit = (n / factor) % 10;
                int higherDigit = n / (factor * 10);
                
                switch(currentDigit) {
                    case 0:
                        count += higherDigit * factor;
                        break;
                    case 1:
                        count += higherDigit * factor + (lowerNum + 1);
                        break;
                    default:
                        count += (higherDigit + 1) * factor;
                }
                
                factor *= 10;
            }
            
            return count;
        }
    };
