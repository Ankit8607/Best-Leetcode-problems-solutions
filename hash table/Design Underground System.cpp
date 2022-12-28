// https://leetcode.com/problems/design-underground-system/description/

class UndergroundSystem {
    map<pair<string, string>, pair<int, int>> stationTimeMap;  // (startStation, endStation), (cnt, totTime)
    map<int, pair<int, string>> startTimeMap;  // id, (startTime, station)
    
public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        startTimeMap[id] = make_pair(t, stationName);
    }
    
    void checkOut(int id, string stationName, int t) {
        int startTime = startTimeMap[id].first;
        string startStation = startTimeMap[id].second;
        stationTimeMap[make_pair(startStation, stationName)].first++;
        stationTimeMap[make_pair(startStation, stationName)].second += t - startTime;
    }
    
    double getAverageTime(string startStation, string endStation) {
        int cnt = stationTimeMap[make_pair(startStation, endStation)].first;
        int totTime = stationTimeMap[make_pair(startStation, endStation)].second;
        return (double) totTime / cnt;
    }
};
