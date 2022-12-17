// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/description/

class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int op=0,cl=0,ans=0;
        int i=0;
        while(i<n) {
            char ch=s[i];
            if(ch=='(') op++;
            else cl++;
            if(op and cl){
                if(cl==1){
                    if(i+1<n and s[i+1]==')'){
                        i++;
                        continue;
                    }
                    else ans++, cl++;
                }
                op--;
                cl-=2;
            }
            if(op==0 and cl>0){
                op++;
                cl--;i--;
                ans++;
            }
            i++;
        }
        if(op) ans+=(2*op-cl);
        else if(cl>1){
            if(cl%2==0) ans+=cl/2;
            else ans+=(cl+1)/2+1;
        }
        return ans;
    }
};
