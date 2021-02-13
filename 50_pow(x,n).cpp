class Solution {
public:
    double myPow(double x, long n) {
        if (n == 0) return 1;
        int flag = 0;
        if (n < 0) { 
            flag = 1;
            n = -n;
        }
        double pro = 1.0;
        double last = x;
        while (n != 0) {
            int r = n % 2;
            n = n / 2;
            if (r == 1) pro *= last;
            last = last * last;
        }
        return flag == 1 ? 1.0/pro: pro;
        
    }
};