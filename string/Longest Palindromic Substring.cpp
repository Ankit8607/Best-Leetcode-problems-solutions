// https://leetcode.com/problems/longest-palindromic-substring/description/?envType=daily-question&envId=2023-10-27

class Solution {
public:
    string longestPalindrome(string &tmp) {
        string s="@";
        for(int i=0;i<tmp.size();i++) s+='#',s+=tmp[i];
        s+='#'; s+='$';
        int ans=1,n=s.size(),ind=2;
        int c=2,l=2,r=2;
        vector<int>len(n); 
        for(int i=2;i<n;i++){
            int mirr=2*c-i;
            len[i]=min(len[mirr],r-i);
            while(s[i+len[i]+1]==s[i-len[i]-1]) len[i]++;
            if(i+len[i]>r) c=i,r=i+len[i];
            if(len[i]>ans) ans=len[i],ind=i;
        }
        if(s[ind]=='#') ind=ind-ans+1;
        else ind=ind-ans+1;
        string res;
        while(ans--) res+=s[ind],ind+=2;
        return res;
    }
};
