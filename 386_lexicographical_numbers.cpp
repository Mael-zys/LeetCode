// dfs by recursive
class Solution {
public:
    void recursive(int i, vector<int> &v, int n) {
        if (i > n) return;
        v.push_back(i);
        for (int j = 0; j <= 9; j++) {
            recursive(i * 10 + j, v, n);
        }
        return;
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        for (int i = 1; i <= 9; i++) {
            recursive(i, v, n);
        }
        return v;
    }
};

//dfs by stack
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        stack<int> s;
        vector<int> v;
        for (int i = 9; i > 0; i--) {
            if (i <= n) s.push(i);
        }
        while(!s.empty()) {
            int i = s.top();
            s.pop();
            v.push_back(i);
            for (int j = 9; j >= 0; j--) {
                if (i * 10 + j <= n)
                    s.push(i * 10 + j);
            }
        }
        return v;
    }
};