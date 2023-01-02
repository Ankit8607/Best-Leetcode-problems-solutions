// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty()){
                if(s[i]=='c' and st.top()=='b'){
                    st.pop();
                    if(!st.empty() and st.top()=='a')st.pop();
                    else return false;
                }
                else st.push(s[i]);
            }
            else st.push(s[i]);
        }
        if(!st.empty()) return false;
        return true;
    }
};
