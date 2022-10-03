// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans;
        int cnt=0;
        for(string &i: dictionary){
            int tmp=0;
            int a=0,b=0;
            while(a<i.size() and b<s.size()){
                if(i[a]==s[b]){
                    a++; b++; tmp++;
                }
                else b++;
            }
            if(tmp==i.size()){
                if(tmp>cnt){
                    cnt=tmp;
                    ans=i;
                }
                else if(cnt==tmp){
                    if(ans>i) ans=i;
                }
            }
        }
        return ans;
    }
};
