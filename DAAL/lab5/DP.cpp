#include <iostream>
using namespace std;

const int MAX_ITEMS = 10;  // Maximum number of items
const int MAX_CAPACITY = 50;  // Maximum knapsack capacity

struct Item {
    int value, weight;
    Item(int v = 0, int w = 0) : value(v), weight(w) {}  // Default constructor for compatibility
};

int knapsackDP(int W, Item items[], int n) {
    int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1] = {0};  // DP table with default values 0

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Printing DP Table
    cout << "\nDP Table (Rows = Items, Columns = Capacity):\n";
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            cout << dp[i][w] << "\t";
        }
        cout << "\n";
    }

    return dp[n][W];
}

int main() {
    Item items[MAX_ITEMS] = {
        Item(5, 1), Item(10, 3), Item(15, 5), Item(7, 4),
        Item(8, 1), Item(9, 3), Item(4, 2)
    };
    int n = 7;  // Number of items
    int W = 15; // Capacity of knapsack

    int maxValue = knapsackDP(W, items, n);

    cout << "\nMaximum value in 0/1 Knapsack = " << maxValue << endl;
    return 0;
}
