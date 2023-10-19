// https://leetcode.com/problems/backspace-string-compare/description/?envType=daily-question&envId=2023-10-19

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a,b;
        for(auto i:s){
            if(i=='#'){
                if(!a.empty()) a.pop();
            }
            else a.push(i);
        }
        string as,bs;
        while(!a.empty()){
            as+=a.top();
            a.pop();
        }
        for(auto i:t){
            if(i=='#'){
                if(!b.empty()) b.pop();
            }
            else b.push(i);
        }
        while(!b.empty()){
            bs+=b.top();
            b.pop();
        }
        return as==bs;
    }
};
