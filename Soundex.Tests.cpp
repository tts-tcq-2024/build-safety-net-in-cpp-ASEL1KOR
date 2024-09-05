// Test for non-alphabetic symbols and numbers
TEST(SoundexTest, HandlesNumbersAndSymbols) {
    EXPECT_EQ(generateSoundex("A123"), "A000"); // Numbers should be ignored
    EXPECT_EQ(generateSoundex("B@#$"), "B000"); // Special characters should be ignored
}

// Test for special characters at the start of the name
TEST(SoundexTest, HandlesNameStartingWithSpecialCharacters) {
    EXPECT_EQ(generateSoundex("!Bob"), "B100"); // Special characters should be ignored at the beginning
}

// Test for mixed alphabetic and numeric input
TEST(SoundexTest, HandlesAlphanumericInput) {
    EXPECT_EQ(generateSoundex("A1B2"), "A100"); // Alphanumeric mixed with letters
}

// Test for minimum valid input length (1 character)
TEST(SoundexTest, HandlesOneCharacter) {
    EXPECT_EQ(generateSoundex("Q"), "Q000");
}

// Test for a name with exactly 4 characters
TEST(SoundexTest, HandlesExactLength) {
    EXPECT_EQ(generateSoundex("Ray"), "R000"); // Only 'R' and no other consonants
    EXPECT_EQ(generateSoundex("Test"), "T230");
}

// Test for different special character handling
TEST(SoundexTest, HandlesMultipleSpecialCharactersInName) {
    EXPECT_EQ(generateSoundex("A@pp#le"), "A140");
}

// Test for cases where the name ends with a vowel
TEST(SoundexTest, HandlesNameEndingWithVowel) {
    EXPECT_EQ(generateSoundex("Boi"), "B000");
}



