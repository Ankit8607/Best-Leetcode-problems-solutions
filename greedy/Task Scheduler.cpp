// https://leetcode.com/problems/task-scheduler/description/?envType=daily-question&envId=2024-03-19

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>ch(26,0);
        for(auto i:tasks)
            ch[i-'A']++;
        int mx=0,cnt=0;
        for(auto i:ch){
            if(i>mx) mx=i,cnt=1;
            else if(i==mx) cnt++; 
        }
        n++;
        return cnt+max(n*mx-n,(int)tasks.size()-cnt);
    }
};



// In python

// class Solution:
//     def leastInterval(self, tasks: List[str], n: int) -> int:
//         ch=[0]*26
//         for i in tasks:
//             ch[ord(i[0])-ord('A')]+=1
//         mx,cnt=0,0
//         for i in ch:
//             if i>mx: 
//                 mx=i
//                 cnt=1
//             elif i==mx:
//                 cnt+=1
//         n+=1
//         return cnt+max(n*mx-n,len(tasks)-cnt)


// In javascript

// /**
//  * @param {character[]} tasks
//  * @param {number} n
//  * @return {number}
//  */
// var leastInterval = function(tasks, n) {
//     let ch=new Array(26).fill(0);
//     tasks.forEach((i) => {
//         ch[i.charCodeAt(0)-'A'.charCodeAt(0)]++;
//     });
//     let mx=0,cnt=0;
//     ch.forEach((i) =>{
//         if(i>mx) mx=i,cnt=1;
//         else if(i==mx) cnt++; 
//     });
//     n++;
//     return cnt+Math.max(n*mx-n,tasks.length-cnt);
// };
