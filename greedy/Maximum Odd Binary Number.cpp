// https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt=0;
        for(auto i:s) if(i=='1') cnt++;
        cnt--;
        for(int i=0;i<s.size();i++){
            if(cnt>0) s[i]='1';
            else s[i]='0';
            cnt--;
        }
        s[s.size()-1]='1';
        return s;
    }
};
