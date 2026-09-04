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
        char c;
        cin>>n>>c;
        string str ;
        cin>> str;
        int i =0;
        int ans =0;
        while(i < n){
            int j = i;
            if(str[i] == c){
                while(str[j%n] != 'g'){
                    j++;
                }
                ans = max(ans,j-i);
                i = j+1;
            }
            else{
                i++;
            }
        }
        if(c == 'g')cout<<0<<endl;
        else{
            cout<<ans<<endl;
        }
    }

    return 0;
}