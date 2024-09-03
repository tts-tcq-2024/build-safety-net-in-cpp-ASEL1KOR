#include <string>
#include <unordered_map>
#include <cctype>

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::unordered_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };

    std::string result;
    result += std::toupper(name[0]);

    char previousCode = '0'; // To track previous code for duplicates
    for (size_t i = 1; i < name.length(); ++i) {
        char currentChar = std::toupper(name[i]);

        if (soundexMap.find(currentChar) != soundexMap.end()) {
            char currentCode = soundexMap[currentChar];

            if (currentCode != previousCode) {
                result += currentCode;
            }

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
