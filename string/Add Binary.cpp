// https://leetcode.com/problems/add-binary/

/*

Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

*/



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
