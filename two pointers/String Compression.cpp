// https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size(),i=0,sz=0;
        while(i<n){
            int cnt=1;
            chars[sz++]=chars[i++];
            while(i<n and chars[i]==chars[i-1]) i++,cnt++;
            if(cnt==1) continue;
            string t=to_string(cnt);
            for(int j=0;j<t.size();j++) chars[sz++]=t[j];
        }
        return sz;
    }
};
