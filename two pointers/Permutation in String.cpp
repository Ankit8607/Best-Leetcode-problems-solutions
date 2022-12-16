// https://leetcode.com/problems/permutation-in-string/description/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        int arr[26],brr[26];
        memset(arr,0,sizeof(arr));
        memset(brr,0,sizeof(brr));

        for(char &i:s1) arr[i-'a']++;

        int l=0,r=0;
        while(r<m){
            brr[s2[r]-'a']++;
            while(arr[s2[r]-'a']<brr[s2[r]-'a']){
                brr[s2[l]-'a']--;
                l++;
            }
            if(r-l+1==n) return 1;
            r++;
        }
        return 0;
    }
};
