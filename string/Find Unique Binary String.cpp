// https://leetcode.com/problems/find-unique-binary-string/?envType=daily-question&envId=2023-11-16

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string>st;
        int n=nums.size();
        string ans;
        for(auto i:nums) st.insert(i);
        for(int i=0;i<(1<<n);i++){
            string tmp= bitset<16>(i).to_string();
            tmp=tmp.substr(16-n);
            st.insert(tmp);
            if(st.size()>n) return tmp;
        }
        return ans;
    }
};
