// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.

// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

// The number of ways decoding "12" is 2.

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0) return 0;
        if(s[0] == '0') return 0;
        int a = 1, b = 1, c = 1;
        for(int i = 1; i < n; ++i) {
            if(s[i-1] == '1') {
                if(s[i] == '0') {
                    c = a;
                } else {
                    c = a+b;
                }
            } else if(s[i-1] == '2') {
                if(s[i] == '0') {
                    c = a;
                } else if(s[i] <= '6') {
                    c = a+b;
                } else {
                    c = b;
                }
            } else {
                if(s[i] == '0') {
                    return 0;
                } else {
                    c = b;
                }
            }
            a = b;
            b = c;
        }
        return c;
    }
};
