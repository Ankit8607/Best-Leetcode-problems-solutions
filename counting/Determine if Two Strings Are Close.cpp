// https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=daily-question&envId=2024-01-14

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>a(26,0),b(26,0);
        for(auto i:word1) a[i-'a']++;   
        for(auto i:word2) b[i-'a']++;   
        for(int i=0;i<26;i++){
            if(a[i]==0 and b[i]) return 0;
            if(b[i]==0 and a[i]) return 0; 
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b;
    }
};
