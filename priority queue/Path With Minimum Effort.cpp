// https://leetcode.com/problems/path-with-minimum-effort/

/*

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106

*/


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>>pq;
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        int ans=0;
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int cost=-pq.top().first;
            ans=max(ans,cost);
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==(n-1) and j==(m-1)) return ans;
            vis[i][j]=1;
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 and y>=0 and x<n and y<m and !vis[x][y]){
                    pq.push({-abs(heights[x][y]-heights[i][j]),{x,y}});
                }
            }
        }
        return ans;
    }
};
