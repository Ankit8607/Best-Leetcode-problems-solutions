// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

/*

There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

 

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2 
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
 

Constraints:

1 <= points.length <= 105
points[i].length == 2
-231 <= xstart < xend <= 231 - 1

*/


class Solution {
public:

    static bool comp(vector<int>&a,vector<int>&b){
        if(a[1]<b[1]) return a[1]<b[1];
        return 0; 
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),comp);
        int ans=0;
        int last=-1;
        int i=0;
        while(i<points.size()) {
            ans++;
            last=points[i++][1];
            while(i<points.size() and last>=points[i][0]){
                i++;
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     int findMinArrowShots(vector<vector<int>>& points) {
//         int last=INT_MIN,ans=0;
//         sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b){
//             return a[1]<b[1];
//         });
//         for(auto i:points)
//             if(i[0]>last || (i[0]==INT_MIN and ans==0)) last=i[1],ans++;
//         return ans;
//     }
// };


// In Python

// class Solution:
//     def findMinArrowShots(self, points: List[List[int]]) -> int:
//         last=float('-inf')
//         ans=0
//         p=sorted(points,key=lambda x: x[1])
//         for i in p:
//             if i[0]>last: 
//                 last=i[1]
//                 ans+=1
//         return ans



 
// In javascript

// /**
//  * @param {number[][]} points
//  * @return {number}
//  */
// var findMinArrowShots = function(points) {
//     let last=Number.MIN_SAFE_INTEGER,ans=0;
//     points.sort(comp);
//     function comp(a,b){
//         return (a[1]<b[1])?-1:1;
//     }
//     points.forEach((i) => {
//         if(i[0]>last) last=i[1],ans++;
//     });
//     return ans;
// };
