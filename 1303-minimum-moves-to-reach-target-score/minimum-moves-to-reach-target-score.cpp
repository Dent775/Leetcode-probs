class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count=0;
        if(maxDoubles==0)
        return target-1;
        while(target>1)
        {
            if(target&1)
            {
                target--;
                count++;
            }
            else
            {
                if(maxDoubles>0)
                {
                    target>>=1;
                    count++;
                    maxDoubles--;
                }
                else
                {
                    target--;
                    count++;
                }
            }
        }
        return count;
    }
};