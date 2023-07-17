// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,sub=0;
        for(auto &i: nums){
            if(i>sub){
                sub=i;
                ans++;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int minimumOperations(vector<int>& arr) {
//         unordered_set<int> s(arr.begin(),arr.end());
//         return s.size()-s.count(0);
//     }
// };
