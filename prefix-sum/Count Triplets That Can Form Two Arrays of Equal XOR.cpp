// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/?envType=daily-question&envId=2024-05-30

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size(),t=0;
        vector<int>x(n,0);
        for(int i=0;i<n;i++){
            t^=arr[i];
            x[i]=t;
        }
        int ans=0;
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                t=x[j-1]^(i==0?0:x[i-1]);
                for(int k=j;k<n;k++){
                    if(t==(x[k]^x[j-1]))
                        ans++;
                }
            }
        }
        return ans;
    }
};
