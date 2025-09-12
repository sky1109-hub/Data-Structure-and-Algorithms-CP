#include <iostream>
#include <vector>
using namespace std;

void combnlsum(vector<int>& a, int t, vector<int>& temp)
{
    if (t < 0)
        return;
    if (t == 0)
    {
        cout << " { ";
        for (int i = 0; i < temp.size(); i++)
        {
            cout << temp[i] << " ";
        }
        cout << " }" << endl;
        return;
    }
    for (int i = 0; i < a.size(); i++)
    {
        temp.push_back(a[i]);
        combnlsum(a, t - a[i], temp);
        temp.pop_back(); 
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int t;
    cout << "target: ";
    cin >> t;

    vector<int> temp;
    combnlsum(a, t, temp);  
    return 0;
}
