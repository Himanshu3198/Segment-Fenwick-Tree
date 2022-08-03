//  find max element in given range using segment tree
#include <bits/stdc++.h>
using namespace std;
vector<int> a(10005), seg(4 * 10005);

void build(int idx, int low, int high)
{
    if (low == high)
    {
        seg[idx] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * idx + 1, low, mid);
    build(2 * idx + 2, mid + 1, high);
    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}
int query(int idx, int l, int r, int low, int high)
{
    if (low >= l && high <= r)
    {
        return seg[idx];
    }
    if (high < l || low > r)
        return INT_MIN;
    int mid = (low + high) / 2;
    int left = query(2 * idx + 1, l, r, low, mid);
    int right = query(2 * idx + 2, l, r, mid + 1, high);
    return max(left, right);
}
int main()
{
    int n = 10;
    a = {8, 2, 5, 1, 4, 5, 3, 9, 6, 10};

    for (auto it : a)
        cout << it << " ";
    cout << "\n";
    build(0, 0, n - 1);
    cout << query(0, 0, 3, 0, n - 1) << "\n";
    cout << query(0, 2, 7, 0, n - 1) << "\n";
    cout << query(0, 7, 9, 0, n - 1) << "\n";
    cout << query(0, 3, 5, 0, n - 1) << "\n";
}
