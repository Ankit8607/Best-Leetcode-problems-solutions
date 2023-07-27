// https://leetcode.com/problems/maximum-running-time-of-n-computers/description/

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int m=batteries.size();
        sort(batteries.begin(),batteries.end());
        long long sum=0;
        for(int i=0;i<m-n;i++) sum+=batteries[i];
        long long ans=0,l=0,r=sum+batteries[m-1];
        while(l<=r){
            long long mid=(l+r)/2,t=sum;
            int flag=1;
            for(int i=m-n;i<m;i++){
                if(batteries[i]<mid) t-=mid-batteries[i];
                if(t<0){
                    flag=0;
                    break;
                }
            }
            if(flag){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
            cout<<"mid= "<<mid<<endl;
        }
        return ans;
    }
};
