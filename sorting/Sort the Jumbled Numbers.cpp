// https://leetcode.com/problems/sort-the-jumbled-numbers/

class Solution {
public:
    int f(int n, vector<int>& map) {
        int t = 0;
        string s = to_string(n);
        for (auto i : s) t = t * 10 + map[i - '0'];
        return t;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&mapping, this](int &a, int &b) {
            int new_a = f(a, mapping), new_b = f(b, mapping);
            return new_a < new_b;
        });
        return nums;
    }
};
