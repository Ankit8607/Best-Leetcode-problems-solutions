// https://leetcode.com/problems/naming-a-company/


class Solution {
public:

    long long distinctNames(vector<string>& ideas){

      
        unordered_map<int, unordered_set<string>>mpp;
        long long res = 0;


        for(auto &it : ideas) mpp[it[0]].insert(it.substr(1,it.size()-1));        

        
        for(int i = 0; i < 26; i++)
        {
            for(int j = i+1; j < 26; j++)
            {
                unordered_set<string>temp1 = mpp[i+'a'], temp2 = mpp[j+'a'];
                
                long long val = 0;

                for(auto &it : temp1)
                {
                  if(temp2.find(it) != temp2.end()) val++;
                }

                
                res += 1LL*((temp1.size()- val)*(temp2.size()- val))*2;
            }
        }

        return res;
    }
};
