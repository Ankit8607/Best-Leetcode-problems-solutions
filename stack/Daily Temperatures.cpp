// https://leetcode.com/problems/daily-temperatures/description/?envType=daily-question&envId=2024-01-31

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        vector<int>ans(temperatures.size());
        for(int i=temperatures.size()-1;i>=0;i--){
            while(!st.empty() and temperatures[i]>=temperatures[st.top()]) st.pop();
            ans[i]=(st.empty()?0:st.top()-i);
            st.push(i);
        }
        return ans;
    }
};
