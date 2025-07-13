class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end(), std::greater<>());
        sort(trainers.begin(), trainers.end(), std::greater<>());

        int max1 = 0;
        int max2 = 0;
        int j = 0;

        for (int i = 0; i < players.size(); i++) {
            while (j < trainers.size() && players.at(i) > trainers.at(j)) j++;
            if (j < trainers.size()) {
                max1++;
                j++;  
            } 
            else break;
        }

        j = 0;
        for (int i = 0; i < trainers.size(); i++) {
            while (j < players.size() && players.at(j) > trainers.at(i)) j++;
            if (j < players.size()) {
                max2++;
                j++;  
            } 
            else break;
        }

        return max(max1, max2);
    }
};
