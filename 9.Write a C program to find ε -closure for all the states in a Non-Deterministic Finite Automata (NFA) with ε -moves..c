#include <stdio.h>
#include <stdbool.h>

// Constants
#define MAX_STATES 50
#define MAX_TRANSITIONS 50

// Function prototypes
void findEpsilonClosure(int n, int transitions[MAX_STATES][MAX_TRANSITIONS], int epsilonClosure[MAX_STATES][MAX_STATES]);

int main() {
    int n; // Number of states
    int m; // Number of transitions
    int transitions[MAX_STATES][MAX_TRANSITIONS]; // Transition function
    int epsilonClosure[MAX_STATES][MAX_STATES]; // ε-closure

    // Input: Number of states and transitions
    printf("Enter the number of states: ");
    scanf("%d", &n);

    printf("Enter the number of transitions: ");
    scanf("%d", &m);

    // Input: Transition function
    printf("Enter the transition function (use -1 to represent no transition):\n");
    for (int i = 0; i < n; i++) {
        printf("State %d:", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &transitions[i][j]);
        }
    }

    // Find ε-closure
    findEpsilonClosure(n, transitions, epsilonClosure);

    // Output ε-closure for each state
    printf("Epsilon Closure for each state:\n");
    for (int i = 0; i < n; i++) {
        printf("ε-Closure(%d): { ", i);
        for (int j = 0; j < n; j++) {
            if (epsilonClosure[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("}\n");
    }

    return 0;
}

void findEpsilonClosure(int n, int transitions[MAX_STATES][MAX_TRANSITIONS], int epsilonClosure[MAX_STATES][MAX_STATES]) {
    for (int i = 0; i < n; i++) {
        // Initialize visited array for each state
        int visited[MAX_STATES] = {0};

        // DFS to find ε-closure for state i
        int stack[MAX_STATES];
        int top = -1;

        stack[++top] = i;
        visited[i] = 1;

        while (top != -1) {
            int current = stack[top--];

            for (int j = 0; j < n; j++) {
                if (transitions[current][j] == -1) {
                    continue; // No transition
                }

                if (visited[j] == 0 && transitions[current][j] == 0) {
                    stack[++top] = j;
                    visited[j] = 1;
                    epsilonClosure[i][j] = 1;
                }
            }
        }
    }
}
