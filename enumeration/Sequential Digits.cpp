// https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2024-02-02

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1;i<9;i++){
            int t=i,k=i+1;
            while(k<=9){
                t=t*10+k; k++;
                if(t>high) break;
                if(t>=low) ans.push_back(t);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
