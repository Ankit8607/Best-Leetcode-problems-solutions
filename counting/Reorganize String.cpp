// https://leetcode.com/problems/reorganize-string/

/*

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

*/


class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        set<pair<int,char>,greater<pair<int,char>>>st;
        int mx=0;
        for(auto &i:mp){
            st.insert({i.second,i.first});
            mx=max(mx,i.second);
        }
        if((2*mx-1)>s.size()) return "";
        int i=0;
        char arr[s.size()];
        auto it=st.begin();
        while(it!=st.end()){
            // cout<<it->first<<" "<<it->second<<endl;
            for(int j=0;j<it->first;j++){
                arr[i]=it->second;
                i+=2;
                if(i>=s.size()) i=1;
            }
            it++;
        }

        string ans;
        for(int i=0;i<s.size();i++){
            ans+=arr[i];
            // cout<<arr[i];
        }
        return ans;
    }
};
