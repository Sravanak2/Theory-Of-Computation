#include <stdio.h>
#include <stdbool.h>

bool matchS(char *input);
bool matchA(char *input);

bool matchS(char *input) {
    if (matchA(input) && input[0] == '1' && input[1] == '0' && input[2] == '1') {
        return matchA(input + 3);
    }
    return false;
}

bool matchA(char *input) {
    if (input[0] == '0') {
        return matchA(input + 1);
    } else if (input[0] == '1') {
        return matchA(input + 1);
    } else {
        return true;
    }
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (matchS(input)) {
        printf("The string \"%s\" belongs to the language.\n", input);
    } else {
        printf("The string \"%s\" does not belong to the language.\n", input);
    }

    return 0;
}
