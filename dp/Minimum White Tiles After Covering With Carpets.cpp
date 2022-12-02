// https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/

class Solution {
public:

    int pre[1010];
    int dp[1010][1010];
    int n;

    int rec(int level,string &floor,int num,int &len){
        if(level>=n) return 0;
        if(num==0) return pre[n]-pre[level];

        if(dp[level][num]!=-1) return dp[level][num];

        int ans=0;
        if(floor[level]=='0') ans=rec(level+1,floor,num,len);
        else{
            ans=min(1+rec(level+1,floor,num,len),rec(level+len,floor,num-1,len));
        }
        return dp[level][num]=ans;
    }

    int minimumWhiteTiles(string floor, int num, int len) {
        memset(dp,-1,sizeof(dp));
        n=floor.size();
        pre[0]=0;
        for(int i=0;i<n;i++)
            pre[i+1]=pre[i]+(floor[i]-'0');
        return rec(0,floor,num,len);
    }
};
