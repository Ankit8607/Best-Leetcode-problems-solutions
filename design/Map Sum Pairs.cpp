// https://leetcode.com/problems/map-sum-pairs/

/*

Design a map that allows you to do the following:

Maps a string key to a given value.
Returns the sum of the values that have a key with a prefix equal to a given string.
Implement the MapSum class:

MapSum() Initializes the MapSum object.
void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.
 

Example 1:

Input
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output
[null, null, 3, null, 5]

Explanation
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
 

Constraints:

1 <= key.length, prefix.length <= 50
key and prefix consist of only lowercase English letters.
1 <= val <= 1000
At most 50 calls will be made to insert and sum.

*/



class MapSum {
public:
    
    map<string,int>mp;
    class node{
        public:
        node* child[26]={0};
        int val=0;
    };
    node *head;
    MapSum() {
        head=new node();   
        mp.clear();
    }
    
    void insert(string key, int value) {
        if(mp.find(key)!=mp.end()){
            int tmp=value;
            value-=mp[key];
            mp[key]=tmp;
        }
        else mp[key]=value;
        node *cur=head;
        for(int i=0;i<key.size();i++){
            int x=key[i]-'a';
            if(cur->child[x]==NULL) cur->child[x]=new node();
            cur=cur->child[x];
            cur->val+=value;
        }
    }
    
    int sum(string prefix) {
        node *cur=head;
        for(int i=0;i<prefix.size();i++){
            int x=prefix[i]-'a';
            if(cur->child[x]==NULL) return 0;
            cur=cur->child[x];
        }
        return cur->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
