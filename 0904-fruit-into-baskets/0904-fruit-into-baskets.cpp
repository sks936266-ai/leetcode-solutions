class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int left = 0;
        int max_fruits = 0;
        
        for (int right = 0; right < fruits.size(); ++right) {
            // Add current fruit to the basket
            basket[fruits[right]]++;
            
            // If we have more than 2 types of fruit, shrink the window
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            
            // Update the maximum number of fruits
            max_fruits = max(max_fruits, right - left + 1);
        }
        
        return max_fruits;
    }
};