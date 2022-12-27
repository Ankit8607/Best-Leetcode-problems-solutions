// https://leetcode.com/problems/closest-divisors/description/

class Solution {
public:
    vector<int> closestDivisors(int num) {
        int a=0,b=1e9+7;
        int t=num+1;
        for(int i=1;i*i<=t;i++){
            if(t%i==0){
                int a1=i,b1=t/i;
                if(b1-a1<b-a) a=a1,b=b1;
            }
        }
        t=num+2;
        for(int i=1;i*i<=t;i++){
            if(t%i==0){
                int a1=i,b1=t/i;
                if(b1-a1<b-a) a=a1,b=b1;
            }
        }
        return {a,b};
    }
};
