#include <bits/stdc++.h>
using namespace std;

// Define your state type
struct State {
    vector<int> path; // example: partial solution
};

// Backtracking function
int backtrack(State &curr, const vector<int> &input) {
    // BASE CASE
    if (curr.path.size() == input.size()) {
        // modify the answer (e.g., print or count)
        for (int x : curr.path) cout << x << " ";
        cout << "\n";
        return 1; // one solution found
    }

    int ans = 0;
    // ITERATE_OVER_INPUT
    for (int i = 0; i < input.size(); i++) {
        // skip if already used
        if (find(curr.path.begin(), curr.path.end(), input[i]) != curr.path.end())
            continue;

        // modify the current state
        curr.path.push_back(input[i]);

        // recursive call
        ans += backtrack(curr, input);

        // undo the modification of the current state
        curr.path.pop_back();
    }

    return ans;
}

int main() {
    vector<int> input = {1, 2, 3};
    State start;
    int totalSolutions = backtrack(start, input);
    cout << "Total solutions: " << totalSolutions << "\n";
    return 0;
}