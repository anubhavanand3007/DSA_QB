#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
    int buy=prices[0], profit = prices[0]-buy;
    for(int i=0;i<prices.size();i++){
        buy = min(buy,prices[i]);
        profit = max(profit,prices[i]-buy);
    }
    return profit;
}

int solve(){
    vector<int> prices;
    int profit = maxProfit(prices);
    cout << profit;
}

int main(){
    solve();
    return 0;
}