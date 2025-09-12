#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while (1)
    {
        char c;
        cout << "Enter next char (use `?` to stop): ";
        cin >> c;
        if (c == '?')
        {
            break;
        }
        s += c;
    }

    unordered_map<char, int> precedence;
    precedence['^'] = 3;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['+'] = 1;
    precedence['-'] = 1;

    string ans = "";
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (isalnum(ch))  // operand (a-z, A-Z, 0-9)
        {
            ans += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();  // pop '('
        }
        else  // operator
        {
            while (!st.empty() && st.top() != '(')
            {
                char topOp = st.top();
                int precTop = precedence[topOp];
                int precCurr = precedence[ch];

                bool isRightAssoc = (ch == '^');
                if ((precTop > precCurr) || (precTop == precCurr && !isRightAssoc))
                {
                    ans += topOp;
                    st.pop();
                }
                else
                {
                    break;
                }
            }
            st.push(ch);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    cout << "Postfix: " << ans << endl;

    return 0;
}
