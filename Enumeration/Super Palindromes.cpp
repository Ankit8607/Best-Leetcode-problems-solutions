// https://leetcode.com/problems/super-palindromes/

/*

Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.

Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].

 

Example 1:

Input: left = "4", right = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
Example 2:

Input: left = "1", right = "2"
Output: 1
 

Constraints:

1 <= left.length, right.length <= 18
left and right consist of only digits.
left and right cannot have leading zeros.
left and right represent integers in the range [1, 1018 - 1].
left is less than or equal to right.


*/

#define ll long long
vector<ll>arr;
class Solution {
public:

	void rec(int pos,int len,string s){
		if(pos>=(len+1)/2){
			arr.push_back(stol(s));
            return;
		}
		for(char i='0';i<='9';i++){
			if(pos==0 and i=='0') continue;
			s[pos]=i; s[len-pos-1]=i;
			rec(pos+1,len,s);
		}
	}

	bool is_palin(ll t){
		string s=to_string(t);
		for(int i=0;i<((int)s.size()+1)/2;i++){
			if(s[i]!=s[s.size()-i-1]) return false;
		}
		return 1;
	}

    int superpalindromesInRange(string left, string right) {
        ll l=stol(left),r=stol(right);
        for(int i=1;i<=10;i++){
			string s;
			for(int j=0;j<i;j++) s+='0';
			s[0]='1'; s[i-1]='1';
			rec(0,i,s);
		}
        // for(auto i:arr) cout<<i<<" ";
		int ans=0;
        int t=ceil(sqrt(l));
		int i=lower_bound(arr.begin(),arr.end(),t)-arr.begin();
		for(;arr[i]<sqrt(LONG_MAX) && arr.size();i++){
            if(1LL*arr[i]*arr[i]>r) break;
			if(is_palin(arr[i]*arr[i])) ans++;
		}
        return ans;
    }
};
