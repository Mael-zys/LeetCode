class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> mx(stones.begin(),stones.end());
        while (mx.size() > 1) {
            int a = mx.top();
            mx.pop();
            int b = a - mx.top();
            mx.pop();
            if (b != 0 || mx.size() == 0) mx.push(b);
        }
        return mx.top();
    }
};