#include <unordered_map>
#include <string>
#include <vector>
#include <set>
#include <utility>
using namespace std;

class FoodRatings {
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodCuisine;
    unordered_map<string, set<pair<int, string>>> cuisineFood;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            foodRating[foods[i]]=ratings[i];
            foodCuisine[foods[i]]=cuisines[i];
            cuisineFood[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine=foodCuisine[food];
        int oldRating=foodRating[food];
        cuisineFood[cuisine].erase({-oldRating, food});
        cuisineFood[cuisine].insert({-newRating, food});
        foodRating[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineFood[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */