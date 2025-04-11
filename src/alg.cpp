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
    int find_number = value - arr[i];
    int left_number = i + 1;
    int right_number = len - 1;
    while (left_number <= right_number) {
      int middle = left_number + (right_number - left_number) / 2;
      if (arr[middle] == find_number) {
        pair_numbers++;
        for (int j = middle - 1; j >= left_number && arr[j] == find_number; --j)
          pair_numbers++;
        for (int j = middle + 1; j <= right_number && arr[j] == find_number; ++j)
          pair_numbers++;
          break;
      }
      else if (arr[middle] < find_number) {
        left_number = middle + 1;
      }
      else {
        right_number = middle - 1;
      }
    }
  }
  return pair_numbers;
}
