class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int minPrice = INT_MAX;
        int secMinPrice = INT_MAX;
        for (int price : prices) {
            if (price < minPrice) {
                secMinPrice = minPrice;
                minPrice = price;
            } else if (price < secMinPrice) {
                secMinPrice = price;
            }
        }
        int totalCost = minPrice + secMinPrice;
        if (totalCost <= money) {
            return money - totalCost;
        }
        
        return money;
    }
};