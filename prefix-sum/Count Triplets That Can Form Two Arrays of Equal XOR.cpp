// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/?envType=daily-question&envId=2024-05-30

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size(),t=0;
        vector<int>x(n,0);
        for(int i=0;i<n;i++){
            t^=arr[i];
            x[i]=t;
        }
        int ans=0;
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                t=x[j-1]^(i==0?0:x[i-1]);
                for(int k=j;k<n;k++){
                    if(t==(x[k]^x[j-1]))
                        ans++;
                }
            }
        }
        return ans;
    }
};


// In python

// class Solution:
//     def countTriplets(self, arr: List[int]) -> int:
//         n=len(arr)
//         t=0
//         x=[0 for _ in range(n)]
//         for i in range(n):
//             t^=arr[i]
//             x[i]=t
//         ans=0
//         for j in range(n):
//             for i in range(j):
//                 t=x[j-1]^(0 if i==0 else x[i-1])
//                 for k in range(j,n,1):
//                     if t==(x[k]^x[j-1]):
//                         ans+=1
//         return ans


// In javascript

// /**
//  * @param {number[]} arr
//  * @return {number}
//  */
// var countTriplets = function(arr) {
//     let n=arr.length,t=0;
//     let x=[];
//     for(let i=0;i<n;i++){
//         t^=arr[i];
//         x[i]=t;
//     }
//     let ans=0;
//     for(let j=1;j<n;j++){
//         for(let i=0;i<j;i++){
//             t=x[j-1]^(i==0?0:x[i-1]);
//             for(let k=j;k<n;k++){
//                 if(t==(x[k]^x[j-1]))
//                     ans++;
//             }
//         }
//     }
//     return ans;
// };
