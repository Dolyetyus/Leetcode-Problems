class Solution {
public:
    int maxCoins(vector<int>& piles) {
        priority_queue<int> maxHeap(begin(piles), end(piles));

        int chosen = 0;
        int ret = 0;
        while (chosen < piles.size()){
            maxHeap.pop();
            ret+=maxHeap.top();
            maxHeap.pop();
            chosen+=3;
        }

        return ret;
    }
};
