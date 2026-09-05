#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int MOD = 1e9 + 7;

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int odd = 0;
        int evenOdd = 0;
        int evenEven = 0;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;

            if (x % 2) {
                odd++;
            } else {
                x /= 2;

                if (x % 2)
                    evenOdd++;
                else
                    evenEven++;
            }
        }

        cout << max({odd, evenOdd, evenEven}) << '\n';
    }

    return 0;
}