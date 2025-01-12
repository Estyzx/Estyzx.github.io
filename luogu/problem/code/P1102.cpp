#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    map<ll, ll> mp;
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        ll t;
        cin >> t;
        mp[t]++;
    }
    ll ans = 0;
    for (auto i: mp) {
        if (mp.count(i.first + c)) {
            ans += mp[i.first + c] * i.second;
        }
    }
    cout << ans;
    return 0;
}
