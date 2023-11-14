#include <stdio.h>
#include <string.h>

int check(char *str) {
    int state = 0;

    for (int i = 0; str[i]; i++) {
        if (state == 0 && str[i] == 'b')
            state = 1;
        else if (state == 1 && str[i] == 'a')
            state = 2;
        else if (state == 2 && str[i] == 'a')
            state = 2;
        else if (state == 1 && str[i] == 'b')
            state = 1;
        else
            return 0;
    }

    return state == 2;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (check(str))
        printf("The string belongs to the language.\n");
    else
        printf("The string does not belong to the language.\n");

    return 0;
}
