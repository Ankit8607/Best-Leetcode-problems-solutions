// https://leetcode.com/problems/minimum-time-to-complete-all-tasks/

class Solution {
public:

    static bool comp(vector<int>&a,vector<int>&b){
        if(b[1]==a[1]) return a[0]<b[0];
        return a[1]<b[1];
    }

    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),comp);
        int n=tasks.size();
        vector<int>mark(2000+10,0);
        int mx=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=tasks[i][0];j<=tasks[i][1];j++) sum+=mark[j];
            if(sum<tasks[i][2]){
                int t=tasks[i][2]-sum;
                for(int j=tasks[i][1];(j>=tasks[i][0]) and t;j--) if(mark[j]==0) mark[j]=1,t--,mx++;
            }
        }
        return mx;
    }
};
