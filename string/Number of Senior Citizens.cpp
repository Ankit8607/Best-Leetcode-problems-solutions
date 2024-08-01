// https://leetcode.com/problems/number-of-senior-citizens/description/?envType=daily-question&envId=2024-08-01

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto i:details){
            int t=((i[11]-'0')*10+(i[12]-'0'));
            ans+=(t>60);
        }
        return ans;
    }
};
