#include <stdio.h>
#include <stdbool.h>

int transition(int currentState, char input);

bool simulateNFA(char *input);

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (simulateNFA(input)) {
        printf("The string \"%s\" is accepted.\n", input);
    } else {
        printf("The string \"%s\" is not accepted.\n", input);
    }

    return 0;
}

int transition(int currentState, char input) {
    switch (currentState) {
        case 0:
            if (input == 'o') return 1;
            else return -1;
        case 1:
            return (input == '1') ? 2 : -1;
        default:
            return -1;
    }
}

bool simulateNFA(char *input) {
    int currentState = 0;
    int i = 0;

    while (input[i] != '\0') {
        currentState = transition(currentState, input[i]);
        if (currentState == -1) {
            return false;
        }
        i++;
    }

    return currentState == 2;
}
