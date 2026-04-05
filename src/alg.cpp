// Copyright 2021 NNTU-CS
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
    int count = 0;
    int lt = 0;
    int rt = len - 1;

    while (lt < rt) {
        int sum = arr[lt] + arr[rt];

        if (sum == value) {
            int ltVal = arr[lt];
            int rtVal = arr[rt];

            if (ltVal == rtVal) {
                int n = rt - lt + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int ltCount = 1;
                while (lt + 1 < rt && arr[lt + 1] == ltVal) {
                    ltCount++;
                    lt++;
                }

                int rtCount = 1;
                while (rt - 1 > lt && arr[rt - 1] == rtVal) {
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
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; i++) {
        int target = value - arr[i];

        if (target < arr[i]) {
            continue;
        }

        int lt = i + 1;
        int rt = len - 1;
        int firstIndex = -1;

        while (lt <= rt) {
            int mid = lt + (rt - lt) / 2;
            if (arr[mid] == target) {
                firstIndex = mid;
                rt = mid - 1;
            } else if (arr[mid] < target) {
                lt = mid + 1;
            } else {
                rt = mid - 1;
            }
        }

        if (firstIndex != -1) {
            lt = firstIndex;
            rt = len - 1;
            int lastIndex = firstIndex;

            while (lt <= rt) {
                int mid = lt + (rt - lt) / 2;
                if (arr[mid] == target) {
                    lastIndex = mid;
                    lt = mid + 1;
                } else if (arr[mid] < target) {
                    lt = mid + 1;
                } else {
                    rt = mid - 1;
                }
            }

            count += (lastIndex - firstIndex + 1);

            while (i + 1 < len && arr[i + 1] == arr[i]) {
                i++;
                count += (lastIndex - firstIndex + 1);
            }
        }
    }
    return count;
}
