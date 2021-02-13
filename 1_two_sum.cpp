//using map to find the number (target-nums), here just 2 sum, so it's fine to use map

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> inputs;
        map<int, int>::iterator iter;
        for (int i = 0; i < nums.size(); i++){
            if (inputs.find(nums[i]) == inputs.end())
                inputs[nums[i]] = i;
            int diff = target - nums[i];
            iter = inputs.find(diff);
            if (iter != inputs.end() && iter->second != i)
                return {iter->second, i};
        }
        return {-1,-1};
    }
};