// https://leetcode.com/problems/minimum-sum-of-squared-difference/

class Solution {
public:

    pair<int,long long> check(int mid,long long k,vector<int>& v){
        for(int i=0;i<v.size();i++){
            if(v[i]>mid) k-=(v[i]-mid);
        }
        return {k>=0,k};
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int>v;
        int n=nums1.size();
        for(int i=0;i<nums1.size();i++) v.push_back(abs(nums1[i] - nums2[i]));
        sort(v.begin(),v.end());
        k1+=k2;
        int l=0,r=v[n-1],ans=0;
        long long k;
        while(l<=r){
            int mid=(l+r)/2;
            pair<int,long long> p=check(mid,k1,v);
            if(p.first){
                ans=mid;
                r=mid-1;
                k=p.second;
            }
            else l=mid+1;
        }
        if(ans==0) return 0;
        for(int i=0;i<n;i++){
            if(v[i]>ans) v[i]=ans;
        }
        int i=n-1;
        while(k--) v[i--]--;
        long long res=0;
        for(auto &i:v) res+=1LL*i*i;
        return res;
    }
};
