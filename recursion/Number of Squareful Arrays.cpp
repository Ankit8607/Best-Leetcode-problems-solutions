// https://leetcode.com/problems/number-of-squareful-arrays/description/

class Solution {
public:

    void rec(int node,map<int,set<int>>&g, set<vector<int>>&st, vector<int>v,map<int,int>&fre,int &n){
        
        if(n==v.size()){
            st.insert(v);
            return;
        }

        for(auto &i: g[node]){
            if(fre[i]>0){
                fre[i]--;
                v.push_back(i);
                rec(i,g,st,v,fre,n);
                v.pop_back();
                fre[i]++;
            }
        }
    }


    bool fun(int a,int b){
        if(floor(sqrt(a+b))==ceil(sqrt(a+b))) return 1;
        return 0;
    }

    int numSquarefulPerms(vector<int>& nums) {
        map<int,int>fre;
        for(auto i: nums) fre[i]++;

        map<int,set<int>>g;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(fun(nums[i],nums[j])){
                    g[nums[i]].insert(nums[j]);
                }
            }
        }

        set<vector<int>>st;
        for(auto &i: fre){
            i.second--;
            vector<int>v;
            v.push_back(i.first);
            rec(i.first,g,st,v,fre,n);
            v.pop_back();
            i.second++;
        }
        return st.size();
    }
};
