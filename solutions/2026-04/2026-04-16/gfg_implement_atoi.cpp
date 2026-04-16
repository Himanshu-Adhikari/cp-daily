class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // 1. Skip whitespaces
        while (i < n && s[i] == ' ') i++;

        // 2. Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Convert digits
        long long res = 0;
        while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');

            // 4. Handle overflow
            if (sign * res >= INT_MAX) return INT_MAX;
            if (sign * res <= INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * res);
    }
};