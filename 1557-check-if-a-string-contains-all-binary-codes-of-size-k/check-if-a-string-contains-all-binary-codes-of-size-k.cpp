class Solution {
public:
    bool hasAllCodes(string s, int k) {
        long long ans=1<<k;
        int n=s.size();
        unordered_set<string> sets;
        for(int i=0;i+k<=n;i++)
        {
            sets.insert(s.substr(i,k));
        }
        return sets.size()==ans;
    }
};