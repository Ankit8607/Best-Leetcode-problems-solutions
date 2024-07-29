// https://leetcode.com/problems/count-number-of-teams/description/?envType=daily-question&envId=2024-07-29

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0,n=rating.size();
        for(int i=1;i<n-1;i++){
            int left=0, right=0;
            for(int j=i+1;j<n;j++)
                if(rating[i]<rating[j]) right++;
            for(int j=0;j<i;j++)
                if(rating[i]>rating[j]) left++;
            ans+=(left*right);
            left=0; right=0;
            for(int j=i+1;j<n;j++)
                if(rating[i]>rating[j]) right++;
            for(int j=0;j<i;j++)
                if(rating[i]<rating[j]) left++;
            ans+=(left*right);
        }
        return ans;
    }
};
