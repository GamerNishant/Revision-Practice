#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


// Function to calculate the minimum cost to make pod counts pairwise distinct
int getMinCost(vector<int>& pods, vector<int>& cost) {
    int n = pods.size();
    vector<pair<int, int>> pod_cost_pairs;

    // Create pairs of (pods[i], cost[i]) and sort based on pods[i] and cost[i]
    for (int i = 0; i < n; ++i) {
        pod_cost_pairs.push_back({pods[i], cost[i]});
    }

    // Sort based on pod counts, and if pod counts are equal, sort by cost
    sort(pod_cost_pairs.begin(), pod_cost_pairs.end());

    int total_cost = 0;

    for(auto v : pod_cost_pairs) cout << v.first << ',' << v.second << endl;

    // Iterate through the pods to make them distinct
    for (int i = 1; i < n; ++i) {
        if (pod_cost_pairs[i].first <= pod_cost_pairs[i - 1].first) {
            int increment = pod_cost_pairs[i - 1].first - pod_cost_pairs[i].first + 1;
            total_cost += increment * pod_cost_pairs[i-1].second;
            pod_cost_pairs[i].first += increment;
        }
    }

    return total_cost;
}

int main() {
    // Example input
    int n = 5;
    vector<int> pods = {5, 2, 5, 3, 3};
    vector<int> cost = {3, 7, 8, 6, 9};

    int result = getMinCost(pods, cost);

    cout << "Minimum cost: " << result << endl;

    return 0;
}
