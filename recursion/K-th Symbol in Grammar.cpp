// https://leetcode.com/problems/k-th-symbol-in-grammar/description/?envType=daily-question&envId=2023-10-25

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        int tot=(1<<(n-2));
        if(k>tot) return 1-kthGrammar(n-1,k-tot);
        return kthGrammar(n-1,k);
    }
};
