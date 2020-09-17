#include "stddef.h"
#include "gtest/gtest.h"

#include "onegin/stringpart.h"

TEST(compare_words, should_pass) { ASSERT_TRUE(1 == 1); }

TEST(compare_words, one_word) {
    char hello[] = "hello";
    StringPart first = {
        .begin = hello,
        .end = hello + sizeof(hello) - 1,
    };

    char help[] = "helplo";
    StringPart second = {
        .begin = help,
        .end = help + sizeof(help) - 1,
    };

    EXPECT_TRUE(compare_words(&first, &second));
    EXPECT_TRUE(compare_words_reversed(&first, &second));
    EXPECT_FALSE(compare_words(&second, &first));
    EXPECT_FALSE(compare_words_reversed(&second, &first));
}

TEST(compare_words, same_word) {
    char hello[] = "Hello, world!";
    StringPart part = {
        .begin = hello,
        .end = hello + sizeof(hello) - 1,
    };

    EXPECT_FALSE(compare_words(&part, &part));
    EXPECT_FALSE(compare_words_reversed(&part, &part));
}

TEST(compare_words, empty_string) {
    char empty[] = "";
    StringPart empty_part{
        .begin = empty,
        .end = empty + sizeof(empty) - 1,
    };

    char not_empty[] = "a!?";
    StringPart not_empty_part{
        .begin = not_empty,
        .end = not_empty + sizeof(not_empty) - 1,
    };

    EXPECT_TRUE(compare_words(&empty_part, &not_empty_part));
    EXPECT_FALSE(compare_words(&not_empty_part, &empty_part));
    EXPECT_TRUE(compare_words_reversed(&empty_part, &not_empty_part));
    EXPECT_FALSE(compare_words_reversed(&not_empty_part, &empty_part));
}

TEST(compare_words, large_test) {
    char a[] = "привет";
    size_t as = sizeof(a);
}

TEST(split, empty) {
    char text[] = "";
    StringPart *result = NULL;
    size_t result_length = split(text, '\n', &result);
    EXPECT_EQ(0, result_length);
    free(result);
}

TEST(split, one_part) {
    char text[] = "Hello\n";
    StringPart *result = NULL;
    size_t result_length = split(text, '\n', &result);
    ASSERT_EQ(1, result_length);
    EXPECT_EQ(text, result[0].begin); // 'H' symbol in the text
    EXPECT_EQ(text + 5, result[0].end); // '\n' symbol in the text
    free(result);
}

TEST(split, two_parts) {
    char text[] = "Hello\nthere \nguys";
    StringPart *result = NULL;
    size_t result_length = split(text, '\n', &result);
    ASSERT_EQ(2, result_length);
    EXPECT_EQ(text, result[0].begin);       // 'H' symbol in the text
    EXPECT_EQ(text + 5, result[0].end);     // '\n' symbol in the text
    EXPECT_EQ(text + 6, result[1].begin);   // 't' symbol
    EXPECT_EQ(text + 12, result[1].end);    // second '\n'
    free(result);
}
