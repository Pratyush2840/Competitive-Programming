#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int MOD = 1e9 + 7;

void solve(int n , int k ,int q , vector<int>& arr) {
    for(auto it : arr){
        if(it <= q){
            it =1;
        }
        else{
            it =0;
        }
    }
    int l =0 ;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int n,k,q;
    while (t--) {
        cin>>n>>k>>q;
        vector<int >arr(n);
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        solve(n,k,q,arr);
    }

    return 0;
}