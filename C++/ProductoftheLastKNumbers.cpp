class ProductOfNumbers {
public:
    vector<int> prefix = {1};
    int size = 0;

    ProductOfNumbers() {}
    
    void add(int num) {
        if (num==0){
            prefix.clear();
            size = 0;
            prefix.push_back(1);
        }
        else {
            prefix.push_back(prefix.at(size)*num);
            size++;
        }
    }
    
    int getProduct(int k) {
        if (k>size) return 0;
        return prefix.at(size)/prefix.at(size-k);
    }
};
