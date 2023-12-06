// https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/?envType=daily-question&envId=2023-12-06

class Solution {
public:
    int totalMoney(int n) {
        int num=1,ans=0;
        while(n){
            for(int i=0;i<=6 and n;i++) ans+=num+i,n--;
            num++;
        }
        return ans;
    }
};
