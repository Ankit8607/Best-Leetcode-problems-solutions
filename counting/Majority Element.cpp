// https://leetcode.com/problems/majority-element/description/?envType=daily-question&envId=2024-02-12

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=-1,cnt=1;
        for(auto i:nums){
            if(ans==-1) ans=i;
            else if(i==ans) cnt++;
            else{
                cnt--;
                if(cnt==0) ans=i,cnt=1;
            }
        }
        return ans;
    }
};
