// https://leetcode.com/problems/data-stream-as-disjoint-intervals/

class SummaryRanges {
public:
    set<pair<int,int>>st;
    vector<int>arr;
    SummaryRanges() {
        st.clear();
        arr.resize(10001,0);
        // memset(arr,0,sizeof(arr));
    }
    
    void addNum(int value) {
        // cout<<arr[value];
        if(arr[value]) return;
        arr[value]=1;
        if(st.size()==0){
            st.insert({value,0});
            st.insert({value,1});
            return;
        }
        auto it=st.lower_bound({value,-2});
        if(it==st.begin()){
            if(value+1==it->first) st.erase(it);
            else st.insert({value,1});
            st.insert({value,0});
        }
        else if(it==st.end()){
            it--;
            if(value-1==it->first){
                st.erase(it);
                st.insert({value,1});
            }
            else st.insert({value,0}),st.insert({value,1});;
        }
        else{
            if(value+1==it->first){
                auto i=it;
                i--;
                st.erase(it);
                if(i->first+1==value){
                    st.erase(i);
                    return;
                }
                st.insert({value,0});
            }
            else{
                it--;
                if(it->first+1==value) st.erase(it);
                else st.insert({value,0});
                st.insert({value,1});
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        auto it=st.begin();
        while(it!=st.end()){
            // cout<<"it->first= "<<it->first<<" it->second= "<<it->second<<endl;
            vector<int>res;
            res.push_back(it->first);
            it++; 
            // cout<<"it->first= "<<it->first<<" it->second= "<<it->second<<endl;
            res.push_back(it->first);
            ans.push_back(res);
            it++;
        }
        // cout<<endl;
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
