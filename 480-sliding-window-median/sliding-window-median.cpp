class Solution {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    unordered_map<int,int> delayed;
    int smallsize=0,largesize=0;
    int k;

    void pruneSmall(){
        while(!small.empty()&&delayed[small.top()])
        {
            delayed[small.top()]--;
            small.pop();
        }
    }

    void pruneLarge(){
        while(!large.empty()&&delayed[large.top()])
        {
            delayed[large.top()]--;
            large.pop();
        }
    }

    void balance(){
        if(smallsize>largesize+1)
        {
            large.push(small.top());
            small.pop();
            smallsize--;
            largesize++;
            pruneSmall();
        }
        else if(smallsize<largesize)
        {
            small.push(large.top());
            large.pop();
            largesize--;
            smallsize++;
            pruneLarge();
        }
    }

    void add(int num)
    {
        if(small.empty()||num<=small.top())
        {
            small.push(num);
            smallsize++;
        }
        else
        {
            large.push(num);
            largesize++;
        }
        balance();
    }

    void remove(int num)
    {
        delayed[num]++;
       
        if(num<=small.top())
        smallsize--;
        else
        largesize--;
        if(!small.empty()&&num==small.top())
        pruneSmall();
        if(!large.empty()&&num==large.top())
        pruneLarge();
        balance();
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int K) {
        k=K;
        vector<double> ans;
        for(int i=0;i<k;i++)
        {
            add(nums[i]);
        }
        if(k%2)
        ans.push_back(small.top());
        else
        ans.push_back(((double)small.top()+large.top())/2.0);
        for(int i=k;i<nums.size();i++)
        {
            remove(nums[i-k]);
            add(nums[i]);
            if(k%2)
            ans.push_back(small.top());
            else
            ans.push_back(((double)small.top()+large.top())/2.0);
        }
        return ans;
    }
};