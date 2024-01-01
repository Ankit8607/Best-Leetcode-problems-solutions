// https://leetcode.com/problems/assign-cookies/description/?envType=daily-question&envId=2024-01-01

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0,it=0;
        for(int i=0;i<g.size();i++){
            while(it<s.size() and g[i]>s[it]) it++;
            if(it<s.size()) ans++,it++;
        }
        return ans;
    }
};
