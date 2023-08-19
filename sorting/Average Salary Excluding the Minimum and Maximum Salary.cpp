// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/

class Solution {
public:
    double average(vector<int>& salary) {
        double sum=0,n=salary.size();
        for(int i:salary) sum+=i;
        sum-=*min_element(salary.begin(),salary.end())+*max_element(salary.begin(),salary.end());
        return sum/(n-2);
    }
};
