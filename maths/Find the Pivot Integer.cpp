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


// In python

// class Solution:
//     def pivotInteger(self, n: int) -> int:
//         sum = n*(n+1)/2
//         x=int(math.sqrt(sum))
//         if x*x == sum:
//             return int(x)
//         return -1


// In javascript

// /**
//  * @param {number} n
//  * @return {number}
//  */
// var pivotInteger = function(n) {
//     let sum = n*(n+1)/2;
//     let x = parseInt(Math.sqrt(sum))
//     console.log(x);
//     if(x*x==sum)
//         return x;
//     return -1;
// };
