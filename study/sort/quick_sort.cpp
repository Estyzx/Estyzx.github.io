#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

void quick_sort(vector<int> &nums, int l, int r);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    vector<int> nums = {2, 6, 3, 1, 9, 8, 7, 5, 0};
    for (auto x: nums) {
        cout << x << " ";
    }
    cout << endl;
    quick_sort(nums, 0, nums.size() - 1);
    for (auto x: nums) {
        cout << x << " ";
    }
}

void quick_sort(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    int pivot = nums[l];
    int i = l + 1, j = r;
    while (i <= j) {
        while (i <= j && nums[j] > pivot) {
            j--;
        }
        while (i <= j && nums[i] < pivot) {
            i++;
        }
        if (i <= j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    swap(nums[l], nums[i - 1]);
    quick_sort(nums, l, i - 1);
    quick_sort(nums, i, r);
}
