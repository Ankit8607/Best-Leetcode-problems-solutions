// https://leetcode.com/problems/sum-of-subarray-minimums/description/?envType=daily-question&envId=2024-01-20

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size(),mod=1e9+7;
        vector<int>left(n),right(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[st.top()]>=arr[i]) st.pop();
            left[i]=(st.empty()?-1:st.top());
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[st.top()]>arr[i]) st.pop();
            right[i]=(st.empty()?n:st.top());
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=1LL*arr[i]*(right[i]-i)*(i-left[i])%mod;
            ans%=mod;
        }
        return ans;
    }
};
