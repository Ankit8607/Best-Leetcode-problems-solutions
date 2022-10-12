// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    int kth(int a[], int m, int b[], int n, int k) {
        if (m < n) return kth(b,n,a,m,k);
        if (n==0) return a[k-1];
        if (k==1) return min(a[0],b[0]);

        int j = min(n,k/2);
        int i = k-j;
        if (a[i-1] > b[j-1]) return kth(a,i,b+j,n-j,k-j);
        return kth(a+i,m-i,b,j,k-i);
    }

    double findMedianSortedArrays(vector<int>&num1,vector<int>&num2) {
        int n=num2.size(),m=num1.size();
        if(n==0 and m==0) return 0;
        if(n==0){
            if(m%2) return (double) num1[m/2];
            else return (double) (num1[m/2]+num1[m/2-1])/2.0;
        }
        if(m==0){
            if(n%2) return (double) num2[n/2];
            else return (double) (num2[n/2]+num2[n/2-1])/2.0;
        }
        int b[n],a[m];
        for(int i=0;i<n;i++) b[i]=num2[i];
        for(int i=0;i<m;i++) a[i]=num1[i];
        int k = (m+n)/2;
        int m1 = kth(a,m,b,n,k+1);
        if ((m+n)%2==0) {
            int m2 = kth(a,m,b,n,k);
            return ((double)m1+m2)/2.0;
        }
        return m1;
    }
};
