// https://leetcode.com/problems/reveal-cards-in-increasing-order/description/?envType=daily-question&envId=2024-04-10

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int>q;
        for(int i=deck.size()-1;i>=0;i--){
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
            q.push(deck[i]);
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};



// In python

// class Solution:
//     def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
//         deck.sort()
//         q = deque()
//         for i in range(len(deck) - 1, -1, -1):
//             if q:
//                 q.appendleft(q.pop())
//             q.appendleft(deck[i])
//         return list(q)


// In javascript

// /**
//  * @param {number[]} deck
//  * @return {number[]}
//  */
// var deckRevealedIncreasing = function(deck) {
//     deck.sort((a, b) => a - b);
//     const q = [];
//     for (let i = deck.length - 1; i >= 0; i--) {
//         if (q.length > 0) {
//             q.unshift(q.pop());
//         }
//         q.unshift(deck[i]);
//     }
//     return q;
// };
