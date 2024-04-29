# Data Structures Assignment: Searching in a Partially Sorted Array

This assignment focuses on implementing three different search algorithms to find a given number `x` in a partially sorted array `V` of size `m`. The array initially contains `n` sorted natural numbers, where `200 <= n <= 300`, and the remaining elements are zeros.

## Problem Description

Given an array `V` of size `m`, containing `n` sorted natural numbers followed by zeros, and a number `x`, the task is to find the index of `x` in the array. If `x` is not present in the array, the program should return -1.

## Implementations

The assignment requires implementing three search functions with different time complexities:

1. **Search1(V, m, x)** with a time complexity of O(n).
2. **Search2(V, m, x)** with a time complexity of O(log m).
3. **Search3(V, m, x)** with a time complexity of O(log n).

## Testing

To test the algorithms, the assignment requires generating 500 arrays of size 1000, where:
- `n` is randomly generated within the range `200 <= n <= 300`.
- `n` random numbers are generated and sorted within the array.
- The remaining elements are filled with zeros.
- `x` is randomly generated.

For each search function, the average number of comparisons performed should be reported.

## Output

The program should print the following output:
