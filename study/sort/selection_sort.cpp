#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

void selectionSort(vector<int> &nums);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    vector<int> nums = {2, 1, 3, 4, 5, 9, 6};
    for (auto num: nums) {
        cout << num << " ";
    }
    cout << endl;
    selectionSort(nums);
    for (auto num: nums) {
        cout << num << " ";
    }
    return 0;
}

void selectionSort(vector<int> &nums) {
    int index = 0;
    while (index < nums.size()) {
        int minindex = index;
        for (int i = index + 1; i < nums.size(); i++) {
            if (nums[i] < nums[minindex]) {
                minindex = i;
            }
        }
        swap(nums[index], nums[minindex]);
        index++;
    }
}
