// https://leetcode.com/problems/build-an-array-with-stack-operations/description/?envType=daily-question&envId=2023-11-03

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int it=0,num=1;
        while(it<target.size() and num<=n){
            ans.push_back("Push");
            if(target[it]!=num) ans.push_back("Pop");
            else it++;
            num++;
        }
        return ans;
    }
};
