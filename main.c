#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(int computer, int user) {
    if (computer == user) {
        return -1;
    }
    // 0 ROCK 1 PAPER 2 SCISSOR
    if(computer == 0 && user == 2) {
        return 0;  // ROCK PAPER (LOSE)
    } else if (computer == 0 && user == 3) {
        return 0; // ROCK SCISSOR (LOSE)
    } else if (computer == 1 && user == 1) {
        return 1; // PAPER ROCK (WIN)
    } else if (computer == 1 && user == 3) {
        return 1; // PAPER SCISSOR (WIN)
    } else if (computer == 2 && user == 1) {
        return 1; // SCISSOR ROCK (WIN)
    } else if (computer == 2 && user == 2) {
        return 0; // SCISSOR PAPER
    }
}

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

    int result = game(computerChoice, choice);

    printf("YOU: %d vs COMPUTER: %d\n", choice, computerChoice);
    
    if(result == -1) {
        printf("Game Draw!\n");
    } else if(result == 1) {
        printf("Congratulations! You have won the game.\n");
    } else {
        printf("OH! You have lost the game!\n");
    }

    

    return 0;
}