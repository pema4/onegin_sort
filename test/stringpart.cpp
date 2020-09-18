#include "onegin/stringpart.h"
#include "stddef.h"
#include "gtest/gtest.h"

TEST(compare_letters, one_word) {
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

    EXPECT_TRUE(compare_letters(&first, &second));
    EXPECT_TRUE(compare_letters_reversed(&first, &second));
    EXPECT_FALSE(compare_letters(&second, &first));
    EXPECT_FALSE(compare_letters_reversed(&second, &first));
}

TEST(compare_letters, same_word) {
    char hello[] = "Hello, world!";
    StringPart part = {
        .begin = hello,
        .end = hello + sizeof(hello) - 1,
    };

    EXPECT_FALSE(compare_letters(&part, &part));
    EXPECT_FALSE(compare_letters_reversed(&part, &part));
}

TEST(compare_letters, empty_string) {
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

    EXPECT_TRUE(compare_letters(&empty_part, &not_empty_part));
    EXPECT_FALSE(compare_letters(&not_empty_part, &empty_part));
    EXPECT_TRUE(compare_letters_reversed(&empty_part, &not_empty_part));
    EXPECT_FALSE(compare_letters_reversed(&not_empty_part, &empty_part));
}

TEST(compare_letters, utf8_test_1) {
    char first[] =  "hi! привет! bye!";
    StringPart first_part = {
        .begin = first,
        .end = first + sizeof(first)
    };
    char second[] = "hi! приведи ещё 5 друзей и получи подарок!";
    StringPart second_part = {
        .begin = second,
        .end = second + sizeof(second)
    };

    EXPECT_FALSE(compare_letters(&first_part, &second_part));
    EXPECT_TRUE(compare_letters(&second_part, &first_part));
}

TEST(split, empty_text) {
    char text[] = "";
    StringPart *result = NULL;
    size_t result_length = split(text, '\n', &result);
    EXPECT_EQ(0, result_length);
    free(result);
}

TEST(split, one_line) {
    char text[] = "Hello\n";
    StringPart *result = NULL;
    size_t result_length = split(text, '\n', &result);
    ASSERT_EQ(1, result_length);
    EXPECT_EQ(text, result[0].begin);   // 'H' symbol in the text
    EXPECT_EQ(text + 5, result[0].end); // '\n' symbol in the text
    free(result);
}

TEST(split, two_line) {
    char text[] = "Hello\nthere \nguys";
    StringPart *result = NULL;
    size_t result_length = split(text, '\n', &result);
    ASSERT_EQ(2, result_length);
    EXPECT_EQ(text, result[0].begin);     // 'H' symbol in the text
    EXPECT_EQ(text + 5, result[0].end);   // '\n' symbol in the text
    EXPECT_EQ(text + 6, result[1].begin); // 't' symbol
    EXPECT_EQ(text + 12, result[1].end);  // second '\n'
    free(result);
}

TEST(split, empty_lines) {
    char text[] = "\n\n\n";
    StringPart *result = NULL;
    size_t result_length = split(text, '\n', &result);
    EXPECT_EQ(0, result_length);
}

TEST(split, five_lines_and_some_are_empty) {
    char text[] = "\nhello\n\nthere\n\n";
    StringPart *result = NULL;
    size_t result_length = split(text, '\n', &result);
    ASSERT_EQ(2, result_length);
    EXPECT_EQ(text + 1, result[0].begin);
    EXPECT_EQ(text + 6, result[0].end);
    EXPECT_EQ(text + 8, result[1].begin);
    EXPECT_EQ(text + 13, result[1].end);
}
