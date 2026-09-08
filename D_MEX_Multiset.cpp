#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    string output;
    output.reserve(1 << 20);

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        unordered_map<int,int> freq;
        freq.reserve(n * 2);
        for (int x : a) freq[x]++;

        auto getFreq = [&](int v) -> int {
            auto it = freq.find(v);
            return it == freq.end() ? 0 : it->second;
        };

        int c0 = getFreq(0);

        if (c0 == 1) {
            output += "NO\n";
        } else if (c0 == 0) {
            output += "YES\n";
            output.append(n, 'A');
            output += '\n';
        } else {
            // find M2 = largest value such that freq[v] >= 2 for all v < M2
            int v = 0;
            while (getFreq(v) >= 2) v++;
            int M2 = v;

            string result(n, 'C');
            unordered_map<int,int> assigned;
            assigned.reserve(M2 * 2 + 4);

            for (int i = 0; i < n; i++) {
                int val = a[i];
                if (val < M2) {
                    int c = assigned[val]; // default 0 on first access
                    if (c == 0) {
                        result[i] = 'A';
                        assigned[val] = 1;
                    } else if (c == 1) {
                        result[i] = 'B';
                        assigned[val] = 2;
                    } else {
                        if (val == 0) {
                            result[i] = 'A';
                        }
                        assigned[val] = c + 1;
                    }
                }
                // else: leave as default 'C'
            }

            output += "YES\n";
            output += result;
            output += '\n';
        }
    }

    cout << output;
    return 0;
}