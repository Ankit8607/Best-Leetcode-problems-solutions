// https://leetcode.com/problems/lru-cache/description/

class LRUCache {
public:
    int n,time,sz,ptr;
    vector<int>v;
    map<int,int>mp,mptime;
    LRUCache(int capacity) {
        n=capacity;
        time=0;
        sz=0;
        ptr=0;
    }
    
    int get(int key) {
        if(mp.count(key)){
            update(key,mp[key]);
            return mp[key];
        }
        return -1;
    }
    
    void update(int key,int value){
        mp[key]=value;
        v.push_back(key);
        v[mptime[key]]=-1;
        mptime[key]=time++;
    }

    void put(int key, int value) {
        if(mp.count(key)){
            update(key,value);
        }
        else if(sz<n){
            mp[key]=value;
            v.push_back(key);
            mptime[key]=time++;
            sz++;
        }
        else{
            while(v[ptr]==-1){
                ptr++;
            }
            mp.erase(v[ptr]);
            mptime.erase(v[ptr]);
            v[ptr]=-1;
            v.push_back(key);
            mp[key]=value;
            mptime[key]=time++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
