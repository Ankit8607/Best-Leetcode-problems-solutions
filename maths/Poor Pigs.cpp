// https://leetcode.com/problems/poor-pigs/?envType=daily-question&envId=2023-10-29

class Solution
{
    public:
     int poorPigs(int buckets, int time_to_die, int time_to_test)
    {
        int test = time_to_test/time_to_die;
        int i=0;
        while(pow(test+1,i)< buckets)
        {
            i++;
        }
        return i;
    }
};
