// https://leetcode.com/problems/make-k-subarray-sums-equal/description/


class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        long long ans=0;
        long long n=arr.size();
        long long g=gcd(n,k);
        vector <long long> res;
        for (int i=0;i<g;i++){
            vector<long long> lol;
            for (int j=i;j<n;j+=g) lol.push_back(arr[j]);
            sort(lol.begin(),lol.end());
            res.push_back(lol[lol.size()/2]);
        }
        for (int i=0;i<n;i++) ans+=abs(res[i%g]-arr[i]);
        return ans;
    }
};
