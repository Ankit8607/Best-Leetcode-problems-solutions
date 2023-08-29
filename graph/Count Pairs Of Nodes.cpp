// https://leetcode.com/problems/count-pairs-of-nodes/

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degreeVec(n+1);
        typedef pair<int, int> ThePair;
        map<ThePair, int> sharedMap;
        for (auto & vec: edges) {
            degreeVec[vec[0]]++;
            degreeVec[vec[1]]++;
            ThePair p = make_pair(min(vec[0], vec[1]), max(vec[0], vec[1]));
            sharedMap[p]++;
        }
        vector<int> degreeVecOrig = degreeVec;
        sort(degreeVec.begin(), degreeVec.end());
        vector<int> res;
        for (int query : queries) {
            int ans=0;
            int l=1, r=n;
            while (l <r) {
                if (degreeVec[l]+degreeVec[r] > query) {                     
                    ans += (r-l); r--;
                } else {
                    l++;
                }
            }
            for (auto & elem : sharedMap) {
                if ( (degreeVecOrig[elem.first.first] + degreeVecOrig[elem.first.second] > query) &&
                     (degreeVecOrig[elem.first.first] + degreeVecOrig[elem.first.second] - elem.second <= query)) {
                    ans--;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};
