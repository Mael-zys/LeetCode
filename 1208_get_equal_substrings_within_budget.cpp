// sliding window

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost=0;
        int num=0;
        int l = 0;
        for (int r = 0 ; r < s.size(); r++)
        {
            cost += abs(s[r] - t[r]);
            while (cost > maxCost)
            {
                cost -= abs(s[l] - t[l]);
                l++;
            }    
            num = max(num, r - l + 1);    
        }
        return num;
    }
};