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
  int right_number = len - 1;
  while (right_number >= 0 && arr[right_number] > value) {
    right_number--;
  }
  for (int i = 0; i < len; i++) {
    for (int j = right_number; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        pair_numbers++;
      }
    }
  }
  return pair_numbers;
}
int countPairs3(int *arr, int len, int value) {
  int pair_numbers = 0;
  for (int i = 0; i < len - 1; ++i) {
    int find_numb = value - arr[i];
    int left_number = i + 1;
    int right_number = len - 1;
    while (left_number <= right_number) {
      int middle = left_number + (right_number - left_number) / 2;
      if (arr[middle] == find_numb) {
        pair_numbers++;
        for (int j = middle - 1; j >= left_number && arr[j] == find_numb; --j)
          pair_numbers++;
        for (int j = middle + 1; j <= right_number && arr[j] == find_numb; ++j)
          pair_numbers++;
          break;
      } else if (arr[middle] < find_numb) {
        left_number = middle + 1;
      } else {
        right_number = middle - 1;
      }
    }
  }
  return pair_numbers;
}
