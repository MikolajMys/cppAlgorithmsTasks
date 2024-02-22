#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string input;
    std::getline(std::cin, input, '^');

    for(unsigned long long i = 0; i < input.length(); i++){
        if (isupper(input[i])) {
            input[i] = tolower(input[i]);
        }
    }

    int count[26] = {0};

    for(char c : input){
        if (isalpha(c)) {
            count[c - 'a']++;
        }
    }

    char max = '\0';
    char min = '\0';
    long int maxInt = 0;
    long int minInt = 0;

    for (int i = 0; i < 26; i++) {
        if (count[i] > maxInt) {
            maxInt = count[i];
            max = i + 'a';
        }
        if (count[i] > 0) {
            if (!min || count[i] < minInt) {
                minInt = count[i];
                min = i + 'a';
            }
        }
    }

    std::cout << max << ' ' << min << '\n';

    return 0;
}