// https://leetcode.com/problems/my-calendar-iii/

class MyCalendarThree {
public:
    multiset<pair<int,int>>start;
    multiset<int>end;
    MyCalendarThree() {
        start.clear();
        end.clear();
    }
    
    int book(int startTime, int endTime) {
        int ans=0,cnt=0;
        start.insert({startTime,endTime});
        end.insert(endTime);
        auto it=end.begin();
        for(auto &i:start){
            while(it!=end.end() and i.first>=*it){
                cnt--;
                it++;
            }
            cnt++;
            ans=max(ans,cnt);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
