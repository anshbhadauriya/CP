#include <bits/stdc++.h>
using namespace std;

bool canReduceToZero(vector<int>& p) {
    int n = p.size();
    int left = 0, right = n - 1;
    int current = 1; // start removing numbers from 1 to n
    
    while (current <= n) {
        if (p[left] == current) {
            left++;
        } else if (p[right] == current) {
            right--;
        } else {
            return false; // current number not at either end
        }
        current++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];

        if (canReduceToZero(p)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
