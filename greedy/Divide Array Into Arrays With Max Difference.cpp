// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-question&envId=2024-02-01

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& arr, int k) {
        int n=arr.size();
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i+=3){
            if(arr[i+2]-arr[i]>k) return {};
            ans.push_back({arr[i],arr[i+1],arr[i+2]});
        }
        return ans;
    }
};
