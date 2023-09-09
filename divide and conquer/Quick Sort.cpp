// https://practice.geeksforgeeks.org/problems/quick-sort/1

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low<high){
            int t=partition(arr,low,high);
            quickSort(arr,low,t-1);
            quickSort(arr,t+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int pivot=arr[high];
       int left=low,it=low;
       while(it<high){
           if(arr[it]<pivot) swap(arr[it],arr[left++]);
           it++;
       }
       swap(arr[left],arr[high]);
       return left;
    }
};
