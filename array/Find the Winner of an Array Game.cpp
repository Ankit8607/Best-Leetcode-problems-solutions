// https://leetcode.com/problems/find-the-winner-of-an-array-game/description/?envType=daily-question&envId=2023-11-05

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int cnt=0,n=arr.size();
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]) cnt++,arr[i+1]=arr[i];
            else cnt=1;
            if(cnt>=k) return arr[i+1];
        }
        return arr[n-1];
    }
};
