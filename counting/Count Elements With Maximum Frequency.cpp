// https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2024-03-08

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int arr[101]={0};
        for(auto i:nums) arr[i]++;
        int mx=0,cnt=0;
        for(auto i:arr){
            if(i>mx) mx=i,cnt=i;
            else if(i==mx) cnt+=i;
        }
        return cnt;
    }
};
