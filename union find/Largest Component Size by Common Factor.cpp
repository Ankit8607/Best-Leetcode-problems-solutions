// https://leetcode.com/problems/largest-component-size-by-common-factor/

class Solution {
public:

    int find(int node,vector<int>&par){
        if(par[node]==node) return node;
        return par[node]=find(par[node],par);
    }

    void merge(int u,int v,vector<int>&par,vector<int>&rank){
        int x=find(u,par),y=find(v,par);
        if(x==y) return;

        if(rank[x]>=rank[y]){
            par[y]=par[x];
            rank[x]+=rank[y];
        }
        else{
            par[x]=par[y];
            rank[y]+=rank[x];
        }
    }

    int largestComponentSize(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>par(mx+1),rank(mx+1,0);
        for(int i=0;i<=mx;i++) par[i]=i;
        for(auto i:nums){
            if(i==1) continue;
            vector<int>fact;
            int f=2,num=i;
            while(i>1 and f*f<=num){
                if(i%f==0) fact.push_back(f);
                while(i%f==0) i/=f;
                f++;
            }
            if(i>1) fact.push_back(i);
            par[fact[0]]=find(fact[0],par);
            rank[par[fact[0]]]++;
            for(int k=1;k<fact.size();k++) merge(par[fact[0]],fact[k],par,rank);
            // cout<<"par= "<<par[fact[0]]<<" rank= "<<rank[par[fact[0]]]<<endl;
        }
        int ans=1;
        for(auto i:rank) ans=max(ans,i);
        return ans;
    }
};
