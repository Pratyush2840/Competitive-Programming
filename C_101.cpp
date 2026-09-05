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
        int n ;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        //left
        int flag=0;
        for(int i=0 ; i < n;i++){
            if(arr[i] == -1 && flag == 0){
                arr[i] =1;
                flag =1;
            }
            else if(arr[i] ==1){
                flag=1;
            }
        }
        //right
        flag =0;
        for(int i = n-1 ; i>=0 ; i--){
            if(arr[i] == -1 && flag ==0){
                arr[i] =1;
                flag = 1;
            }
            else if( arr[i] == 1){
                flag = 1;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i] == -1){
                arr[i] = 0;
            }
        }
        for(auto it : arr){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}