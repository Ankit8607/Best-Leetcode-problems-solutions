// https://leetcode.com/problems/construct-smallest-number-from-di-string/

class Solution {
public:

    int rec(int level,string pattern, int *vis,int *res){
        if(level== pattern.size()+1) return 1;

        if(level==0){
            for(int i=1;i<=9;i++){
                res[0]=i;
                vis[i]=1;
                if(rec(level+1,pattern,vis,res)) return 1;
                vis[i]=0;
            }
        }
        else{
            for(int i=1;i<=9;i++){
                if(vis[i]) continue;
                if(pattern[level-1]=='I'){
                    if(i>res[level-1]){
                        vis[i]=1;
                        res[level]=i;
                        if(rec(level+1,pattern,vis,res)) return 1;
                        vis[i]=0;
                    }
                }
                else{
                    if(i<res[level-1]){
                        vis[i]=1;
                        res[level]=i;
                        if(rec(level+1,pattern,vis,res)) return 1;
                        vis[i]=0;
                    }
                }
            }
        }
        return 0;
    }
    string smallestNumber(string pattern) {
        int vis[10]={0};
        int ans[pattern.size()+1];
        rec(0,pattern,vis,ans);
        string res="";
        for(int i=0;i<pattern.size()+1;i++) res+=(ans[i]+'0');
        return res;
    }
};
