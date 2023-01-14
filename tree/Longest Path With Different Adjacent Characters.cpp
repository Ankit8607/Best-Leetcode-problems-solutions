// https://leetcode.com/problems/longest-path-with-different-adjacent-characters/

class Solution {
public:
    int ans=0;
    int rec(int node,vector<vector<int>>&g,string &s){
        int mx1=0, mx2=0;
        for(auto &i:g[node]){
            if(s[i]==s[node]) ans=max(ans,rec(i,g,s));
            else{
                int t=rec(i,g,s);
                if(t>=mx1) mx2=mx1,mx1=t;
                else if(t>mx2) mx2=t;
            }
        }
        // cout<<"node= "<<node<<" "<<max(1+mx1+mx2,ans)<<endl;
        ans=max(ans,1+mx1+mx2);
        return 1+max(mx1,mx2);
    }
    int longestPath(vector<int>& parent, string s) {
        int n=s.size();
        vector<vector<int>>g(n);
        for(int i=1;i<n;i++){
            g[parent[i]].push_back(i);
        }
        rec(0,g,s);
        return ans;
    }
};
