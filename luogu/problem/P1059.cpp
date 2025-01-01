#include <bits/stdc++.h>  
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<int> st;  
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        st.insert(t);
    }
    vector<int> v(st.begin(), st.end());  
    sort(v.begin(), v.end());  
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " \n"[i == v.size() - 1];  
    }
    return 0;
}