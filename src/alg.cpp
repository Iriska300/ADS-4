// Copyright 2021 NNTU-CS
#include <algorithm>
#include <iostream>

int countPairs1(int* arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
                while (j + 1 < len && arr[j + 1] == arr[j]) {
                    j++;
                }
            }
        }
        while (i + 1 < len && arr[i + 1] == arr[i]) {
            i++;
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
            int ltCount = 1;
            int rtCount = 1;

            while (lt + 1 < rt && arr[lt] == arr[lt + 1]) {
                ltCount++;
                lt++;
            }

            while (rt - 1 > lt && arr[rt] == arr[rt - 1]) {
                rtCount++;
                rt--;
            }
            count += ltCount * rtCount;
            lt++;
            rt--;
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

    for (int i = 0; i < len - 1; i++) {
        int numberToFind = value - arr[i];

        int lt = i + 1;
        int rt = len - 1;
        int found = -1;

        while (lt <= rt) {
            int center = lt + (rt - lt) / 2;
            if (arr[center] == numberToFind) {
                found = center;
                break;
            } else if (arr[center] < numberToFind) {
                lt = center + 1;
            } else {
                rt = center - 1;
            }
        }

        if (found != -1) {
            count++;

            int j = found + 1;
            while (j < len && arr[j] == numberToFind) {
                count++;
                j++;
            }
        }

        while (i + 1 < len && arr[i + 1] == arr[i]) {
            i++;
        }
    }
    return count;
}
