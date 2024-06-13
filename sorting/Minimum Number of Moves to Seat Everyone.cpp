// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/?envType=daily-question&envId=2024-06-13


class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int ans=0;
        for(int i=0;i<seats.size();i++)
            ans+=abs(seats[i]-students[i]);
        return ans;
    }
};


// In python 

// class Solution:
//     def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
//         seats.sort()
//         students.sort()
//         ans=0
//         for i in range(0,len(seats)):
//             ans+=abs(seats[i]-students[i]);
//         return ans


// In javascript

// /**
//  * @param {number[]} seats
//  * @param {number[]} students
//  * @return {number}
//  */
// var minMovesToSeat = function(seats, students) {
//     seats.sort(function(a, b){return a - b});
//     students.sort(function(a, b){return a - b});
//     let ans=0;
//     for(let i=0;i<seats.length;i++)
//         ans+=Math.abs(seats[i]-students[i]);
//     return ans;
// };
