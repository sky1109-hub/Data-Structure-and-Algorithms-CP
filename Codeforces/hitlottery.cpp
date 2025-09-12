#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCoinsGreedy(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend()); 
    int count = 0;
    for (int c : coins) {
        count += amount / c;
        amount %= c;
    }
    return amount == 0 ? count : -1;
}

int main() {
    vector<int> coins = {1, 5,10,20,100};
    int amount ;
    cin>>amount;

    int result = minCoinsGreedy(coins, amount);
    cout<< result << "\n";

    return 0;
}
