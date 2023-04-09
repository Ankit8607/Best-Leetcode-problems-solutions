// https://leetcode.com/problems/make-number-of-distinct-characters-equal/

class Solution {
public:
    bool isItPossible(string word1, string word2)  {
        set<char>a,b;
        int arr[26]={0},brr[26]={0};
        for(char &i:word1) a.insert(i),arr[i-'a']++; 
        for(char &i:word2) b.insert(i),brr[i-'a']++; 
        int n=a.size(),m=b.size();
        if(m>n){
            swap(n,m);
            swap(arr,brr);
        }

        if(n==m){
            int b1=0,b2=0,b3=0,b4=0;
            for(int i=0;i<26;i++){
                if(arr[i] and brr[i]) return 1;
                if(arr[i]==1) b1=1;
                if(brr[i]==1) b2=1;
                if(arr[i]>1 and brr[i]==0) b3=1;
                if(brr[i]>1 and arr[i]==0) b4=1;
            }
            if((b1 and b2) || (b3 and b4)) return 1;
            return 0;
        }
        else if(n-m>2) return 0;
        else if(n-m==2){
            int b1=0,b2=0,b3=0;
            for(int i=0;i<26;i++){
                if(arr[i]==1 and brr[i]==0) b1=1;
                if(brr[i]>1 and arr[i]>0) b2=1;
                if(brr[i]>1 and arr[i]>=1) b3=1;
            }
            if(b1 and b2 and b3) return 1;
            return 0;
        }
        else{
            int b1=0,b2=0,b3=0;
            for(int i=0;i<26;i++){
                if(arr[i]>1 and brr[i]==0) b1=1;
                if(brr[i]>1 and arr[i]>=1) b3=1;
                if(brr[i]>=1 and arr[i]==1) b2=1;
            }
            cout<<b1<<b2<<b3;
            if((b1 || b2) and b3) return 1;
            return 0;
        }
        return 0;
    }
};
