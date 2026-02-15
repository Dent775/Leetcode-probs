class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int carry=0;
        int diff=abs((int)a.size()-(int)b.size());
        string add="";
        for(int i=0;i<diff;i++)
        add+='0';
        if(a.size()<b.size())
        a=add+a;
        else
        b=add+b;
        int size=a.size();
        for(int i=size-1;i>=0;i--)
        {
            int diga=a[i]-'0';
            int digb=b[i]-'0';
            int sum=diga+digb+carry;
            res+=(sum%2)?'1':'0';
            carry=sum/2;
        }
        if(carry==1)
        res+='1';
        reverse(res.begin(),res.end());
        return res;
    }
};