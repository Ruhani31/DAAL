#include <iostream>
#include <queue>

using namespace std;

#define MAX_FILES 100  // Define the maximum number of files

int optimalMerge(int files[], int n) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // Push all file sizes into the min heap
    for (int i = 0; i < n; ++i) {
        minHeap.push(files[i]);
    }
    
    int totalCost = 0;
    int iteration = 1;

    while (minHeap.size() > 1) {
        int first_smallest = minHeap.top();
        minHeap.pop();
        int second_smallest = minHeap.top();
        minHeap.pop();

        int merge_cost = first_smallest + second_smallest;
        totalCost += merge_cost;

        minHeap.push(merge_cost);

        cout << "Iteration " << iteration++ << ":\n";
        cout << "  Merging files of size " << first_smallest << " and " << second_smallest 
             << " -> Cost: " << merge_cost << endl;
        cout << "  Current total cost: " << totalCost << endl;

        priority_queue<int, vector<int>, greater<int>> tempHeap = minHeap;
        cout << "  Heap state: ";
        while (!tempHeap.empty()) {
            cout << tempHeap.top() << " ";
            tempHeap.pop();
        }
        cout << "\n\n";
    }

    return totalCost;
}

int main() {
    int n;
    cout << "Enter the number of files: ";
    cin >> n;

    if (n <= 0 || n > MAX_FILES) {
        cout << "Number of files must be a positive integer and less than or equal to " << MAX_FILES << "." << endl;
        return 1;
    }

    int files[MAX_FILES];
    
    cout << "Enter the sizes of the " << n << " files separated by spaces:\n";
    for(int i = 0; i < n; ++i) {
        cin >> files[i];
        if(files[i] <= 0) {
            cout << "File sizes must be positive integers." << endl;
            return 1; 
        }
    }

    int cost = optimalMerge(files, n);
    cout << "Total cost for optimal merge: " << cost << endl;

    return 0;
}
