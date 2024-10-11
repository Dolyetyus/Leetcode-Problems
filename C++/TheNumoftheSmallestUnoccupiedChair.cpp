class Solution {
public:
    // bro wtf is this problem
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        for (int i = 0; i < times.size(); i++) {
            times[i].push_back(i);
        }

        sort(times.begin(), times.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        using Event = pair<int, int>;
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        priority_queue<Event, vector<Event>, greater<Event>> occupiedChairs;

        for (int i = 0; i < times.size(); i++) {
            availableChairs.push(i);
        }

        for (const auto& time : times) {
            int arrivalTime = time[0];
            int departureTime = time[1];
            int friendIndex = time[2];

            while (!occupiedChairs.empty() && occupiedChairs.top().first <= arrivalTime) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }

            int chosenChair = availableChairs.top();
            availableChairs.pop();

            if (friendIndex == targetFriend) {
                return chosenChair;
            }

            occupiedChairs.emplace(departureTime, chosenChair);
        }

        return -1;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
