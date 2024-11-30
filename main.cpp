#include <iostream>
#include <cstring>
char* remove_repeated(const char str1[], const char str2[]) {
    int full_size = strlen(str1) + strlen(str2);
    char* result = new char[full_size + 1];
    int last_index = 0;
    for (int i = 0; i < strlen(str1); i++) {
        bool is_repeated = false;
        for (int j = 0; j < strlen(str2); j++) {
            if (str1[i] == str2[j]) {
                is_repeated = true;
                break;
            }
        }
        if (!is_repeated) {
            result[last_index++] = str1[i];
        }
    }
    for (int i = 0; i < strlen(str2); i++) {
        bool is_repeated = false;
        for (int j = 0; j < strlen(str1); j++) {
            if (str2[i] == str1[j]) {
                is_repeated = true;
                break;
            }
        }
        if (!is_repeated) {
            result[last_index++] = str2[i];
        }
    }
    result[last_index] = '\0';
    return result;
}
int main() {
    const char* str1 = "lol";
    const char* str2 = "loler";
    char* result = remove_repeated(str1, str2);
    std::cout << "str1: " << str1 << ", str2: " << str2 << ", Result: " << result << std::endl;
    delete[] result;
    return 0;
}
