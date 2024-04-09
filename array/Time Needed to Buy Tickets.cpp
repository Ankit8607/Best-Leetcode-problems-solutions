// https://leetcode.com/problems/time-needed-to-buy-tickets/description/?envType=daily-question&envId=2024-04-09class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0;
        for(int i=0;i<tickets.size();i++){
            ans+=min(tickets[k],tickets[i]);
            if(i==k) tickets[i]--;
        }
        return ans;
    }
};


In python

class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        ans=0
        for i in range(len(tickets)):
            ans+=min(tickets[k],tickets[i])
            if(i==k):
                tickets[i]-=1
        return ans


In javascript

/**
 * @param {number[]} tickets
 * @param {number} k
 * @return {number}
 */
var timeRequiredToBuy = function(tickets, k) {
    let ans=0;
    for(let i=0;i<tickets.length;i++){
        ans+=Math.min(tickets[k],tickets[i]);
        if(i==k) tickets[i]--;
    }
    return ans;
};
