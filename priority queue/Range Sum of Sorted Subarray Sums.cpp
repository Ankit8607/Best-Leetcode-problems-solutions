// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/

class Solution {
public:
    int rangeSum(vector<int>& A, int N, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < N; ++i) q.emplace(A[i], i + 1);
        long ans = 0, mod = 1e9+7;
        for (int i = 1; i <= right; ++i) {
            auto p = q.top();
            q.pop();
            if (i >= left) ans = (ans + p.first) % mod;
            if (p.second < N) {
                p.first += A[p.second++];
                q.push(p);
            }
        }
        return ans;
    }
};
