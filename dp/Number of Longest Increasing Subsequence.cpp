// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> len(n,1), cnt(n,1);
        int ans=1,mxlen=1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    if(len[j]+1>len[i]){
                        len[i]=len[j]+1;
                        cnt[i]=cnt[j];
                    }
                    else if(len[j]+1==len[i]){
                        cnt[i]+=cnt[j];
                    }
                }
            }
            // cout<<"len[i]= "<<len[i]<<" cnt[i]= "<<cnt[i]<<endl;
            if(len[i]>mxlen){
                ans=cnt[i];
                mxlen=len[i];
            }
            else if(len[i]==mxlen) ans+=cnt[i];
        }
        return ans;
    }
};
