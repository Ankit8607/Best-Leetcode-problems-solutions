// https://leetcode.com/problems/trapping-rain-water/

/*
 
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 
 
Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

*/


class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int arr[n];
        arr[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            arr[i]=max(height[i],arr[i+1]);
        }
        int ans=0;
        int mx=height[0];
        for(int i=1;i<n-1;i++){
            ans+=max(0,min(mx,arr[i])-height[i]);
            mx=max(mx,height[i]);
            // cout<<ans<<" ";
        }
        return ans;
    }
};
