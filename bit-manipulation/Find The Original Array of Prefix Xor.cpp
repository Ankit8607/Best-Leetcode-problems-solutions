// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/?envType=daily-question&envId=2023-10-31

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        for(int i=pref.size()-1;i>0;i--) pref[i]^=pref[i-1];
        return pref;
    }
};
