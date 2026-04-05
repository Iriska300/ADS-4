// Copyright 2021 NNTU-CS
#include <iostream>
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int result = 0;

    for (int idx = 0; idx < len; ++idx) {
        for (int jdx = idx + 1; jdx < len; ++jdx) {
            if (arr[idx] + arr[jdx] == value) {
                result += 1;
                break;
            }
        }
        while (idx + 1 < len && arr[idx] == arr[idx + 1]) {
            idx += 1;
        }
    }
    return result;
}

int countPairs2(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int result = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];

        if (currentSum == value) {
            result += 1;
            left += 1;
            right -= 1;

            while (left < right && arr[left] == arr[left - 1]) {
                left += 1;
            }

            while (left < right && arr[right] == arr[right + 1]) {
                right -= 1;
            }
        } else if (currentSum < value) {
            left += 1;
        } else {
            right -= 1;
        }
    }
    return result;
}

int countPairs3(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int result = 0;

    for (int idx = 0; idx < len; ++idx) {
        int need = value - arr[idx];

        int low = idx + 1;
        int high = len - 1;
        int position = -1;

        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (arr[middle] == need) {
                position = middle;
                break;
            } else if (arr[middle] < need) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }

        if (position != -1) {
            result += 1;

            int step = position + 1;
            while (step < len && arr[step] == need) {
                result += 1;
                step += 1;
            }

            step = position - 1;
            while (step > idx && arr[step] == need) {
                result += 1;
                step -= 1;
            }
        }

        while (idx + 1 < len && arr[idx + 1] == arr[idx]) {
            idx += 1;
        }
    }
    return result;
}
