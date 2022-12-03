// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    multiset<int>first,second;
    int n;
    MedianFinder() {
        n=0;
    }
    
    void addNum(int num) {
        if(first.size() and num<=*(--first.end()))
            first.insert(num);
        else second.insert(num);
        n++;
    }
    
    double findMedian() {
        while(first.size()<second.size()){
            first.insert(*second.begin());
            auto it=second.begin();
            second.erase(it);
        }
        while(first.size()>second.size()){
            second.insert(*first.rbegin());
            // first.erase(first.find(*first.rbegin()));
            auto it=first.end(); it--;
            first.erase(it);
        }
        if(n%2) return *second.begin();
        else{
            double ans=(*first.rbegin()+*second.begin())/2.0;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
