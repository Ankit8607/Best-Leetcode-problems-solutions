// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/?envType=daily-question&envId=2024-05-11

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=wage.size(),sum=0;
        prop=[];
        priority_queue<int>small;
        
        for(int i=0;i<n;i++) prop.push_back((wage[i]*1.0/quality[i],quality[i]));
        sort(prop.begin(),prop.end());

        double ans=1e9;

        for(int i=0;i<n;i++){
            small.push(prop[i].second);
            sum+=prop[i].second;
            if(small.size()>k){
                sum-=small.top();
                small.pop();
            }
            if(small.size()==k) ans=min(ans,sum*prop[i].first);
        }
        return ans;
    }
};


// In python

// import queue
// class Solution:
//     def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
//         n,sum=len(wage),0
//         prop = [(wage[i]/quality[i], quality[i]) for i in range(n)]
//         prop.sort()
//         small=queue.PriorityQueue()
//         ans=1e9*1.0

//         for i in range(n):
//             small.put(-prop[i][1])
//             sum+=prop[i][1]
//             if small.qsize()>k:
//                 sum+=small.get()
//             if small.qsize()==k: ans=min(ans,sum*prop[i][0])

//         return ans
