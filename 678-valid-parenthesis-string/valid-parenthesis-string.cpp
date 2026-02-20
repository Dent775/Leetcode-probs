class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        stack<int> star;
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if(c=='*')
            star.push(i);
            else if(c=='(')
            st.push(i);
            else
            {
                if(!st.empty())
                st.pop();
                else if(!star.empty())
                star.pop();
                else
                return false;
            }
        }
        while(!st.empty()&&!star.empty())
        {
            if(st.top()>star.top())
            return false;
            st.pop();
            star.pop();
        }
        return st.empty();
    }
};