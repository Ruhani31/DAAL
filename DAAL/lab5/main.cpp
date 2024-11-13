#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_ITEMS = 10;  // Maximum number of items

struct Item {
    int value, weight;
    Item(int v = 0, int w = 0) : value(v), weight(w) {}  // Default constructor for compatibility
};

// Comparator function to sort items by value/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item items[], int n) {
    sort(items, items + n, compare);  // Sort items array by value/weight ratio

    double totalValue = 0.0;
    cout << "Iteration-wise details:\n";
    for (int i = 0; i < n; ++i) {
        if (W == 0) break;

        int takeWeight = min(items[i].weight, W);
        if (takeWeight == W) {
            cout << "Fraction: " << (float)W / items[i].weight << endl;
        }
        totalValue += takeWeight * ((double)items[i].value / items[i].weight);
        W -= takeWeight;

        // Display partial result at each iteration
        cout << "Taking weight: " << takeWeight
             << ", Total value so far: " << totalValue
             << ", Remaining capacity: " << W
             << endl;
    }

    return totalValue;
}

int main() {
    Item items[MAX_ITEMS] = { 
        Item(5, 1), Item(10, 3), Item(15, 5), Item(7, 4), 
        Item(8, 1), Item(9, 3), Item(4, 2)
    };
    int n = 7;  // Number of items
    int W = 15; // Capacity of knapsack
    
    cout << "Maximum value in Fractional Knapsack = " << fractionalKnapsack(W, items, n) << endl;
    return 0;
}
