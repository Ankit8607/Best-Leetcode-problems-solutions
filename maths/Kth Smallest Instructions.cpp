// https://leetcode.com/problems/kth-smallest-instructions/

class Solution {
public:
    
    long long ncr(int h,int v,int k){
        if(h<1) return 1;
        long long ans=1;
        for(int i=h+v;i>max(h,v);i--) ans*=i;
        for(int i=min(h,v);i>0;i--) ans/=i;
        return ans;
    }

    string kthSmallestPath(vector<int>& destination, int k) {
        string ans;
        int v=destination[0],h=destination[1];
        while(v+h>0){
            long long res=ncr(h-1,v,k);
            if(res>=k and h) ans+='H',h--;
            else{
                ans+='V';
                v--;
                k-=res;
            }
        }
        return ans;
    }
};
