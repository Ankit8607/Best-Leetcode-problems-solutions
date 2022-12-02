// https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>st;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) st.insert(nums[i]);
        }
        int i=1;
        for(auto &it:st){
            if(it!=i) return i;
            i++;
        }
        return i;
    }
};
