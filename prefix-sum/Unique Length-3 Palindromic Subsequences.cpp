// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int st[26];
        int end[26],n=s.size();
        int arr[n+1][26];
        memset(arr, 0, sizeof(arr));
        memset(st, -1, sizeof(st));
        memset(end, -1, sizeof(end));
        for(int i=0;i<n;i++){
            int t=s[i]-'a';
            if(st[t]==-1) st[t]=i;
            else end[t]=i;
            arr[i+1][t]=1;
            for(int j=0;j<26;j++) arr[i+1][j]+=arr[i][j];
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(st[i]!=-1 and end[i]!=-1){
                int cnt=0,l=st[i],r=end[i];
                for(int j=0;j<26;j++) cnt+=(arr[r][j]-arr[l+1][j]>0?1:0);
                ans+=cnt;
            }
        }
        return ans;
    }
};
