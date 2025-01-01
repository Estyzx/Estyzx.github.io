#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

void mergesort(vector<int> &v, int l, int r);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    vector<int> v = {21, 98, 34, 45, 57, 46, 74, 81, 9, 10};
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl;
    mergesort(v, 0, v.size() - 1);
    for (auto x: v) {
        cout << x << " ";
    }
    return 0;
}

void mergesort(vector<int> &v, int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) >> 1;
    mergesort(v, l, mid);
    mergesort(v, mid + 1, r);
    vector<int> tmp(r - l + 1);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (v[i] < v[j]) {
            tmp[k++] = v[i++];
        } else {
            tmp[k++] = v[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = v[i++];
    }
    while (j <= r) {
        tmp[k++] = v[j++];
    }
    for (i = l; i <= r; i++) {
        v[i] = tmp[i - l];
    }
}
