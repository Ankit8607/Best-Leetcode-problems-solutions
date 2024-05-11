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


// In python

// class Solution:
//     def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
//         res = [0,1]
//         l,r=0.0,1.0
//         n = len(arr)
//         while l<=r:
//             mid=(l+r)/2.0
//             j,total=1,0
//             res[0]=0
//             res[1]=1
//             for i in range(n):
//                 while j<n and arr[i]>=arr[j]*mid: j+=1
//                 total+=n-j
//                 if j<n and res[0]*1.0/res[1] < arr[i]*1.0/arr[j]: res=[arr[i],arr[j]]
//             if total==k: break
//             if total<k: l=mid
//             else: r=mid
//         return res

// In javascript

// /**
//  * @param {number[]} arr
//  * @param {number} k
//  * @return {number[]}
//  */
// var kthSmallestPrimeFraction = function(arr, k) {
//     res=[0,1]; 
//     let l=0.0,r=1.0;
//     let n = arr.length;
//     while(l<=r){
//         let mid=(l+r)/2;
//         let j=1,total=0;
//         res[0]=0,res[1]=1;
//         for(let i=0;i<n;i++){
//             while(j<n && arr[i]>=arr[j]*mid) j++;
//             total+=n-j;
//             if(j<n && res[0]*1.0/res[1] < arr[i]*1.0/arr[j]) res=[arr[i],arr[j]];
//         }
//         if(total==k) break;
//         if(total<k) l=mid;
//         else r=mid;
//     }
//     return res;
// };
