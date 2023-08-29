// https://leetcode.com/problems/minimum-penalty-for-a-shop/

class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int last[n+1];
        last[n]=0;
        // last[n-1]=(customers[n-1]=='Y'?1:0);
        for(int i=n-1;i>=0;i--) last[i]=last[i+1]+(customers[i]=='Y'?1:0);
        int ans=last[0],cnt=0,ind=0;
        for(int i=0;i<n;i++){
            if(ans>last[i]+cnt){
                ans=last[i]+cnt;
                ind=i;
            }
            if(customers[i]=='N') cnt++;
        }
        if(cnt<ans) ind=n;
        return ind;
    }
};
