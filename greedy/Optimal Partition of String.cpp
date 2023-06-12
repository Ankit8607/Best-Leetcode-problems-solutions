// https://leetcode.com/problems/optimal-partition-of-string/?envType=study-plan-v2&envId=amazon-spring-23-high-frequency

class Solution {
public:
    int partitionString(string s) {
        int ans=0,n=s.size();
        vector<int>arr(26,0);
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
            if(arr[s[i]-'a']>1)  {
                ans++;
                arr.clear();
                arr.resize(26,0);
                arr[s[i]-'a']=1;
            }
        }
        return ans+1;
    }
};
