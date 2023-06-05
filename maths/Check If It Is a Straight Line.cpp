// https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates[1][0]== coordinates[0][0]){
            for(int i=0;i<coordinates.size();i++)
                if(coordinates[0][0]!= coordinates[i][0]) return false;
            return true;
        }
        int slope=((coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]));
        for(int i=2;i<coordinates.size();i++){
            if(coordinates[1][0]== coordinates[i][0] || slope!=((coordinates[1][1]-coordinates[i][1])/(coordinates[1][0]-coordinates[i][0]))) return false;
        }
        return true;
    }
};
