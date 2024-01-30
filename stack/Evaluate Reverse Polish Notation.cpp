// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=daily-question&envId=2024-01-30

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto i:tokens){
            if(i=="*" || i=="+" || i=="-" || i=="/"){
                int b=st.top(),a;
                st.pop();
                a=st.top(); st.pop();
                if(i=="*") a*=b;
                else if(i=="+") a+=b;
                else if(i=="-") a-=b;
                else a/=b;
                st.push(a);
            }
            else st.push(stoi(i));
            cout<<st.top()<<" ";
        }
        return st.top();
    }
};
