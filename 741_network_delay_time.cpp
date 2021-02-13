// solution1
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> net(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < times.size(); i++) {
            net[times[i][0] - 1][times[i][1] - 1] = times[i][2];
        }
        vector<int> stack;
        for (int i = 0; i < n; i++){
            if (net[k-1][i] != INT_MAX) {
                stack.push_back(i + 1);
            }
        }
        while (stack.empty() != true) {
            int l = stack[0];
            stack.erase(stack.begin());
            for (int i = 0; i < n; i++){
                if (net[l - 1][i] != INT_MAX) {
                    if (net[k - 1][i] > net[k - 1][l - 1] + net[l - 1][i]){
                        net[k - 1][i] = min(net[k - 1][i], net[k - 1][l - 1] + net[l - 1][i]);
                        stack.push_back(i + 1);
                    }
                }
            }
        }
        int max_time = 0;
        for (int i = 0; i < n; i++) {
            if (net[k - 1][i] > max_time && i != k - 1)
                max_time = net[k - 1][i];
        }
        return max_time == INT_MAX ? -1 : max_time;
    }
};

// // solution2 dijkstra
class Solution {
public:
    int findMinNode(vector<vector<int>>& net, vector<bool>& flag, int n, int k) {
        int min_time = INT_MAX;
        int min_index = -1;
        for (int i = 0; i < n; i++) {
            if (net[k - 1][i] < min_time && i != k - 1 && flag[i] == false) {
                min_time = net[k - 1][i];
                min_index = i + 1;                
            }
        }
        return min_index;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> net(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < times.size(); i++) {
            net[times[i][0] - 1][times[i][1] - 1] = times[i][2];
        }
        vector<bool> flag(n, false);
        flag[k - 1] = true;
        for (int l = findMinNode(net, flag, n, k); l != -1; l = findMinNode(net, flag, n, k)) {
            flag[l - 1] = true;
            for (int i = 0; i < n; i++){
                if (net[l - 1][i] != INT_MAX) {
                    net[k - 1][i] = min(net[k - 1][i], net[k - 1][l - 1] + net[l - 1][i]);
                }
            }
        }
        int max_time = 0;
        for (int i = 0; i < n; i++) {
            if (net[k - 1][i] > max_time && i != k - 1)
                max_time = net[k - 1][i];
        }
        return max_time == INT_MAX ? -1 : max_time;
    }
};