#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        // forbidden[i] = position i cannot contain treasure
        vector<int> diff(n + 1, 0);

        // Forced treasure positions
        vector<int> treasure(n, 0);

        for (int i = 0; i < n; i++) {
            if (b[i] == 0)
                treasure[i] = 1;
        }

        /*
            If b[i] = d > 0, there must be NO treasure
            at distances 0,1,...,d-1 from i.

            Therefore:
                [i-d+1, i+d-1]
            is forbidden.
        */
        for (int i = 0; i < n; i++) {
            if (b[i] <= 0)
                continue;

            int d = b[i];

            int l = max(0, i - d + 1);
            int r = min(n - 1, i + d - 1);

            diff[l]++;
            diff[r + 1]--;
        }

        vector<int> forbidden(n, 0);

        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            if (cur > 0)
                forbidden[i] = 1;
        }

        bool ok = true;

        // A forced treasure cannot be forbidden.
        for (int i = 0; i < n; i++) {
            if (treasure[i] && forbidden[i]) {
                ok = false;
                break;
            }
        }

        /*
            For every known positive distance,
            choose one endpoint.

            Because that endpoint is NOT forbidden,
            there is no treasure closer than d.
            Therefore its actual distance is exactly d.
        */
        if (ok) {
            for (int i = 0; i < n; i++) {
                if (b[i] <= 0)
                    continue;

                int d = b[i];

                int left = i - d;
                int right = i + d;

                if (left >= 0 && !forbidden[left]) {
                    treasure[left] = 1;
                }
                else if (right < n && !forbidden[right]) {
                    treasure[right] = 1;
                }
                else {
                    ok = false;
                    break;
                }
            }
        }

        /*
            FINAL VERIFICATION.
            This removes any possibility of printing an invalid
            construction because of a construction mistake.
        */
        if (ok) {
            vector<int> dist(n, n);

            int last = -n;

            // Distance from nearest treasure on the left
            for (int i = 0; i < n; i++) {
                if (treasure[i])
                    last = i;

                if (last >= 0)
                    dist[i] = i - last;
            }

            last = 2 * n;

            // Distance from nearest treasure on the right
            for (int i = n - 1; i >= 0; i--) {
                if (treasure[i])
                    last = i;

                if (last < n)
                    dist[i] = min(dist[i], last - i);
            }

            // Must have at least one treasure
            bool hasTreasure = false;
            for (int x : treasure)
                hasTreasure |= x;

            if (!hasTreasure)
                ok = false;

            // Check every known value
            if (ok) {
                for (int i = 0; i < n; i++) {
                    if (b[i] != -1 && b[i] != dist[i]) {
                        ok = false;
                        break;
                    }
                }
            }
        }

        if (!ok) {
            cout << -1 << '\n';
        }
        else {
            string treasure_map_fin;

            for (int i = 0; i < n; i++) {
                treasure_map_fin += treasure[i] ? '1' : '0';
            }

            cout << treasure_map_fin << '\n';
        }
    }

    return 0;
}