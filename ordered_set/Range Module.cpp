// https://leetcode.com/problems/range-module/

/*

A Range Module is a module that tracks ranges of numbers. Design a data structure to track the ranges represented as half-open intervals and query about them.

A half-open interval [left, right) denotes all the real numbers x where left <= x < right.

Implement the RangeModule class:

RangeModule() Initializes the object of the data structure.
void addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
boolean queryRange(int left, int right) Returns true if every real number in the interval [left, right) is currently being tracked, and false otherwise.
void removeRange(int left, int right) Stops tracking every real number currently being tracked in the half-open interval [left, right).
 

Example 1:

Input
["RangeModule", "addRange", "removeRange", "queryRange", "queryRange", "queryRange"]
[[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
Output
[null, null, null, true, false, true]

Explanation
RangeModule rangeModule = new RangeModule();
rangeModule.addRange(10, 20);
rangeModule.removeRange(14, 16);
rangeModule.queryRange(10, 14); // return True,(Every number in [10, 14) is being tracked)
rangeModule.queryRange(13, 15); // return False,(Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
rangeModule.queryRange(16, 17); // return True, (The number 16 in [16, 17) is still being tracked, despite the remove operation)
 

Constraints:

1 <= left < right <= 109
At most 104 calls will be made to addRange, queryRange, and removeRange.

*/


class RangeModule {
public:
    set<pair<int,int>> s;
    RangeModule() {}
    
    void addRange(int x, int y) {
        auto it = s.upper_bound({x,INT_MAX});
        if (it != s.begin()){
            // if previous interval overlap merge and delete
            if ((--it)->second < x) ++it;
            else {
                x = it->first;
                y = max(it->second,y);
                it = s.erase(it);
            }
        }
        // while overlapping merge and delete
        while (it != s.end() && it->first <= y) {
            y = max(y,it->second);
            it = s.erase(it);
        }
        s.insert({x,y});
    }
    
    bool queryRange(int x, int y) {
        auto it = s.upper_bound({x,INT_MAX});
        return (it != s.begin() && (--it)->second >=y);
    }
    
    void removeRange(int x, int y) {
        auto it = s.upper_bound({x,INT_MAX});
        vector<pair<int,int>> to;
        if (it != s.begin()){
            if ((--it)->second <= x) ++it;
            else {
                // if previous interval overlap remove but add back the portion still covered
                to.push_back({it->first, x});
                if (it->second > y) to.push_back({y, it->second});
                it = s.erase(it);
            }
        }
        // while overlapping remove
        // if one of the removed intervals is partially covered by the remove range, add back the uncovered portion
        while (it != s.end() && it->first < y) {
            if (it->second > y) to.push_back({y, it->second});
            it = s.erase(it);
        }
        for (auto p : to) s.insert(p);
    }
};
