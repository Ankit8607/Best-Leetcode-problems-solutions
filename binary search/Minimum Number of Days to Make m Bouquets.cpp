// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/?envType=daily-question&envId=2024-06-19

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL*m*k>bloomDay.size()) return -1;
        int ans=0, l=0, r=1e9;
        while(l<=r){
            int mid=(l+r)/2;
            int cnt=0,streak=0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid) streak++;
                else streak=0;
                if(streak==k){
                    cnt++; 
                    streak=0;
                }
            }
            if(cnt>=m){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};


// In python 

// class Solution:
//     def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
//         if m*k > len(bloomDay): return -1
//         ans,l,r=0,0,1e9
//         while l<=r:
//             mid=int((l+r)/2)
//             cnt,streak=0,0
//             for i in range(len(bloomDay)):
//                 if bloomDay[i]<=mid: streak+=1
//                 else: streak=0
//                 if streak==k:
//                     cnt+=1 
//                     streak=0
//             if cnt>=m:
//                 ans=mid
//                 r=mid-1
//             else: l=mid+1
//         return int(ans)

// In javascript

// /**
//  * @param {number[]} bloomDay
//  * @param {number} m
//  * @param {number} k
//  * @return {number}
//  */
// var minDays = function(bloomDay, m, k) {
//     if(m*k>bloomDay.length) return -1;
//     let ans=0, l=0, r=1e9;
//     while(l<=r){
//         let mid=parseInt((l+r)/2);
//         console.log(mid);
//         let cnt=0,streak=0;
//         for(let i=0;i<bloomDay.length;i++){
//             if(bloomDay[i]<=mid) streak++;
//             else streak=0;
//             if(streak==k){
//                 cnt++; 
//                 streak=0;
//             }
//         }
//         if(cnt>=m){
//             ans=mid;
//             r=mid-1;
//         }
//         else l=mid+1;
//     }
//     return ans;
// };
