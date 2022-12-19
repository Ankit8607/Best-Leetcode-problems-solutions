// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        set<pair<int,pair<int,int>>>st;
        st.insert({matrix[0][0],{0,0}});
        k--;
        while(k--){
            auto t=st.begin();
            int i=(*t).second.first,j=t->second.second;
            st.erase(st.begin());
            if(i+1<n) st.insert({matrix[i+1][j],{i+1,j}});
            if(j+1<n) st.insert({matrix[i][j+1],{i,j+1}});
        }
        return (*st.begin()).first;
    }
};
