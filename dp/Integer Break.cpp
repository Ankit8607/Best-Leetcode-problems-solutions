// https://leetcode.com/problems/integer-break/

/*

Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

 

Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 

Constraints:

2 <= n <= 58

*/

// DP solution
class Solution {
public:
    int integerBreak(int n) {
        
        if (n <= 2)
            return 1;

        vector<int> maxArr(n+1, 0);
                    
        /** For a number i: write i as a sum of integers, then take the product of those integers.
        maxArr[i] = maximum of all the possible products */
        
        maxArr[1] = 0;
        maxArr[2] = 1; // 2=1+1 so maxArr[2] = 1*1
        
        for (int i=3; i<=n; i++) {
            for (int j=1; j<i; j++) {
                /** Try to write i as: i = j + S where S=i-j corresponds to either one number or a sum of two or more numbers
                
                Assuming that j+S corresponds to the optimal solution for maxArr[i], we have two cases:
                (1) i is the sum of two numbers, i.e. S=i-j is one number, and so maxArr[i]=j*(i-j)
                (2) i is the sum of at least three numbers, i.e. S=i-j is a sum of at least 2 numbers,
                and so the product of the numbers in this sum for S is maxArr[i-j]
                (=maximum product after breaking up i-j into a sum of at least two integers):
                maxArr[i] = j*maxArr[i-j]
                */
                maxArr[i] = max(maxArr[i], max(j*(i-j), j*maxArr[i-j]));
            }
        }
        return maxArr[n];
    }
};

// O(1) solution

// class Solution {
// public:
//     int integerBreak(int n) {
//         if(n<=3) return n-1;
//         int t=n/3;
//         int rem=n%3;
//         if(rem==0) return pow(3,t);
//         else if(rem==1) return 4*pow(3,t-1);
//         else return 2*pow(3,t);
//     }
// };
