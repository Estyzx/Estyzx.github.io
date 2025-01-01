#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

void bubbleSort(vector<int> &nums);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    vector<int> nums = {2, 1, 3, 4, 5, 9, 6};
    for (auto num: nums) {
        cout << num << " ";
    }
    cout << endl;
    bubbleSort(nums);
    for (auto num: nums) {
        cout << num << " ";
    }
    return 0;
}

void bubbleSort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size() - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}
