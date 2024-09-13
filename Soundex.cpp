#include <string>
#include <unordered_map>
#include <cctype>

// Function to create the Soundex mapping
std::unordered_map<char, char> createSoundexMap() {
    return {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
}

// Function to get the Soundex code for a character
char getSoundexCode(char c, const std::unordered_map<char, char>& soundexMap) {
    char upperChar = std::toupper(c);
    if (soundexMap.find(upperChar) != soundexMap.end()) {
        return soundexMap.at(upperChar);
    }
    return '0'; // Non-mapped characters like vowels return '0'
}

// Main Soundex generation function
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::unordered_map<char, char> soundexMap = createSoundexMap();
    std::string result(1, std::toupper(name[0]));

    char previousCode = '0';
    for (size_t i = 1; i < name.length(); ++i) {
        char currentCode = getSoundexCode(name[i], soundexMap);

        if (currentCode != '0' && currentCode != previousCode) {
            result += currentCode;
            previousCode = currentCode;
        }
    }

    // Ensure the result is exactly four characters long
    result = result.substr(0, 4);
    while (result.length() < 4) {
        result += '0';
    }

    return result;
}
