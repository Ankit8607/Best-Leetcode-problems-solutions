// https://leetcode.com/problems/remove-duplicate-letters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        int n=s.size();
        int last[26],pre[26]={0};
        memset(last,-1,sizeof(last));
        for(int i=0;i<n;i++) last[s[i]-'a']=i;
        for(int i=0;i<n;i++){
            if(pre[s[i]-'a']) continue;
            while(!st.empty() and s[i]<st.top() and last[st.top()-'a']>i){
                pre[st.top()-'a']=0;
                st.pop();
            }
            if(!pre[s[i]-'a'])st.push(s[i]);
            pre[s[i]-'a']=1;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
