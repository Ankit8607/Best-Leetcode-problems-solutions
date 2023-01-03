// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

class Solution {
public:
    int beautySum(string s) {
        int l,m;
        unordered_map<char,int> umap;
        int res=0;
        for(int i=0;i<s.length();i++){
            umap.clear();
            for(int j=i;j<s.length();j++){
                umap[s[j]]++;
                if(j-i>1){
                    m=0;
                    l=INT_MAX;
                    for(auto i : umap){
                        m = max(i.second,m);
                        l = min(i.second,l);
                    }
                    res+=m-l;
                }
            }
        }
        return res;
    }
};
