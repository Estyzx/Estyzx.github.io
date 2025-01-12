#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int find(int x,vector<int> &v) {
    int i = 0,j = v.size()-1;
    while (i<=j) {
        int mid = (i+j)>>1;
        if (v[mid]>=x) {
            j = mid-1;
        }else {
            i = mid+1;
        }
    }
    if (i>= v.size()|| v[i]!=x) {
        return -1;
    }
    return i;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> v(n,0);
    for (auto  &num : v) {
        cin>>num;
    }
    for (int i = 0 ;i<m;i++) {
        int x;
        cin>>x;
        int index = find(x,v);
        cout<<(index != -1?index+1:-1)<<" ";
    }
    return 0;
}
