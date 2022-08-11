// https://leetcode.com/problems/equal-row-and-column-pairs/

/*

Given a 0-indexed n x n integer matrix grid, return the number of pairs (Ri, Cj) such that row Ri and column Cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e. an equal array).

 

Example 1:


Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
Example 2:


Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
1 <= grid[i][j] <= 105

*/


class Solution {
public:
    class node{
        public:
        int cnt=0;
        // node *child[100010];
        unordered_map<int,node*>mp;
        node(){
            cnt=0;
            // for(int i=0;i<100010;i++) child[i]=NULL;
        }
    };
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        node *root=new node();
        for(int i=0;i<n;i++){
            node *cur=root;
            for(int j=0;j<n;j++){
                int x=grid[j][i];
                if(cur->mp[x]==NULL) cur->mp[x]=new node();
                cur=cur->mp[x];
            }
            cur->cnt++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            node *cur=root;
            for(int j=0;j<n;j++){
                int x=grid[i][j];
                if(cur->mp[x]) cur=cur->mp[x];
                else continue;
            }
            ans+=cur->cnt;
        }
        return ans;
    }
};
