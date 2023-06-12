// https://leetcode.com/problems/summary-ranges/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int i=0,n=nums.size();
        while(i<n){
            int cnt=0,start=i;
            while(i+1<n and nums[i+1]-1==nums[i]){
                i++;
                cnt++;
            }
            string s;
            if(cnt){
                s=to_string(nums[start]);
                s+="->";
                s+=to_string(nums[i]);
            }
            else s=to_string(nums[i]);
            ans.push_back(s);
            i++;
        }   
        return ans;
    }
};
