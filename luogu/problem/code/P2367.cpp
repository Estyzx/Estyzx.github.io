#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n ,p;
    cin >> n >> p;
    vector<int> grade(n);
    for (auto &x : grade) {
        cin >> x;
    }
    vector<int> gradec(n+1,0);
    gradec[0] = grade[0];
    for (int i = 1; i < n; i++) {
        gradec[i] = grade[i] - grade[i-1];
    }
    for (int i = 1;i<=p;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        gradec[x-1] += z;
        if (y<n) {
            gradec[y] -= z;
        }
    }
    int ans  = gradec[0];
    grade[0] = gradec[0];
    for (int i = 1; i < n; i++) {
        grade[i] = grade[i-1] + gradec[i];
        ans = min(ans,grade[i]);
    }
    cout<<ans<<endl;
    return 0;
}
