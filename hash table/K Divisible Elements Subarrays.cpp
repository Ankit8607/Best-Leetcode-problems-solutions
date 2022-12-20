// https://leetcode.com/problems/k-divisible-elements-subarrays/

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int ans=0;
        int n=nums.size(); 
        set<vector<int>>st;
        vector<int>pre(n+1,0);
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(nums[i-1]%p==0);
        for(int j=1;j<=n;j++){
            for(int i=j-1;i<n;i++){
                if(pre[i+1]-pre[i+1-j]<=k){
                    vector<int>res(j);
                    copy(nums.begin()+i+1-j,nums.begin()+i+1,res.begin());
                    st.insert(res);
                }
            }
            ans+=st.size();
            st.clear();
        }
        return ans;
    }
};
