class CustomStack {
public:
    int max;
    int arrSize = 0;
    vector<int> arr;

    CustomStack(int maxSize):
        max(maxSize){}
    
    void push(int x) {
        if (max == arrSize){
            return;
        }
        arr.push_back(x);
        arrSize++;
    }
    
    int pop() {
        if (arrSize == 0){
            return -1;
        }
        int ret = arr.at(arrSize-1);
        arrSize--;
        arr.pop_back();
        return ret;
    }
    
    void increment(int k, int val) {
        int i = 0;
        while (k>0){
            if (i==arrSize) break;
            arr.at(i)+=val;
            i++;
            k--;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
