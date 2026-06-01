#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Puri string ko ulta (reverse) kar do
        reverse(s.begin(), s.end());
        
        int n = s.length();
        int idx = 0; // Yeh pointer processed string ki position track karega
        int i = 0;   // Yeh pointer input string ko scan karega
        
        while (i < n) {
            // Jab tak space hai, skip karte jao
            if (s[i] != ' ') {
                // Agar yeh pehla word nahi hai, toh ek single space manually add karo
                if (idx != 0) {
                    s[idx++] = ' ';
                }
                
                // Word ki starting position ko save kar lo
                int start = i;
                
                // Pure word ko utha kar idx waali position par copy karo
                while (i < n && s[i] != ' ') {
                    s[idx++] = s[i++];
                }
                
                // Jo word abhi idx ke peeche store hua hai, usko wapas reverse (seedha) karo
                // Word ki length thi (i - start)
                reverse(s.begin() + idx - (i - start), s.begin() + idx);
            }
            else {
                i++; // Agar space hai toh chupchaap aage badho
            }
        }
        
        // Faltu ki aakhri/trailing spaces ko remove karne ke liye string ko resize kar do
        s.erase(s.begin() + idx, s.end());
        
        return s;
    }
};