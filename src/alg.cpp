// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int pair_numbers = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        pair_numbers++;
      }
    }
  } 
  return pair_numbers;
}
int countPairs2(int *arr, int len, int value) {
  int pair_numbers = 0;
  int left_number = 0;
  int right_number = len - 1;
  while (left_number < right_number) {
    int sum = arr[left_number] + arr[right_number];
    if (sum == value) {
      pair_numbers++;
      left_number++;
      right_number--;
    } 
    else if (sum < value) {
      left_number++;
    } 
    else {
    right_number--;
    }
  }
  return pair_numbers;
}
int countPairs3(int *arr, int len, int value) {
  int pair_numbers = 0;
  for (int i = 0; i < len - 1; ++i) {
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        pair_numbers++;
        for (int j = mid - 1; j >= left && arr[j] == target; --j)
          pair_numbers++;
        for (int j = mid + 1; j <= right && arr[j] == target; ++j)
          pair_numbers++;
          break;
      }
      else if (arr[mid] < target) {
        left = mid + 1;
      }
      else {
        right = mid - 1;
      }
    }
  }
  return pair_numbers;
}
