class NumberContainers {
public:
    unordered_map<int, set<int>> nums;
    unordered_map<int, int> index_map;
    
    NumberContainers() {}
    
    void change(int index, int number) {
        if (index_map[index]) {
            nums[index_map[index]].erase(index);
        }
        nums[number].insert(index);
        index_map[index] = number;
    }
    
    int find(int number) {
        if (!nums[number].empty()) return *nums[number].begin();
        return -1;
    }
};
