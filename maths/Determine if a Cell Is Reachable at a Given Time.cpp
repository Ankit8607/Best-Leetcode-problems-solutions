// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/?envType=daily-question&envId=2023-11-08

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x=abs(sx-fx),y=abs(fy-sy);
        int dist=max(x,y);
        if(t<dist || (t==1 and sx==fx and sy==fy) ) return false;
        return true;
    }
};
