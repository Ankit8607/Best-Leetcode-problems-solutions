// https://leetcode.com/problems/permutation-sequence/description/

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        set<int>st;
        for(int i=1;i<=n;i++) st.insert(i);
        int fact[n+1];
        fact[0]=1;
        for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i;
        int i=0;
        int tot=n;
        n--;
        for(;i<tot;i++){
            int t=(k+fact[n]-1)/fact[n]-1;
            if(k==1) t=0;
            k=k-t*fact[n--];
            auto it=st.begin();
            while(t--) it++;
            ans+=to_string(*it);
            st.erase(it);
        }
        // ans+=to_string(*st.begin());
        return ans;
    }
};
