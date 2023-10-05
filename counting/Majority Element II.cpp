// https://leetcode.com/problems/majority-element-ii/description/?envType=daily-question&envId=2023-10-05

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int inf=1e9+7,n=nums.size();
        int a=inf,b=inf, cnta=0,cntb=0;
        for(auto i:nums){
            if(i==a) cnta++;
            else if(i==b) cntb++;
            else if(cnta==0) a=i,cnta=1;
            else if(cntb==0) b=i,cntb=1;
            else cnta--,cntb--;
        }
        cnta=0; cntb=0;
        for(auto i:nums) if(i==a) cnta++;
        for(auto i:nums) if(i==b) cntb++;
        vector<int>ans;
        if(cnta>n/3) ans.push_back(a);
        if(cntb>n/3) ans.push_back(b);
        return ans;
    }
};
