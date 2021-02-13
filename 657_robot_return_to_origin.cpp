class Solution {
public:
    bool judgeCircle(string moves) {
        if(moves.size() % 2 != 0) return false;
        int v = 0;
        int h = 0;
        for (int i = 0; i < moves.size(); i++ )
        {
            if (moves[i] == 'L') h--;
            else if (moves[i] == 'R') h++;
            else if (moves[i] == 'U') v++;
            else v--;
        }
        return (v == 0 && h == 0);
    }
};