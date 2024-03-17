// https://leetcode.com/problems/insert-interval/description/?envType=daily-question&envId=2024-03-17

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int flag=0;
        for(auto i:intervals){
            if(flag==0 and i[0]>newInterval[1]) ans.push_back(newInterval),flag=1;
            if(i[0]>newInterval[1] || i[1]<newInterval[0]) ans.push_back({i[0],i[1]});
            else newInterval={min(i[0],newInterval[0]),max(i[1],newInterval[1])};
        }
        if(flag==0) ans.push_back(newInterval);
        return ans;
    }
};


// In Python

// class Solution:
//     def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
//         ans = []
//         flag=0
//         for i in intervals:
//             if flag==0 and i[0]>newInterval[1]:
//                 ans.append(newInterval)
//                 flag=1
//             if i[0]>newInterval[1] or i[1]<newInterval[0]:
//                 ans.append([i[0],i[1]])
//             else:
//                 newInterval=[min(i[0],newInterval[0]),max(i[1],newInterval[1])]

//         if flag==0:
//             ans.append(newInterval)
//         return ans


// In javascript

// /**
//  * @param {number[][]} intervals
//  * @param {number[]} newInterval
//  * @return {number[][]}
//  */
// var insert = function(intervals, newInterval) {
//     let ans=[];
//     let flag=0;
//     intervals.forEach((i) => {
//         if(flag==0 && i[0]>newInterval[1]) ans.push(newInterval),flag=1;
//         if(i[0]>newInterval[1] || i[1]<newInterval[0]) ans.push([i[0],i[1]]);
//         else newInterval=[Math.min(i[0],newInterval[0]),Math.max(i[1],newInterval[1])];
//     });
//     if(flag==0) ans.push(newInterval);
//     return ans;
// };
