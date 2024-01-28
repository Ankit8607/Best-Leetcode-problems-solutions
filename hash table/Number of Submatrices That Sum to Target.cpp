// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/?envType=daily-question&envId=2024-01-28

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size(),ans=0;
        for(int i=0;i<n;i++)
            for(int j=1;j<m;j++)
                matrix[i][j]+=matrix[i][j-1];

        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                map<int,int>mp;
                mp[0]=1;
                int sum=0;
                for(int k=0;k<n;k++){
                    sum+=matrix[k][j]-(i>0?matrix[k][i-1]:0);
                    ans+=mp[sum-target];
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};
