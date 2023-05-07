// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>ans,tmp;
        int n=obstacles.size();
        ans.push_back(1);
        tmp.push_back(obstacles[0]);
        for(int i=1;i<n;i++){
            if(obstacles[i]>=tmp.back()) tmp.push_back(obstacles[i]),ans.push_back(tmp.size());
            else{
                auto it=upper_bound(tmp.begin(),tmp.end(),obstacles[i])-tmp.begin();
                tmp[it]=obstacles[i];
                ans.push_back(it+1);
            }
        }
        return ans;
    }
};
