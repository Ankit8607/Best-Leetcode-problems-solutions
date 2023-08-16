// https://leetcode.com/problems/sliding-window-maximum/description/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            while(!q.empty() and q.front()<nums[i]) q.pop_front();
            q.push_front(nums[i]);
            if(i>=k-1){
                ans.push_back(q.back());
                if(nums[i-k+1]==q.back()) q.pop_back();
            }
        }
        return ans;
    }
};
