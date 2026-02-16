class Solution {
public:
    int reverseBits(int n) {
        int res=0;
        for(int i=0;i<32;i++)
        {
            int dig=n&1;
            int shift=dig<<(31-i);
            res=res|shift;
            n=n>>1;
        }
        return res;
    }
};