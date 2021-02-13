class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> index;
        for(int i = 0; i < arr.size(); i++)
            index[arr[i]] = i;
        unordered_map<int, int> num;
        int ans = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if ( (arr[i] - arr[j]) < arr[j] && index.count(arr[i] - arr[j]))
                {
                    int k = index[arr[i] - arr[j]];
                    num[j * arr.size() + i] = num[k * arr.size() + j] + 1;
                    ans = max(ans, num[j * arr.size() + i] + 2);
                }
            }
        }
        return ans >= 3 ? ans : 0;
        
    }
};