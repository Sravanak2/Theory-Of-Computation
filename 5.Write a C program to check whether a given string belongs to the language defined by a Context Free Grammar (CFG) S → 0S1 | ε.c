#include <stdio.h>
#include <stdbool.h>

bool matchS(char *input);

bool matchS(char *input) {
    if (input[0] == '0') {
        int i = 1;
        while (input[i] == '0') {
            i++;
        }
        if (input[i] == '1') {
            return matchS(input + i + 1);
        } else {
            return false; 
        }
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
