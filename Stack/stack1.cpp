#include <bits/stdc++.h>
using namespace std;
void insert(vector<int> &a)
{
    int x;
    cout << "enter the element";
    cin >> x;
    a.push_back(x);
}
void printdata(vector<int> &a)
{
    for (int i = a.size() - 1; i >= 0; i--)
    {
        cout << a[i];
        if (i != 0)
        {
            cout << " ";
        }
    }
    cout << endl;
}
void del(vector<int> &x)
{
    x.pop_back();
}
void top(vector<int> &x)
{
    cout << "Top Element is: " << x.back() << endl;
}
void isempty(vector<int> &a)
{
    if (a.size() == 0)
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "not Empty" << endl;
    }
}
int main()
{
    int l;
    cout << "Stack using Array " << endl;
    vector<int> a;
    while (1)
    {
        cout<<"Enter choice: ";
        cin >> l;
        switch (l)
        {
        case 1:

            insert(a);
            break;
        case 2:
            del(a);
            break;
        case 3:
            top(a);
            break;
        case 4:
            top(a);
            break;

        case 5:
            isempty(a);
            break;
            case 6:
          printdata(a);
            break;
        
        default:
        cout<<"Enter a better choice";
        exit(1);
        }
    }

    return 0;

}