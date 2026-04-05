// Copyright 2021 NNTU-CS
#include <iostream>
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count = count + 1;
                break;
            }
        }
        while (i + 1 < len && arr[i] == arr[i + 1]) i++;
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int count = 0;
    int lt = 0;
    int rt = len - 1;
    while (lt < rt) {
        int sum = arr[lt] + arr[rt];
        if (sum == value) {
            count++;
            lt++;
            rt--;
            while (lt < rt && arr[lt] == arr[lt - 1]) lt++;
            while (lt < rt && arr[rt] == arr[rt + 1]) rt--;
        } else if (sum < value) {
            lt++;
        } else {
            rt--;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int count = 0;
    int lt = 0;
    int rt = len - 1;
    while (lt < rt) {
        int sum = arr[lt] + arr[rt];
        if (sum == value) {
            count++;
            lt++;
            rt--;
            while (lt < rt && arr[lt] == arr[lt - 1]) lt++;
            while (lt < rt && arr[rt] == arr[rt + 1]) rt--;
        } else if (sum < value) {
            lt++;
        } else {
            rt--;
        }
    }
    return count;
}
