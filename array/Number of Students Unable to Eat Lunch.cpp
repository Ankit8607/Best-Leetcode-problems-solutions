// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/?envType=daily-question&envId=2024-04-08

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ones=accumulate(students.begin(),students.end(),0);
        int zeros=students.size()-ones;
        for(auto i:sandwiches){
            if(i){
                if(ones) ones--;
                else return ones+zeros;
            }
            else{
                if(zeros) zeros--;
                else return ones+zeros;
            }
        }
        return 0;
    }
};


// In python

// class Solution:
//     def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
//         ones=sum(students)
//         zeros=len(students)-ones
//         for i in sandwiches:
//             if i:
//                 if ones:
//                     ones-=1
//                 else: 
//                     return ones+zeros
//             else:
//                 if zeros:
//                     zeros-=1
//                 else:
//                     return ones+zeros
//         return 0


// In javascript

// /**
//  * @param {number[]} students
//  * @param {number[]} sandwiches
//  * @return {number}
//  */
// var countStudents = function(students, sandwiches) {
//     let ones=0;
//     students.forEach(x=>{
//         ones+=x;
//     });
//     let zeros=students.length-ones;
//     for(let i of sandwiches){
//         if(i){
//             if(ones) ones--;
//             else return ones+zeros;
//         }
//         else{
//             if(zeros) zeros--;
//             else return ones+zeros;
//         }
//     }
//     return 0;
// };
