// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/description/

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end());
        int n=properties.size();
        int mx=0,i=n-1,ans=0;
        while(i>=0){
            int mx2=properties[i][1];
            if(properties[i][1]<mx) ans++; 
            while(i>0 && properties[i][0]==properties[i-1][0]){
                if(properties[i-1][1]<mx) ans++;
                mx2=max(mx2,properties[i-1][1]);
                i--;
            }
            mx=max(mx,mx2);
            i--;
        }
        return ans;
    }
};
