#include <bits/stdc++.h>
using namespace std;

double sortSolution(vector<int> profits, vector<int> weights, int maxWeight) {
    int n = profits.size();
    vector<tuple<int, int, double>> v;

    for(int i = 0; i < n; i++) {
        v.push_back({ profits[i], weights[i], (double) profits[i] / weights[i] });
    }

    sort(v.begin(), v.end(), [](auto a, auto b) {
        return get<2>(a) > get<2>(b);
    });

    double maxProfit = 0;
    for(int i = 0; i < n && maxWeight > 0; i++) {
        auto [profit, weight, profPerWeight] = v[i];
        
        if(maxWeight >= weight) {
            maxWeight -= weight;
            maxProfit += profit;
        } else {
            maxProfit += profPerWeight * maxWeight;
            maxWeight  = 0;
        }
    } 

    return maxProfit;
}

double pqSolution(vector<int> profits, vector<int> weights, int maxWeight) {
    int n = profits.size();
    auto cmp = [](auto a, auto b) {
        return get<2>(a) < get<2>(b);
    };
    
    priority_queue<
        tuple<int, int, double>,
        vector<tuple<int, int, double>>,
        decltype(cmp)
    > pq(cmp);
    
    for(int i = 0; i < n; i++) {
        pq.push({ profits[i], weights[i], (double) profits[i] / weights[i] });
    }
    
    double maxProfit = 0;
    while(!pq.empty() && maxWeight > 0) {
        auto [profit, weight, profitPerWeight] = pq.top(); pq.pop();
        
        if(maxWeight >= weight) {
            maxWeight -= weight;
            maxProfit += profit;
        } else {
            maxProfit += profitPerWeight * maxWeight;
            maxWeight  = 0;
        }
    }
    
    return maxProfit;
}

int main() {
    vector<int> profits = {12, 17, 9, 7, 5, 21, 8};
    vector<int> weights = {2 , 5 , 7, 3, 1, 4 , 1};
    int maxWeight       = 15;

    cout << "KnapSack-Fraction Selection Based on Pi / Wi" << endl;
    cout << "=====================================================" << endl;

    cout << "Maximum Profit Using Sort: " << sortSolution(profits, weights, maxWeight) << endl;
    cout << "Maximum Profit Using PQ  : " << pqSolution(profits, weights, maxWeight) << endl;

    return 0;
}