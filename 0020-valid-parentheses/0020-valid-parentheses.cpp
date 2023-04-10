class Solution
{
public:
    bool isValid(string s)
    {
       
        stack<char> st;
        char a;
        for (int i = 0; i < s.size(); i++)
        {
            a= s[i];
            if (a == '[' || a == '{' || a == '(')
            {
                st.push(a);
            }
            else if (!st.empty())
            {
                if ((st.top() == '{' && a == '}') || (st.top() == '[' && a == ']') || (st.top() == '(' && a == ')'))
                {
                    st.pop();
                }
                else
                    return false;
            }

            else
                return false;
        }
        return st.empty();
    }
};