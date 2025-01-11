#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll merge_sort(vector<int> &v, int l, int r) {
    if (l >= r) {
        return 0;
    }
    int mid = (l + r) >> 1;
    ll ans = merge_sort(v, l, mid) + merge_sort(v, mid + 1, r);
    vector<int> tmp;
    int i = l, j = mid + 1, h = 0;
    while (i <= mid && j <= r) {
        if (v[i] > v[j]) {
            ans += (r - j + 1);
            tmp.push_back(v[i++]);
        } else {
            tmp.push_back(v[j++]);
        }
    }
    while (i <= mid) {
        tmp.push_back(v[i++]);
    }
    while (j <= r) {
        tmp.push_back(v[j++]);
    }
    for (i = l; i <= r; ++i) {
        v[i] = tmp[i - l];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (auto &num: v) {
        cin >> num;
    }
    cout << merge_sort(v, 0, n - 1) << endl;
    return 0;
}