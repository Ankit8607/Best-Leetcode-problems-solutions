// https://leetcode.com/problems/largest-local-values-in-a-matrix/description/?envType=daily-question&envId=2024-05-12

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        vector<vector<int>>ans(n-2,vector<int>(m-2));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                int mx = 0;
                for (int k = i; k < i + 3; ++k) 
                    for (int l = j; l < j + 3; ++l)
                        mx = max(mx, g[k][l]);
                ans[i][j]=mx;
            }
        }
        return ans;
    }
};


// In python

// class Solution:
//     def largestLocal(self, g: List[List[int]]) -> List[List[int]]:
//         n=len(g)
//         ans=[[0 for i in range(n-2)] for i in range(n-2)]
//         for i in range(n-2):
//             for j in range(n-2):
//                 mx = 0
//                 for k in range(i,i+3,1):
//                     for l in range(j,j+3,1):
//                         mx = max(mx, g[k][l])
//                 ans[i][j]=mx
//         return ans


// In javascript

// /**
//  * @param {number[][]} grid
//  * @return {number[][]}
//  */
// var largestLocal = function(g) {
//     let n=g.length;
//     let ans=[];
//     for(let i=0;i<n-2;i++){
//         let tmp=[];
//         for(let j=0;j<n-2;j++){
//             let mx = 0;
//             for (let k = i; k < i + 3; ++k) 
//                 for (let l = j; l < j + 3; ++l)
//                     mx = Math.max(mx, g[k][l]);
//             tmp.push(mx);
//         }
//         ans.push(tmp);
//     }
//     return ans;
// };
