// https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/?envType=daily-question&envId=2023-11-18

static const auto _ = []{cin.tie(0);ios::sync_with_stdio(0);return 0;}();
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int j = 0; long sum = k;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum < (long)nums[i]*(i-j+1)) sum -= nums[j++];
        }
        return nums.size()-j;
    }
};
