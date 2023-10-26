// https://leetcode.com/problems/binary-trees-with-factors/description/?envType=daily-question&envId=2023-10-26

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size(),mod=1e9+7;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp,ans;
        for(auto i:arr) mp[i]=1;
        for(int i=0;i<n;i++){
            ans[arr[i]]=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 and mp.count(arr[i]/arr[j]))
                    ans[arr[i]]+=1LL*ans[arr[i]/arr[j]]*ans[arr[j]]%mod;
                ans[arr[i]]%=mod;
            }
        }
        int res=0;
        for(auto i:ans) res=(res+i.second)%mod;
        return res;
    }
};
