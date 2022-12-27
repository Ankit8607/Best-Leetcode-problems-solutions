// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0,arr[3]; arr[0]=0;arr[1]=0;arr[2]=0;
        int i=0,j=0,n=s.size();
        while(i<n){
            while(j<n and (arr[0]==0 || arr[1]==0 || arr[2]==0)){
                arr[s[j]-'a']++;
                j++;
            }
            if(!(arr[0]==0 || arr[1]==0 || arr[2]==0)) ans+=(n-j+1);
            
            arr[s[i++]-'a']--;
        }
        return ans;
    }
};
