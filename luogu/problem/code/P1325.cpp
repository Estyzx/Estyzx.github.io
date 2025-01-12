#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<pair<double, double> > v(n);
    bool flag = false;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y > d) {
            flag = true;
            break;
        }
        double r = sqrt(d * d - y * y);
        v[i] = {x + r, x - r};
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    double t = -1e18;
    for (auto p: v) {
        if (p.second > t) {
            ans++;
            t = p.first;
        }
    }
    if (flag) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}
