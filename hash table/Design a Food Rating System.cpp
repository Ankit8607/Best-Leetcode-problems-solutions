// https://leetcode.com/problems/design-a-food-rating-system/description/?envType=daily-question&envId=2023-12-17

class FoodRatings {
public:
    map<string,set<pair<int,string>>>mp;
    map<string,string>f;
    map<string,int>rat;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++) 
            mp[cuisines[i]].insert({-ratings[i],foods[i]}),f[foods[i]]=cuisines[i],rat[foods[i]]=ratings[i];
    }
    
    void changeRating(string food, int newRating) {
        mp[f[food]].erase({-rat[food],food});
        rat[food]=newRating;
        mp[f[food]].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return mp[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
