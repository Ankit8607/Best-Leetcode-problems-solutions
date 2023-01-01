// https://leetcode.com/problems/car-fleet/description/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>arr;
        int n=position.size();
        for(int i=0;i<n;i++){
            arr.push_back({position[i],1.0*(target-position[i])/speed[i]});
        }

        sort(arr.begin(), arr.end());

        double mx=-1;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(arr[i].second>mx){
                ans++;
                mx=arr[i].second;
            }
        }
        return ans;
    }
};
