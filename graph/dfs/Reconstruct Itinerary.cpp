// https://leetcode.com/problems/reconstruct-itinerary/

class Solution {
public:
    vector<string>ans;

    void rec(string start,string end, map<string,vector<pair<string,int>>>&mp, vector<string> &res, int tickets ){
        if(tickets==0){
            ans=res;
            return;
        }

        for(auto &i: mp[start]){
            if(i.second==0){
                res.push_back(i.first);
                i.second=1;
                rec(i.first,end,mp,res,tickets-1);
                i.second=0;
                res.pop_back();
            }
            if(ans.size()) break;
        }
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,vector<pair<string,int>>>mp;
        int path=tickets.size();
        map<string,int>st;
        for(auto i: tickets){
            mp[i[0]].push_back({i[1],0});
            st[i[0]]++;
            st[i[1]]--;
        }
        string start=(*st.begin()).first,end=(*st.rbegin()).first;
        for(auto i: st){
            if(i.second>0) start=i.first;
            if(i.second<0) end=i.first;
        }
        for(auto &i: mp){
            sort(i.second.begin(),i.second.end());
        }
        vector<string>res;
        res.push_back("JFK");
        rec("JFK",end,mp,res,path);
        return ans;
    }
};
