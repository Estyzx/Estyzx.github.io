#include <bits/stdc++.h>  //万能头文件
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<int> st;  // set 容器
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        st.insert(t);
    }
    vector<int> v(st.begin(), st.end());  // 将set容器转化为vector容器
    sort(v.begin(), v.end());  //排序
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " \n"[i == v.size() - 1];  //如果是最后一个元素，则输出换行符
    }
    return 0;
}