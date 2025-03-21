class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ret;
        unordered_set<string> hset;

        for (string supply: supplies) hset.insert(supply);

        int n = 100;   // 1000 IQ move
        while (n>0) {
            for (int i = 0; i<recipes.size(); i++){
                bool valid = true;
                for (int x = 0; x<ingredients.at(i).size(); x++){
                    if (!hset.contains(ingredients.at(i).at(x))) {
                        valid = false;
                        break;
                    }
                }

                if (valid) hset.insert(recipes.at(i));
            }
            n--;
        }

        for (int i = 0; i<recipes.size(); i++){
            bool valid = true;
            for (int x = 0; x<ingredients.at(i).size(); x++){
                if (!hset.contains(ingredients.at(i).at(x))) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                hset.insert(recipes.at(i));
                ret.push_back(recipes.at(i));
            }
        }

        return ret;
    }
};
