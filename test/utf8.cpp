#include "onegin/utf8.h"
#include "gtest/gtest.h"

TEST(utf8_length, one_byte) {
    char dollar[] = "$! This is a dollar sign";
    EXPECT_EQ(1, utf8_length(dollar));
}

TEST(utf8_length, two_bytes) {
    char cent[] = "\u00A2! This is a cent sign";
    EXPECT_EQ(2, utf8_length(cent));
}

TEST(utf8_length, three_bytes) {
    char ruble[] = "\u20BD! This is a ruble sign";
    EXPECT_EQ(3, utf8_length(ruble));
}

TEST(utf8_length, four_bytes) {
    char hwair[] =
        "\U00010348! This is a hwair letter, I copied it from the Wikipedia";
    EXPECT_EQ(4, utf8_length(hwair));
}

TEST(utf8_length, wrong_utf8_start) {
    char ruble[] = "\u20BD! This is a ruble sign";
    EXPECT_EQ(-1, utf8_length(ruble + 1));
    EXPECT_EQ(-1, utf8_length(ruble + 1));
}

TEST(utf8_compare, one_byte) {
    char keks[] = "keks";
    char qeq[] = "qeq";

    EXPECT_FALSE(utf8_compare(keks, keks));
    EXPECT_TRUE(utf8_compare(keks, qeq));
    EXPECT_FALSE(utf8_compare(qeq, keks));
}

TEST(utf8_compare, two_bytes) {
    char yes[] = "\u0414\u0410";      // "YES" in russian
    char no[] = "\u041D\u0415\u0422"; // "NO" in russian
    char ok[] = "ok";

    // two-byte symbols is not less than itself.
    EXPECT_FALSE(utf8_compare(yes, yes));

    // two-byte symbols are correctly compared.
    EXPECT_TRUE(utf8_compare(yes, no));
    EXPECT_FALSE(utf8_compare(no, yes));

    // two-byte symbol is greater than one-byte symbol
    EXPECT_TRUE(utf8_compare(ok, yes));
    EXPECT_FALSE(utf8_compare(yes, ok));
}

TEST(utf8_compare, three_four_bytes) {
    char hwair[] = "\U00010348";
    char x[] = "\U00010347"; // another gothic symbol
    char ruble[] = "\u20BD";

    EXPECT_FALSE(utf8_compare(hwair, hwair));

    // two-byte symbols are correctly compared.
    EXPECT_FALSE(utf8_compare(hwair, x));
    EXPECT_TRUE(utf8_compare(x, hwair));

    // four-byte symbol is greater than three-byte symbol and one-byte one
    EXPECT_TRUE(utf8_compare(ruble, hwair));
    EXPECT_FALSE(utf8_compare(hwair, ruble));
    EXPECT_TRUE(utf8_compare("o", hwair));
    EXPECT_FALSE(utf8_compare(hwair, "o"));
}

TEST(utf8_equal, some_tests) {
    EXPECT_TRUE(utf8_equal("i", "i"));
    EXPECT_TRUE(utf8_equal("\u20BD", "\u20BD")); // ruble and ruble
    EXPECT_FALSE(utf8_equal("\u20BD", "\U00010348")); // ruble and hwair
}

TEST(utf8_is_letter, latin) {
    EXPECT_TRUE(utf8_is_letter("a"));
    EXPECT_TRUE(utf8_is_letter("z"));
    EXPECT_TRUE(utf8_is_letter("A"));
    EXPECT_TRUE(utf8_is_letter("Z"));

    EXPECT_FALSE(utf8_is_letter("*"));
    EXPECT_FALSE(utf8_is_letter("0"));
}

TEST(utf8_is_letter, cyrillic) {
    EXPECT_TRUE(utf8_is_letter("я"));
    EXPECT_TRUE(utf8_is_letter("Ё"));
    EXPECT_TRUE(utf8_is_letter("ъ"));
    EXPECT_FALSE(utf8_is_letter("$"));
    EXPECT_FALSE(utf8_is_letter("\u20BD")); // ruble sign
}

TEST(utf8_find_next, one_byte) {
    char ok[] = "okay";
    EXPECT_EQ(ok + 1, utf8_find_next(ok));
    EXPECT_EQ(ok + 2, utf8_find_next(ok + 1));
}

TEST(utf8_find_next, two_bytes) {
    char yes[] = "\u0414\u0410"; // "YES" in russian
    EXPECT_EQ(yes + 2, utf8_find_next(yes));
    EXPECT_EQ(yes + 2, utf8_find_next(yes + 1));
}

TEST(utf8_find_next, three_bytes) {
    char ruble[] = "\u20BD! This is a ruble sign";
}
