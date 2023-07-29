// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int len=0,t=n;
        vector<int>digit;
        for(auto i: digits) digit.push_back(stoi(i));

        vector<int>pre(10,0);
        for(auto i: digit) pre[i]=1;
        vector<int>dig;
        while(t){
            len++;
            dig.push_back(t%10);
            t/=10;
        }
        reverse(dig.begin(),dig.end());
        
        vector<int>less(10,0);
        int it=0;
        for(int i=0;i<10;i++){
            while(it<digit.size() and digit[it]<=i) it++;
            less[i]=it;
        }

        int ans=0;
        for(int i=1;i<len;i++)
            ans+=(digits.size()-less[0])*pow((int)digits.size(),i-1);
         
        for(int i=0;i<len;i++){
            if(dig[i]==0){
                if(less[0]==0) return ans;
                continue;
            }
            if(pre[dig[i]]==0){
                ans+=(less[dig[i]-1-(i==0?pre[i]:0)]*pow((int)digits.size(),len-i-1));
                return ans;
            }
            ans+=(less[dig[i]-1-(i==0?pre[i]:0)]*pow((int)digits.size(),len-i-1));
        }
        return ans+1;
    }
};
