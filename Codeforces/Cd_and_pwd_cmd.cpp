#include <bits/stdc++.h>
using namespace std;

stack<string> st;

void printPath()
{
    if (st.empty())
    {
        cout << "/"<<endl;
        return;
    }
    string ans = "";
    stack<string> x = st;
    while (!x.empty())
    {
        ans = "/" + x.top() + ans;
        x.pop();
    }
    cout  << ans <<"/"<< "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();

    while (n--)
    {
        string s;
        getline(cin, s);

        if (s == "pwd")
        {
            printPath();
        }
        else
        {
          
            s = s.substr(3);

           
            if (!s.empty() && s[0] == '/')
            {
                while (!st.empty()) st.pop();
                s = s.substr(1);
            }

            string cur;
            stringstream ss(s);

            while (getline(ss, cur, '/'))
            {
                if (cur == "" || cur == " ")
                    continue;

                if (cur == "..")
                {
                    if (!st.empty()) st.pop();
                }
                else
                {
                    st.push(cur);
                }
            }
        }
    }
    return 0;
}
