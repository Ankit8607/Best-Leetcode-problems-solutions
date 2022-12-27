// https://leetcode.com/problems/rearrange-words-in-a-sentence/description/

class Solution {
public:
    string arrangeWords(string text) {
        text[0]=text[0]-'A'+'a';
        vector<pair<int,pair<int,string>>>v;
        stringstream ss(text);
        string word;
        int i=0;
        while(ss>>word){
            v.push_back({word.size(),{i++,word}});
        }
        sort(v.begin(),v.end());
        string ans="";
        for(auto &i:v){
            if(ans.size()==0) ans+=i.second.second;
            else ans+=" "+i.second.second;
        }
        ans[0]=ans[0]-'a'+'A';
        return ans;
    }
};
