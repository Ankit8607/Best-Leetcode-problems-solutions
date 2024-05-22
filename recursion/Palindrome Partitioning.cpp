// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:

    bool ispalindrome(string s){
        for(int i=0;i<s.size()/2;++i){
            if(s[i]==s[s.size()-1-i]){
                continue;
            }
            return false;
        }
        return true;
    }

    void rec(int level, string &s, vector<vector<int>>&p, vector<vector<string>>&ans,vector<string>&tmp){
        if(level==s.size()){
            ans.push_back(tmp);
            return;
        }

        for(auto i:p[level]){
            tmp.push_back(s.substr(level,i));
            rec(level+i,s,p,ans,tmp);
            tmp.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<int>>p(s.size());
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispalindrome(s.substr(i,j-i+1))){
                    p[i].push_back(j-i+1);
                }
            }
        }
        vector<vector<string>>ans;
        vector<string>tmp;
        rec(0,s,p,ans,tmp);
        return ans;
    }
};
