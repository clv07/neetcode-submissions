class FoodRatings {
private:
    unordered_map<string, string> cuisineOf; // food -> cuisine
    unordered_map<string, int> ratingOf; // food -> rating
    unordered_map<string, set<pair<int, string>>> byCuisine; // cuisine -> (-rating, food)

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int size = foods.size();
        for (int i=0; i < size; i++) {
            cuisineOf[foods[i]] = cuisines[i];
            ratingOf[foods[i]] = ratings[i];
            byCuisine[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &st = byCuisine[cuisineOf[food]];
        st.erase({-ratingOf[food], food});
        st.insert({-newRating, food});
        ratingOf[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return byCuisine[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */