// https://leetcode.com/problems/intersection-of-two-arrays/description/?envType=daily-question&envId=2024-03-10

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans,pre(1001,0);
        for(auto i:nums1) pre[i]=1;
        for(auto i:nums2){
            if(pre[i]){
                pre[i]=0;
                ans.push_back(i);
            }
        }
        return ans;
    }
};
