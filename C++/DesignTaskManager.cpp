class TaskManager {
public:
    priority_queue<pair<int, int>> heap; //pair<priority, id>
    map<int, pair<int, int>> metadata;   // map<id, pair<priority, userID>

    TaskManager(vector<vector<int>>& tasks) {
        for (vector<int> task: tasks) {
            heap.push({task.at(2), task.at(1)});
            metadata[task.at(1)] = {task.at(2), task.at(0)};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        heap.push({priority, taskId});
        metadata[taskId] = {priority, userId};
    }
    
    void edit(int taskId, int newPriority) {
        heap.push({newPriority, taskId});
        metadata[taskId].first = newPriority;
    }
    
    void rmv(int taskId) {
        metadata[taskId].first = -1;
    }

    int execTop() {
        if (heap.empty()) return -1;

        pair<int, int> top = heap.top(); heap.pop();
        int validPriority = metadata[top.second].first;

        while (validPriority != top.first) {
            if (validPriority != -1) {
                heap.push({validPriority, top.second});
            }
            if (heap.empty()) return -1;
            top = heap.top(); heap.pop();
            validPriority = metadata[top.second].first;
        }

        metadata[top.second].first = -1;

        return metadata[top.second].second;
    }
};
