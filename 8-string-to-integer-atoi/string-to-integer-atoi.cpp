class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int flag = 0;
        int started = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ' && started == 0) continue;

            if (started == 0 && s[i] == '-') {
                flag = 1;
                started = 1;
                continue;
            }

            if (started == 0 && s[i] == '+') {
                started = 1;
                continue;
            }

            if (s[i] < '0' || s[i] > '9') break;

            started = 1;
            int digit = s[i] - '0';
            ans = ans * 10 + digit;

            if (flag == 0 && ans > INT_MAX) return INT_MAX;
            if (flag == 1 && ans > 2147483648LL) return INT_MIN;
        }

        if (flag == 1) ans = -ans;
        return (int)ans;
    }
};