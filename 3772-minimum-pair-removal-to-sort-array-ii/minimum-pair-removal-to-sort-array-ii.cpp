class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        if(n<=0)
        return 0;
        vector<long long> val(n);
        vector<int> l(n),r(n);
        vector<char> alive(n,1);
        for(int i=0;i<n;i++)
        {
            val[i]=nums[i];
            l[i]=i-1;
            r[i]=i+1;
        }
        r[n-1]=-1;
        auto isBad=[&](int a,int b)->int{
            if(a==-1||b==-1)
            return 0;
            return val[a]>val[b];
        };
        int bad=0;
        for(int i=0;i<n-1;i++)
        {
            bad+=isBad(i,i+1);
        }
        if(bad==0)
        return 0;
        using t=pair<long long,int>;
        priority_queue<t,vector<t>,greater<t>> pq;
        
        auto push=[&](int i){
            if(i==-1)
            return;
            int j=r[i];
            if(j!=-1 && alive[i] && alive[j])
            pq.push({val[i]+val[j],i});
        };
        for(int i=0;i<n-1;i++)
        push(i);
        int count=0;
        while(bad>0)
        {
            int i;
            while(true)
            {
                auto[s,idx]=pq.top();
                pq.pop();
                i=idx;
                int j=(i==-1)?-1:r[i];
                if(i!=-1 && j!=-1 && alive[i] && alive[j] && val[i]+val[j]==s)
                break;
            }
             int j=r[i];
        int a=l[i];
        int b=r[j];

        bad-=isBad(a,i);
        bad-=isBad(i,j);
        bad-=isBad(j,b);

        val[i]=val[i]+val[j];
        alive[j]=0;

        r[i]=b;
        if(b!=-1)
        l[b]=i;

        bad+=isBad(a,i);
        bad+=isBad(i,b);

        push(a);
        push(i);
        count++;
        }
       return count;
    }
};
