// https://leetcode.com/problems/minimum-window-substring/

/*

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 
 
Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?

*/

class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        string ans;
        if(m>n || m==0) return ans;
        int l=0,r=0;
        vector<int>trr(126,0),arr(126,0);
        map<char ,int>mp;
        for(char i:t) trr[i]++;
        int cnt=0;
        for(int i=0;i<126;i++) if(trr[i]) cnt++;
        while(r<n){
            arr[s[r]]++;
            if(arr[s[r]]==trr[s[r]]) cnt--;
            while(cnt==0 and r<n and l<=r){
                if(ans.size()==0 || ans.size()>r-l+1) ans=s.substr(l,r-l+1);
                arr[s[l]]--;
                if(trr[s[l]]!=0 and arr[s[l]]<trr[s[l]]) cnt++;
                l++;
            }
            r++;
        }
        return ans;
    }
};


// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int n=s.size(),m=t.size();
//         string ans;
//         if(m>n || m==0) return ans;
//         int l=0,r=0;
//         vector<int>arr(126,0),trr(126,0);
//         for(char i:t) trr[i]++;
//         while(r<n){
//             arr[s[r]]++;
//             bool x=1;
//             for(int i=0;i<126;i++){
//                 if(arr[i]<trr[i]){
//                     x=0;
//                     break;
//                 }
//             }
//             while(x and r<n and l<=r){
//                 if(ans.size()==0 || ans.size()>r-l+1) ans=s.substr(l,r-l+1);
//                 arr[s[l]]--;
//                 if(arr[s[l]]<trr[s[l]]) x=0;
//                 l++;
//             }
//             r++;
//         }
//         return ans;
//     }
// };
