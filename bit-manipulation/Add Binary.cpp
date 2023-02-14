// https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0;
        int n=a.size(),m=b.size();
        int carry=0;
        string ans;
        while(i<n || i<m){
            int bita=0;
            if(i<n and a[i]=='1') bita=1;
            int bitb=0;
            if(i<m and b[i]=='1') bitb=1;
            carry+=bita+bitb;
            if(carry==3) ans+='1',carry=1;
            else if(carry==2) ans+='0',carry=1;
            else if(carry) ans+='1',carry=0;
            else ans+='0';
            i++;
        }
        if(carry) ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
