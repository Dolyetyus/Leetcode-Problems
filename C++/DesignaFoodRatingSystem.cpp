class FoodRatings {
public:
    struct Compare {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first == b.first) return a.second > b.second; 
            return a.first < b.first; 
        }
    };

    map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, Compare>> hmap;
    map<string, string> foodToCuisine;
    map<string, int> foodToRating;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i<foods.size(); i++){
            hmap[cuisines[i]].push({ratings[i], foods[i]});
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        foodToRating[food] = newRating;
        hmap[cuisine].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto& pq = hmap[cuisine];
        while (!pq.empty()) {
            auto top = pq.top();
            if (foodToRating[top.second] == top.first) return top.second;
            pq.pop();
        }
        return "";
    }
};
