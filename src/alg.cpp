// Copyright 2021 NNTU-CS
#include <vector>
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            } else if (arr[i] + arr[j] > value) {
                break;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int lt = 0;
    int rt = len - 1;
    while (lt < rt) {
        int sum = arr[lt] + arr[rt];
        if (sum == value) {
            count++;
            lt++;
            rt--;
            while (lt < rt && arr[lt] == arr[lt - 1]) {
                lt++;
            }
            while (lt < rt && arr[rt] == arr[rt + 1]) {
                rt--;
            }
        } else if (sum < value) {
            lt++;
        } else {
            rt--;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];

        if (target < arr[i]) {
            break;
        }

        auto it_low = std::lower_bound(arr + i + 1, arr + len, target);

        if (it_low != arr + len && *it_low == target) {
            count++;
        }
    }
    return count;
}
