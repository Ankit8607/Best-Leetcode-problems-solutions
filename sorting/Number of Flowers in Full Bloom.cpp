// https://leetcode.com/problems/number-of-flowers-in-full-bloom/?envType=daily-question&envId=2023-10-11

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<pair<int,int>>arr,per;
        for(int i=0;i<flowers.size();i++){
            arr.push_back({flowers[i][0],1});
            arr.push_back({flowers[i][1]+1,-1});
        }
        for(int i=0;i<persons.size();i++) per.push_back({persons[i],i});
        sort(per.begin(), per.end());
        sort(arr.begin(),arr.end());
        int cnt=0,i=0,j=0;
        vector<int>ans(per.size());
        while(i<arr.size() and j<persons.size()){
            while(j<per.size() and per[j].first<arr[i].first){
                // cout<<per[j].first<<" "<<arr[i].first<<endl;
                ans[per[j].second]=cnt;
                j++;
            }
            // cout<<"i= "<<i<<" j= "<<j<<endl;
            cnt+=arr[i].second;
            i++;
        }
        while(j<persons.size()){
            ans[per[j].second]=0;
            j++;
        }
        return ans;
    }
};
