class KthLargest {
public:
    int kth;
    priority_queue <int, vector<int>, greater<int>> pq; 

    KthLargest(int k, vector<int>& nums) {
        kth = k;
        
        for (int i = 0; i<nums.size(); i++){
            add(nums.at(i));
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        if (pq.size()>kth){
            pq.pop();
        }

        return pq.top();
    }
};
