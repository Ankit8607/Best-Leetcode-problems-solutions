// https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=1,last=0,prev=0;
        set<int>st;
        st.insert(fruits[0]);
        for(int i=1;i<fruits.size();i++){
            st.insert(fruits[i]);
            if(st.size()==3){
                prev=last;
                st.clear();
                st.insert(fruits[i]);
                st.insert(fruits[i-1]);
            }
            ans=max(ans,i-prev+1);
            if(fruits[i-1]!=fruits[i]) last=i;
        }
        return ans;
    }
};
