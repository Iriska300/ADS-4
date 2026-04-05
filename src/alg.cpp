// Copyright 2021 NNTU-CS
#include <iostream>
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
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
            if (arr[lt] == arr[rt]) {
                int n = rt - lt + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int ltCount = 1;
                int rtCount = 1;

                while (lt + 1 < rt && arr[lt] == arr[lt + 1]) {
                    ++ltCount;
                    ++lt;
                }
                while (rt - 1 > lt && arr[rt] == arr[rt - 1]) {
                    ++rtCount;
                    --rt;
                }
                count += ltCount * rtCount;
                ++lt;
                --rt;
            }
        } else if (sum < value) {
            ++lt;
        } else {
            --rt;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; ++i) {
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
            ++i;
        }
    }
    return count;
}
