class MyCalendar {
public:
    vector<int> starttime;
    vector<int> endtime;

    MyCalendar() {}
    
    bool book(int start, int end) {
        for (int i = 0; i<starttime.size(); i++){
            if (start < endtime.at(i) && end > starttime.at(i)) {
                return false;
            }
        }
        starttime.push_back(start);
        endtime.push_back(end);
        return true;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
