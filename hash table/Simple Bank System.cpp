// https://leetcode.com/problems/simple-bank-system/

class Bank 
{
    public:
    map<int,long long>mp;
    int n;
    //this map will going to store all the account and their repective balance's
    Bank(vector<long long>& balance) 
    {
        n = balance.size();
        for(int i=0;i<(balance.size());i++)
        {
            mp[i+1] = balance[i];
        }
     }
        
    bool transfer(int account1, int account2, long long money) 
    {
        //if either of the account is not valid then just return false
        if(account1<1 or account1>n or account2<1 or account2>n)
        return false;
        //checking if the money can be transferred from account1 or not
        //if we need to transfer the money form account1 to account2 then
        //acouunt1 must have bal>= money

        if(mp[account1] >= money)
        {
            mp[account1] = mp[account1] - money;
            mp[account2] = mp[account2] + money;
            return true;
        }
        else
        {
            return false;
        }
        return false;   //unreachble code
    }
        
    bool deposit(int account, long long money) 
    {
        //if the account is not valid to deposit the money then return false
        if(account<1 or account>n)
        return false;
        
        mp[account] = mp[account] + money;
        return true;
    }
        
    bool withdraw(int account, long long money) 
    {
        //if the account is not valid to withdraw the money then return false
        if(account<1 or account>n)
        return false;
        
        //if the account is valid but does not have sufficient baclance then return false
        if(mp[account] < money)
        return false;
        
        mp[account] = mp[account] - money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
