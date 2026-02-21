class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<bool> sieve(33,true);
        sieve[0]=sieve[1]=false;
        for(int i=2;i*i<=32;i++)
        {
            if(sieve[i])
            {
                for(int j=i*i;j<=32;j+=i)
                sieve[j]=false;
            }
        }
        int ans=0;
        for(int i=left;i<=right;i++)
        {
            int count=__builtin_popcount(i);
            if(sieve[count])
            ans++;
        }
        return ans;
    }
};