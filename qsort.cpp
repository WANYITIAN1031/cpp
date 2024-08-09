#include <iostream>
#include <vector>

using namespace std;

// 快速排序函数
void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // 选择中间元素作为基准值
        int pivot = arr[(left + right) / 2];
        int i = left;
        int j = right;

        // 分割数组
        while (i <= j) {
            // 在左侧找到第一个大于等于基准值的元素
            while (arr[i] < pivot) {
                i++;
            }
            // 在右侧找到第一个小于等于基准值的元素
            while (arr[j] > pivot) {
                j--;
            }
            // 交换这两个元素
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        // 递归调用快速排序函数，对左右两个子数组进行排序
        if (left < j) {
            quickSort(arr, left, j);
        }
        if (i < right) {
            quickSort(arr, i, right);
        }
    }
}

int main() {
    vector<int> arr = {12, 45, 23, 51, 19, 8, 32};
    int n = arr.size();

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // 调用快速排序函数
    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
