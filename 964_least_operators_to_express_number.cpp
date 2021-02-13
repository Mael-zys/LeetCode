//solution 1 top down
class Solution {
public:
    unordered_map<long, int> temp;
    int leastOpsExpressTarget(int x, int target) {
        int r = (int)floor(log(target) / log(x));
        if (pow(x, r) == target) {
            temp[target] = r == 0 ? 1 : r - 1;
            return temp[target];
        }
        
        long diff1 = target - pow(x, r);
        if (temp.count(diff1) == 0)
            temp[diff1] = leastOpsExpressTarget(x, diff1);
        long diff2 = pow(x, r + 1) - target;
        if (diff2 < target && temp.count(diff2) == 0)
            temp[diff2] = leastOpsExpressTarget(x, diff2);
        if (diff2 < target) {
            temp[target] = r < 1 ? min(r + 2 + temp[diff1], r + 1 + temp[diff2]) : min(r + temp[diff1], r + 1 + temp[diff2]);
        }
        else {
            temp[target] =  r < 1 ? r + 2 + temp[diff1] : r + temp[diff1];
        }
        return temp[target];
    }
};

//solution 2  bottom up
class Solution {
public:
    int leastOpsExpressTarget(int x, int y) {
        int pos = 0, neg = 0, k, pos2, neg2, cur;
        for (k = 0; y > 0; ++k, y /= x) {
            cur = y % x;
            if (k > 0) {
                pos2 = min(cur * k + pos, (cur + 1) * k + neg);
                neg2 = min((x - cur) * k + pos, (x - cur - 1) * k + neg);
                pos = pos2, neg = neg2;
            } else {
                pos = cur * 2;
                neg = (x - cur) * 2;
            }
        }
        return min(pos, k + neg) - 1;
    }
};