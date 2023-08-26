// https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](vector<int>&a,vector<int>&b){
            if(b[1]==a[1]) return a[0]<b[0];
            return a[1]<b[1];
        });

        set<pair<int,int>>st;
        int mx=1;
        for(auto i: pairs){
            int a=i[0],b=i[1];
            auto it=st.lower_bound({a,-1});
            if(it!=st.begin() and st.size()>0){
                it--;
                mx=max(mx,it->second+1);
            }
            st.insert({b,mx});
        }

        return mx;
    }
};
