// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int id) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>row(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                row[i][j]=row[i][j-1]+mat[i-1][j-1];
        int ans=-1e9;
        for(int i=1;i<=m;i++){
            for(int j=i;j<=m;j++){
                int sum=0;
                set<int>st;
                st.insert(0);
                for(int k=1;k<=n;k++){
                    sum+=row[k][j]-row[k][i-1];
                    auto it=st.lower_bound((sum-id));
                    if(it!=st.end()){
                        if(ans<(sum-*it))
                            ans=sum-*it;
                    }
                    st.insert(sum);
                }
            }
        }
        return ans;
    }
};
