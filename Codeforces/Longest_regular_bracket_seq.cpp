#include <bits/stdc++.h>
using namespace std;
stack<char> st;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    unordered_map<int, int> mp;
    int mans = 0, cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push('(');
        }
        else
        {
            if (s[i] == ')')
            {
                if (st.empty())
                {
                    mp[cnt]++;
                    mans = max(mans, cnt);
                    cnt = 0;
                }
                else
                {
                    st.pop();
                    cnt += 2;
                }
            }
        }
    }

    mp[cnt]++;
    mans = max(mans, cnt);
    cnt = 0;

    cout << mans << " " << (mans ? mp[mans] : 1) << endl;

    return 0;
}