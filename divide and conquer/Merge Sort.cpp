// https://practice.geeksforgeeks.org/problems/merge-sort/1

class Solution
{
    public:
    void merge(int arr[], int l, int mid, int r)
    {
        int tmp[r-l+1];
        int it=0,left=l,right=mid+1;
        while(left<=mid && right<=r){
            // if(left<=mid and (arr[left]<arr[right] || right>r)) tmp[it++]=arr[left++];
            if(arr[left]<arr[right]) tmp[it++]=arr[left++];
            else tmp[it++]=arr[right++];
        }
        while(left<=mid) tmp[it++]=arr[left++];
        while(right<=r) tmp[it++]=arr[right++];
        for(int i=l;i<=r;i++) arr[i]=tmp[i-l];
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r) return;
        
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};
