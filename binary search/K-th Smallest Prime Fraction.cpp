// https://leetcode.com/problems/k-th-smallest-prime-fraction/description/?envType=daily-question&envId=2024-05-10

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int>res(2); 
        double l=0,r=1;
        int n = arr.size();
        while(l<=r){
            double mid=(l+r)/2;
            int j=1,total=0;
            res[0]=0,res[1]=1;
            for(int i=0;i<n;i++){
                while(j<n and arr[i]>=arr[j]*mid) j++;
                total+=n-j;
                if(j<n and res[0]*1.0/res[1] < arr[i]*1.0/arr[j]) res={arr[i],arr[j]};
            }
            if(total==k) break;
            if(total<k) l=mid;
            else r=mid;
            cout<<mid<<endl;
        }
        return res;
    }
};
