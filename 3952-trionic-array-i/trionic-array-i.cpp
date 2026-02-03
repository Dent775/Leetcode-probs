class Solution {
public:
    bool isTrionic(vector<int>& arr) {
        int n=arr.size();
        int p=0,q=0;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]>=arr[i+1])
            {
                break;
            }
            p=i+1;
        }
        if(p>=n-2||p==0)
        return false;
        q=p;
        for(int i=p;i<n-1;i++)
        {
            if(arr[i]<=arr[i+1])
            break;
            q=i+1;
        }
        if(q>=n-1||p==q)
        return false;
        for(int i=q;i<n-1;i++)
        {
            if(arr[i]>=arr[i+1])
            return false;
        }
        return true;
    }
};