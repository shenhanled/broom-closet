// https://zhuanlan.zhihu.com/p/31498036

# include <iostream>

using namespace std;
const int N = 10005;

// 双指针单向扫描
int partion_uni_direction(int a[], int l, int r) {
    int i = l - 1;
    int pivot = a[r];
    for (int j = l; j <= r; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    return i;
}

// 双指针双向扫描
int partion_bi_direction(int a[], int l, int r) {
    int i = l;
    int j = r;
    int pivot = a[l];
    while (i < j) {
        while (a[j] >= pivot && i < j) {
            j--;
        }
        a[i] = a[j];
        while (a[i] <= pivot && i < j) {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = pivot;
    return i;
}

void quick_sort(int a[], int l, int r) {
    if (l < r) {
        // int k = partion_uni_direction(a, l, r);
        int k = partion_bi_direction(a, l, r);
        quick_sort(a, l, k - 1);
        quick_sort(a, k + 1, r);
    }
}

int a[N];

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        quick_sort(a, 0, n - 1);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}