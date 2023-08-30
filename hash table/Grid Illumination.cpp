// https://leetcode.com/problems/grid-illumination/

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        multiset<int> row,col,dia1,dia2;
        set<pair<int,int>>arr;
        for(auto i:lamps){
            if(arr.find({i[0],i[1]})!=arr.end()) continue;
            row.insert(i[0]); col.insert(i[1]); dia1.insert(i[0]+i[1]); dia2.insert(n+i[0]-i[1]-1);
            arr.insert({i[0],i[1]});
        }
        vector<int>ans;
        int dx[]={1,1,1,-1,-1,-1,0,0,0};
        int dy[]={1,0,-1,-1,0,1,0,1,-1};
        for(auto i: queries){
            int r=i[0],c=i[1];
            ans.push_back(0);
            if(row.find(r)!=row.end() || col.find(c)!=col.end() || dia1.find(r+c)!=dia1.end() || dia2.find(n+r-c-1)!=dia2.end()) ans.back()=1;
            for(int j=0;j<9;j++){
                int x=r+dx[j];
                int y=c+dy[j];
                if(x>=0 and y>=0 and x<n and y<n and arr.find({x,y})!=arr.end()){
                    row.erase(row.find(x)); col.erase(col.find(y)); dia1.erase(dia1.find(x+y)); dia2.erase(dia2.find(n+x-y-1));
                    arr.erase({x,y});
                }
            }
        }
        return ans;
    }
};
