// https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/description/

class Solution {
public:
    double dp[1010][1010];
    double rec(int level,int skips,vector<int>&dist,int speed){
        if(level==dist.size()) return 0; 

        if(dp[level][skips]!=0) return dp[level][skips];

        double ans=1e9;

        double time= (double)dist[level]/speed;
        ans=min(ans,ceil((double)rec(level+1,skips,dist,speed)+time));

        if(skips>0) ans=min(ans,(double)rec(level+1,skips-1,dist,speed)+time-(1e-7));
        
        return dp[level][skips]=ans;
    }

    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int sum=0;
        for(auto &i:dist) sum += i;
        if(ceil((double)sum/speed)>hoursBefore) return -1;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<dist.size();i++){
            if(rec(0,i,dist,speed)<=hoursBefore)
                return i;
        }
        return -1;
    }
};
