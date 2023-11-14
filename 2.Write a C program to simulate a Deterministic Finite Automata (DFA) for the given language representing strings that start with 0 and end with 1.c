#include <stdio.h>
#include <string.h>

int transition(int state, char input) {
    if (state == 0 && input == '0') return 1;
    if (state == 1 && input == '1') return 2;
    return -1;
}
int dfa(char *input) {
    int state = 0; 
    for (int i = 0; i < strlen(input); i++) {
        state = transition(state, input[i]);
        if (state == -1) return 0; 
    }
    return (state == 2); 
}

int main() {
    char input[100];
    printf("Enter the string: ");
    scanf("%s", input);

    if (dfa(input)) {
        printf("The string is in the language.\n");
    } else {
        printf("The string is not in the language.\n");
    }

    return 0;
}
