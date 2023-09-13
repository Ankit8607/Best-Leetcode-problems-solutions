// https://leetcode.com/problems/candy/description/?envType=daily-question&envId=2023-09-13

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>right(n,0);
        for(int i=n-2;i>=0;i--) if(ratings[i]>ratings[i+1]) right[i]=right[i+1]+1;
        int ans=0,left=0;
        for(int i=0;i<n;i++){ 
            if(i>0 and ratings[i]>ratings[i-1]) left++;
            else left=0;
            ans+=max(left,right[i])+1;
        }
        return ans;
    }
};
