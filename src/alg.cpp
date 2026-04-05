// Copyright 2021 NNTU-CS
#include <algorithm>
#include <iostream>

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
    int count = 0;
    int lt = 0;
    int rt = len - 1;

    while (lt < rt) {
        int sum = arr[lt] + arr[rt];

        if (sum == value) {
            int ltVal = arr[lt];
            int ltCount = 0;
            while (lt <= rt && arr[lt] == ltVal) {
                ltCount++;
                lt++;
            }

            int rtVal = arr[rt];
            int rtCount = 0;
            while (rt >= lt && arr[rt] == rtVal) {
                rtCount++;
                rt--;
            }

            if (ltVal == rtVal) {
                count += ltCount * (ltCount - 1) / 2;
            } else {
                count += ltCount * rtCount;
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

    for (int i = 0; i < len; i++) {
        int target = value - arr[i];

        int low = i + 1;
        int high = len - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (first != -1) {
            low = first;
            high = len - 1;
            int last = first;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid] == target) {
                    last = mid;
                    low = mid + 1;
                } else if (arr[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            count += (last - first + 1);
        }

        while (i + 1 < len && arr[i + 1] == arr[i]) {
            i++;
        }
    }
    return count;
}
