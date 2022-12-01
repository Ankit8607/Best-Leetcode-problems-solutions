// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

class Solution {
public:
    int minTaps(int n, vector<int>& range) {
        int arr[n+1];
        int ans=0;
        int till=-1;
        int store=-1;
        for(int i=0;i<=n;i++){
            arr[i]=-1;
            if(range[i]==0) continue;
            arr[max(0,i-range[i])]=min(n,i+range[i]);
        }
        for(int i=0;i<=n;i++){
            store=max(store,arr[i]);          
            if(till<=i and i!=n){
                till=store;
                // cout<<"i= "<<i<<" "<<"till= "<<till<<endl;
                ans++;
            }
            if(store<i) return -1;
        }
        return ans;
    }
};
