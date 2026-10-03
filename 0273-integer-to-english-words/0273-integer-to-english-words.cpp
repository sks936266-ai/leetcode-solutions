class Solution {
public:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                           "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
                           "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty",
                           "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> units = {"", "Thousand", "Million", "Billion"};

    string threeDigits(int n) {
        if (n == 0) return "";
        if (n < 20) return ones[n] + " ";
        if (n < 100) return tens[n / 10] + " " + threeDigits(n % 10);
        return ones[n / 100] + " Hundred " + threeDigits(n % 100);
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string result = "";
        int i = 0;

        while (num > 0) {
            int chunk = num % 1000;
            if (chunk != 0) {
                string part = threeDigits(chunk);
                if (!units[i].empty()) part += units[i] + " ";
                result = part + result;
            }
            num /= 1000;
            i++;
        }

        while (!result.empty() && result.back() == ' ') result.pop_back();
        return result;
    }
};