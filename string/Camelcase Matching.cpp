// https://leetcode.com/problems/camelcase-matching/description/

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for(string &s:queries) {
            int n=s.size();
            int m=pattern.size();
            int i=0,j=0;
            int flag=0;
            while(i<n and j<m) {
                if(s[i]==pattern[j]) i++,j++;
                else{
                    if(s[i]>='A' && s[i]<='Z'){
                        result.push_back(0);
                        flag=1;
                        break;
                    }
                    else i++;
                }
            }
            if(flag) continue;
            if(j==m and i<n){
                while(i<n){
                    if(s[i]>='A' && s[i]<='Z'){
                        result.push_back(0);
                        flag=1;
                        break;
                    }
                    i++;
                }
                if(flag==0) result.push_back(1);
            }
            else if(j<m) result.push_back(0);
            else result.push_back(1);
        }
        return result;
    }
};
