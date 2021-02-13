//solution 1
class Solution {
public:
    
    unordered_map<int, vector<int> > S;
    
    vector<int> beautifulArray(int N) {
        if (N == 1) return (vector<int>){1};
        int leftN = (N + 1) / 2;
        int rightN = N / 2;
        vector<int> leftArray;
        vector<int> rightArray;
        if (S.count(leftN) == 0) 
        {
            leftArray = beautifulArray(leftN);
            S[leftN] = leftArray;
        }
        else
            leftArray = S[leftN];
        if (S.count(rightN) == 0) 
        {
            rightArray = beautifulArray(rightN);
            S[rightN] = rightArray;
        }
        else
            rightArray = S[rightN];
        vector<int> res;
        for (int i : leftArray)
            res.push_back(2 * i - 1);
        for (int i : rightArray)
            res.push_back(2 * i);
        return res;
    }
};

//solution 2
class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> result = {1};
        while(result.size()<N){
            vector<int> temp;
            for(int i : result)
                if(i*2-1 <= N)
                    temp.push_back(i*2-1);
            for(int i:result)
                if(i*2 <= N)
                    temp.push_back(i*2);
            
            result = temp;
            
        }
        return result;
    }
};