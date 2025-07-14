#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];

        int max_customers = *max_element(A.begin(), A.end());
        int max_profit = 0;

        for (int x = 0; x <= max_customers; ++x) {
            int total_sold = 0;
            for (int i = 0; i < N; ++i) {
                total_sold += min(x, A[i]);
            }
            int profit = total_sold * 50 - x * 30 * N;
            if (profit > max_profit) max_profit = profit;
        }

        cout << max_profit << endl;
    }
    return 0;
}