#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n, k, b, s;
        cin >> n >> k >> b >> s;

        ll number = k * b;

        if (number > s) {
            cout << -1 << '\n';
            continue;
        }

        ll remain = s - number;

        if (n * (k - 1) < remain) {
            cout << -1 << '\n';
            continue;
        }

        vector<ll> arr(n, 0);

        arr[0] = k * b;

        for (int i = 0; i < n ; i++) {
            ll add = min(remain, k - 1);
            arr[i] += add;
            remain -= add;
        }

        for (auto x : arr) {
            cout << x << " ";
        }

        cout << '\n';
    }

    return 0;
}