// https://leetcode.com/problems/the-kth-factor-of-n/?envType=study-plan-v2&envId=amazon-spring-23-high-frequency

class Solution {
public:
    int kthFactor(int n, int k) {
        for(int i=1;i<=n;i++){
            if(n%i==0){
                if(k==1) return i;
                k--;
            }
        }
        return -1;
    }
};
