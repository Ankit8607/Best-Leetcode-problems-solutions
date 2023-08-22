// https://leetcode.com/problems/excel-sheet-column-title/description/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber){
            columnNumber--;
            ans+=(columnNumber%26+'A');
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
