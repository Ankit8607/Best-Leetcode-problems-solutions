// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

/*

Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1], k = 1
Output: 1
Example 2:

Input: nums = [1,2], k = 4
Output: -1
Example 3:

Input: nums = [2,-1,2], k = 3
Output: 3
 

Constraints:

1 <= nums.length <= 105
-105 <= nums[i] <= 105
1 <= k <= 109

*/


#define ll long long
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        ll pre[n+1];
        pre[0]=0;
        for(int i=0;i<n;i++) pre[i+1]=pre[i]+nums[i];
        int ans=1e9;
        dq.push_back(0);
        for(int i=1;i<=n;i++){
            while(!dq.empty() and pre[i]-pre[dq.front()]>=k){
                ans=min(ans,i-dq.front());
                dq.pop_front();
            }
            if(!dq.empty() and pre[dq.front()]>=pre[i]){
                dq.clear();
            }
            while(!dq.empty() and pre[dq.back()]>=pre[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        while(dq.size()>1){
            if(pre[n]-pre[dq.front()]>=k) ans=min(ans,n-dq.front());
            dq.pop_front();
        }
        return (ans==1e9?-1:ans);
    }
};
