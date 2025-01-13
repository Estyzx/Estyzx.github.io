#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << v[r] - v[l - 1] << endl;
    }
}
