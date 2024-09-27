class MyCalendarTwo {
public:
    vector<pair<int, int>> events;
    vector<pair<int, int>> doubleBooks;

    MyCalendarTwo(){}
    
    bool book(int start, int end) {
        for (auto& db : doubleBooks) {
            if (start < db.second && end > db.first) {
                return false;
            }
        }
        
        for (auto& event : events) {
            if (start < event.second && end > event.first) {
                doubleBooks.push_back({max(start, event.first), min(end, event.second)});
            }
        }
        
        events.push_back({start, end});
        return true;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
