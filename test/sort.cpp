#include "onegin/sort.h"
#include "gtest/gtest.h"

bool compare_int(const void *left, const void *right) {
    int left_int = *((int *)left);
    int right_int = *((int *)right);
    return left_int < right_int;
}

TEST(is_sorted, null_array) {
    ASSERT_DEBUG_DEATH(is_sorted(NULL, 5, 4, compare_int), "");
}

TEST(is_sorted, wrong_elem_size) {
    int arr[] = {1, 2, 3, 4, 5};
    ASSERT_DEBUG_DEATH(is_sorted(arr, 5, 0, compare_int), "");
}

TEST(is_sorted, wrong_array_size) {
    int arr[] = {1, 2, 3, 4, 5};
    ASSERT_DEBUG_DEATH(is_sorted(arr, 0, sizeof(*arr), compare_int), "");
}

TEST(is_sorted, singleton_array) {
    int arr[] = {1};
    ASSERT_TRUE(is_sorted(arr, 1, sizeof(*arr), compare_int));
}

TEST(is_sorted, equal_elements_array) {
    int arr[] = {1, 1, 1};
    ASSERT_TRUE(is_sorted(arr, 3, sizeof(*arr), compare_int));
}

TEST(is_sorted, descending_two_elem_array) {
    int arr[] = {2, 1};
    ASSERT_FALSE(is_sorted(arr, 2, sizeof(*arr), compare_int));
}

TEST(is_sorted, not_descending_large_array) {
    int arr[] = {1, 3, 3, 5, 6, 7};
    ASSERT_TRUE(is_sorted(arr, 6, sizeof(*arr), compare_int));
}

TEST(is_sorted, not_ascending_large_array) {
    int arr[] = {1, 3, 5, 600, 7};
    ASSERT_FALSE(is_sorted(arr, 5, sizeof(*arr), compare_int));
}

TEST(sort, null_array) {
    int arr[] = {1, 2, 3};
    ASSERT_DEBUG_DEATH(sort(NULL, 3, sizeof(*arr), compare_int), "");
}

TEST(sort, singleton_array) {
    int arr[] = {1};
    size_t elem_size = sizeof(*arr);
    size_t N = sizeof(arr) / elem_size;
    sort(arr, N, elem_size, compare_int);
    ASSERT_TRUE(is_sorted(arr, N, elem_size, compare_int));
}

TEST(sort, descending_two_elem_array) {
    int arr[] = {2, 1};
    size_t elem_size = sizeof(*arr);
    size_t N = sizeof(arr) / elem_size;
    sort(arr, N, elem_size, compare_int);
    ASSERT_TRUE(is_sorted(arr, N, elem_size, compare_int));
}

TEST(sort, large_array_1) {
    int arr[] = {3, 2, 1};
    size_t elem_size = sizeof(*arr);
    size_t N = sizeof(arr) / elem_size;
    sort(arr, N, elem_size, compare_int);
    ASSERT_TRUE(is_sorted(arr, N, elem_size, compare_int));
}

TEST(sort, large_array_2) {
    int arr[] = {5, 1, 2, 4, 3, 0};
    size_t elem_size = sizeof(*arr);
    size_t N = sizeof(arr) / elem_size;
    sort(arr, N, elem_size, compare_int);
    ASSERT_TRUE(is_sorted(arr, N, elem_size, compare_int));
}

TEST(sort, same) {
    int arr[] = {1, 1};
    size_t elem_size = sizeof(*arr);
    size_t N = sizeof(arr) / elem_size;
    sort(arr, N, elem_size, compare_int);
    ASSERT_TRUE(is_sorted(arr, N, elem_size, compare_int));
}
