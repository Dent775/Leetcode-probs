class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int arr1[26]={0};
        int arr2[26]={0};
        int arr3[26]={0};
        int arr4[26]={0};
        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            if(!(i&1))
            {
                arr1[s1[i]-'a']++;
                arr2[s2[i]-'a']++;
            }
            else
            {
                arr3[s1[i]-'a']++;
                arr4[s2[i]-'a']++;
            }
        }
        for(int i=0;i<26;i++)
        {
            if((arr1[i]!=arr2[i])||(arr3[i]!=arr4[i]))
            {
                return false;
            }
        }
        return true;
    }
};