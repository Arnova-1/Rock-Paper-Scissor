#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char buffer[16];

    printf("--------------------\n"
        " ROCK PAPER SCISSOR\n"
        "--------------------\n"
        "[1] ROCK\n"
        "[2] PAPER\n"
        "[3] SCISSOR\n"
    );

    while(1) {
        printf("Enter the corresponding number to select Rock, Paper, or Scissor: ");
        
        if(!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Input error. Exiting...\n");
            return 1;
        }

        if(sscanf(buffer, "%d", &choice) == 1 && (choice == 1 || choice == 2 || choice == 3)) {
            break;
        } else {
            printf("Invalid input. Please enter 1, 2 or 3.\n");
        }
    };

    srand(time(NULL));

    int computerChoice = rand() % 3;

    return 0;
}

int game(int computer, int user) {

    if (computer == user) {
        return -1;
    }
}