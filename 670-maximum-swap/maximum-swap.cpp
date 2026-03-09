class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int digit[10]={0};
        for(int i=0;i<s.size();i++)
        {
            digit[s[i]-'0']=i;
        }
        for(int i=0;i<s.size();i++)
        {
            for(int j=9;j>s[i]-'0';j--)
            {
                if(digit[j]>i)
                {
                    swap(s[digit[j]],s[i]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};