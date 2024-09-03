#include <gtest/gtest.h>
#include "Soundex.h"

// Test for empty string input
TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

// Test for single character input
TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

// Test for a name with characters mapping to the same code
TEST(SoundexTest, HandlesDuplicateCodes) {
    EXPECT_EQ(generateSoundex("BFPV"), "B100");
    EXPECT_EQ(generateSoundex("CGJKQSXZ"), "C200");
}

// Test for a name with mixed character codes and length greater than 4
TEST(SoundexTest, HandlesMixedCodes) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
}

// Test for names that contain non-alphabetic characters
TEST(SoundexTest, HandlesNonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("O'Hara"), "O600");
}

// Test for a name with only vowels
TEST(SoundexTest, HandlesVowelsOnly) {
    EXPECT_EQ(generateSoundex("Aeio"), "A000");
}

// Test for names with a mix of upper and lower case letters
TEST(SoundexTest, HandlesMixedCaseInput) {
    EXPECT_EQ(generateSoundex("Washington"), "W252");
    EXPECT_EQ(generateSoundex("Lee"), "L000");
}

// Test for a name with repeating characters that should result in a single code
TEST(SoundexTest, HandlesRepeatingCharacters) {
    EXPECT_EQ(generateSoundex("Lloyd"), "L300");
}

// Test for a name with a long sequence that should be truncated
TEST(SoundexTest, HandlesLongNames) {
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
}


