#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

class Solution {
private:
    unordered_map<string, vector<int>> memo;

public:
    vector<int> diffWaysToEvaluate(string expression) {
        // Return memoized result if sub-expression was already solved
        if (memo.count(expression)) {
            return memo[expression];
        }

        vector<int> result;

        for (int i = 0; i < expression.length(); i++) {
            char op = expression[i];

            // Split when an operator is encountered
            if (op == '+' || op == '-' || op == '*') {
                string leftStr = expression.substr(0, i);
                string rightStr = expression.substr(i + 1);

                vector<int> leftResults = diffWaysToEvaluate(leftStr);
                vector<int> rightResults = diffWaysToEvaluate(rightStr);

                // Combine every pair of results from left and right parts
                for (int l : leftResults) {
                    for (int r : rightResults) {
                        if (op == '+') {
                            result.push_back(l + r);
                        } else if (op == '-') {
                            result.push_back(l - r);
                        } else if (op == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }

        // Base case: If string contains no operators, it's a single integer
        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        return memo[expression] = result;
    }

    vector<int> diffWaysToCompute(string expression) {
        return diffWaysToEvaluate(expression);
    }
};