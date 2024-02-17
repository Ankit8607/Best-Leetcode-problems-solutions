// https://leetcode.com/problems/furthest-building-you-can-reach/description/?envType=daily-question&envId=2024-02-17

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int>ld;
        int sum=0,i=1;
        while(i<heights.size()){
            if(heights[i-1]<heights[i]){
                ld.insert(heights[i]-heights[i-1]);
                if(ld.size()>ladders) sum+=*ld.begin(), ld.erase(ld.begin());
                if(sum>bricks) return i-1;
            }
            i++;
        }
        return i-1;
    }
};
