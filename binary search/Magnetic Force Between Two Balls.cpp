// https://leetcode.com/problems/magnetic-force-between-two-balls/description/

class Solution {
public:

    bool check(int mid,int cnt,vector<int>& position) {
        int last=0;
        cnt--;
        for(int i=1;i<position.size();i++){
            if((position[i]-position[last])>=mid){
                cnt--;
                last=i;
            }
        }
        return cnt<=0;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int l=1,r=position[n-1],ans=1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,m,position)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};
