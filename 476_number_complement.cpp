class Solution {
public:
    int findComplement(int num) {
        int Complement = 0;
        int i = 0;
        while (num != 0) {
            Complement += num % 2 == 0 ? pow(2, i) : 0;
            i++;
            num /= 2;
        }
        return Complement;
    }
};