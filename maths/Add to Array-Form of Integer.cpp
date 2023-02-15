// https://leetcode.com/problems/add-to-array-form-of-integer/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0,i=0;
        int n=num.size()-1;
        vector<int>ans;
        while(k){
            int t=k%10;
            k/=10;
            if(n<0){
                ans.push_back((carry+t)%10);
                carry=(carry+t)/10;
                continue;
            }
            ans.push_back((num[n]+carry+t)%10);
            carry=(num[n]+carry+t)/10;
            n--;
        }
        while(n>=0){
            ans.push_back((num[n]+carry)%10);
            carry=(num[n]+carry)/10;
            n--;
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
