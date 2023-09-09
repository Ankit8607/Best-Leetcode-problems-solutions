// https://practice.geeksforgeeks.org/problems/uncommon-characters4932/1

class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            int cnt[26]={0};
            for(auto i:A) cnt[i-'a']=1;
            for(auto i:B){
                if(cnt[i-'a']==1) cnt[i-'a']=2;
                else if(cnt[i-'a']==0) cnt[i-'a']=3;
            } 
            string ans;
            for(int i=0;i<26;i++) if(cnt[i]==1 || cnt[i]==3)ans+=('a'+i);
            if(ans.size()==0) return "-1";
            return ans;
        }
};
