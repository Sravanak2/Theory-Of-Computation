#include <stdio.h>
#include <string.h>
int dfa(char *input) {
    int state = 0; 
	int i;
    for ( i = 0; i < strlen(input); i++) {
        if (input[i] != 'a' && input[i] != 'b') {
            return 0; 
        }
        if (state == 0) {
            if (input[i] == 'a') {
                state = 1; 
            } else {
                state = 2; 
            }
        } else if (state == 1) {
            if (input[i] == 'a') {
                state = 2; 
            } else {
                state = 1; 
            }
        } else if (state == 2) {
            if (input[i] == 'a') {
                state = 2; 
            } else {
                return 0;
            }
        }
    }
    if (state == 2) {
        return 1; 
    } else {
        return 0;
    }
}
int main() {
    char input[100];
    printf("Enter the string: ");
    scanf("%s", input);
    if (dfa(input)) {
        printf("String Accepted.\n");
    } else {
        printf("String  not Accepted.\n");
    }
    return 0;
}
