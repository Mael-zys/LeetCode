//using INT_MAX and INT_MIN to see if the integer is in the 32-bit integer range.

class Solution {
public:
    int reverse(int x) {
        int r = 0;
        int g = 0;
        while (x != 0) {
            g = x % 10;
            x = x / 10;
            if (r > INT_MAX / 10 || (r == INT_MAX / 10 && g > INT_MAX % 10)) return 0;
            if (r < INT_MIN / 10 || (r == INT_MIN / 10 && g < INT_MIN % 10)) return 0;
            r =  10 * r + g;
        }
        return r;
    }
};