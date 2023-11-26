// https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/?envType=daily-question&envId=2023-11-26

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            vector<int>tmp;
            for(int j=0;j<matrix[i].size();j++){
                if(i and matrix[i][j]) matrix[i][j]+=matrix[i-1][j];
                tmp.push_back(matrix[i][j]);
            }
            sort(tmp.begin(),tmp.end(),greater<int>());
            for(int j=0;j<matrix[i].size();j++) ans=max(ans,tmp[j]*(j+1));
        }
        return ans;
    }
};
