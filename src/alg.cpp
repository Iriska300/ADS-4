// Copyright 2021 NNTU-CS
#include <iostream>
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int* sorted = new int[len];
    for (int i = 0; i < len; i++) sorted[i] = arr[i];
    std::sort(sorted, sorted + len);

    int count = 0;
    int lt = 0;
    int rt = len - 1;

    while (lt < rt) {
        int sum = sorted[lt] + sorted[rt];
        if (sum == value) {
            if (sorted[lt] == sorted[rt]) {
                int n = rt - lt + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int ltCount = 1, rtCount = 1;
                while (lt + 1 < rt && sorted[lt] == sorted[lt + 1]) {
                    ltCount++;
                    lt++;
                }
                while (rt - 1 > lt && sorted[rt] == sorted[rt - 1]) {
                    rtCount++;
                    rt--;
                }
                count += ltCount * rtCount;
                lt++;
                rt--;
            }
        } else if (sum < value) {
            lt++;
        } else {
            rt--;
        }
    }
    delete[] sorted;
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int* sorted = new int[len];
    for (int i = 0; i < len; i++) sorted[i] = arr[i];
    std::sort(sorted, sorted + len);

    int count = 0;

    for (int i = 0; i < len; i++) {
        int target = value - sorted[i];

        int lt = i + 1;
        int rt = len - 1;
        int first = -1;

        while (lt <= rt) {
            int mid = lt + (rt - lt) / 2;
            if (sorted[mid] == target) {
                first = mid;
                rt = mid - 1;
            } else if (sorted[mid] < target) {
                lt = mid + 1;
            } else {
                rt = mid - 1;
            }
        }

        if (first != -1) {
            lt = first;
            rt = len - 1;
            int last = first;
            while (lt <= rt) {
                int mid = lt + (rt - lt) / 2;
                if (sorted[mid] == target) {
                    last = mid;
                    lt = mid + 1;
                } else if (sorted[mid] < target) {
                    lt = mid + 1;
                } else {
                    rt = mid - 1;
                }
            }
            count += (last - first + 1);
        }

        while (i + 1 < len && sorted[i + 1] == sorted[i]) {
            i++;
        }
    }
    delete[] sorted;
    return count;
}
