class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int current = 9999999;

        for (int price: prices){
            if (price<current) current = price;

            if (price-current > max_profit) max_profit=price-current;
        }

        return max_profit;
    }
};
