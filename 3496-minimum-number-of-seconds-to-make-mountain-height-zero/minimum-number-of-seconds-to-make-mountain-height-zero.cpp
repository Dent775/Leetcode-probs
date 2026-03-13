class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long ans=0;
        using t=tuple<long long,long long,long long>;
        priority_queue<t,vector<t>,greater<t>> pq;
        for(int i=0;i<workerTimes.size();i++)
        {
            pq.push({workerTimes[i],workerTimes[i],1});
        }
        while(!pq.empty())
        {
            auto[time,wt,k]=pq.top();
            pq.pop();
            mountainHeight--;
            ans=max(ans,time);
            if(mountainHeight<=0)
            return ans;
            ++k;
            long long newTime=time+wt*k;
            pq.push({newTime,wt,k});
        }
        return 0;
    }
};