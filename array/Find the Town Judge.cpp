// https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>he(n+1,0),tr(n+1,0);
        for(auto &i:trust){
            he[i[0]]++;
            tr[i[1]]++;
        } 
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(he[i]==0 and tr[i]==n-1){
                if(ans!=-1) return -1;
                ans=i;
            }
        }
        return ans;
    }
};
