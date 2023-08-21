// https://leetcode.com/problems/repeated-substring-pattern/

class Solution {
public:

    string st(string s, int t){
        string ans;
        while(t--) ans+=s;
        return ans;
    }

    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        vector<int>fact;
        if(n>1) fact.push_back(1);
        for(int i=2;i*i<=n;i++) if(n%i==0) fact.push_back(i),fact.push_back(n/i);
        for(auto i:fact) cout<<i<<" ";
        for(auto i:fact) if(s==st(s.substr(0,i),n/i)) return 1;
        return false;
    }
};
