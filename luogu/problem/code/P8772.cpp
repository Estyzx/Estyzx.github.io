#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        ans += v[i];
    }
    ll a = 0;
    for (int i = 1; i <= n; ++i) {
        a += v[i] * (ans - v[i]);
    }
    cout << a / 2 << endl;
    return 0;
}
