// https://leetcode.com/problems/can-place-flowers/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0,i=1;
        if(flowerbed.size()==1){
            if(flowerbed[0]==0) cnt++;
            return cnt>=n;
        }
        if(flowerbed[0]==0 and flowerbed[1]==0) flowerbed[0]=1, cnt++;
        while(i<flowerbed.size()){
            if(i==flowerbed.size()-1){
                if(flowerbed[i]==0 and flowerbed[i-1]==0) cnt++;
            }
            else{
                if(flowerbed[i]==0 and flowerbed[i-1]==0 and flowerbed[i+1]==0)
                    flowerbed[i]=1, cnt++;
            }
            i++;
        }
        return cnt>=n;
    }
};
