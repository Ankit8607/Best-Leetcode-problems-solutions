// https://leetcode.com/problems/restore-ip-addresses/

class Solution {
public:
    vector<string>ans;

    void rec(int level,int last,string &s,string &cur,int cnt){
        if(last>255 || cnt>3) return;
        if(s[level]<'0' and s[level]>'9') return;
        if(level==s.size()){ 
            if(last!=-1 and cnt==3)ans.push_back(cur);
            return;
        }

        if(last==-1){
            cur+=s[level];
            rec(level+1,(s[level]-'0'),s,cur,cnt);
            cur.pop_back();
        }
        else if(last!=0){
            cur+=s[level];
            rec(level+1,last*10+(s[level]-'0'),s,cur,cnt);
            cur.pop_back();
        }
        if(last!=-1){
            cur+='.';
            rec(level,-1,s,cur,cnt+1);
            cur.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string cur;
        rec(0,-1,s,cur,0);
        return ans;
    }
};
