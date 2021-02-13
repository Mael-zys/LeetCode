class Solution {
public:
    int subtractProductAndSum(int temp) {
        int sum = 0;
        int produit = 1;
        while (temp > 0) {
            sum += temp % 10;
            produit *= temp % 10;
            temp = temp / 10;
        }
        return produit - sum;
    }
};