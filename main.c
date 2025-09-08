#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* choiceMsg(int choice) {
    switch (choice) {
        case 1: return "ROCK";
        case 2: return "PAPER";
        case 3: return "SCISSOR";
        default: return "INVALID";
    }
} 

int game(int computer, int user) {
    if (computer == user) {
        return -1;
    }
    // 1 ROCK 2 PAPER 3 SCISSOR
    if(computer == 1 && user == 2) {
        return 1;  // ROCK PAPER (WIN)
    } else if (computer == 1 && user == 3) {
        return 0; // ROCK SCISSOR (LOSE)
    } else if (computer == 2 && user == 1) {
        return 0; // PAPER ROCK (LOSE)
    } else if (computer == 2 && user == 3) {
        return 1; // PAPER SCISSOR (WIN)
    } else if (computer == 3 && user == 1) {
        return 1; // SCISSOR ROCK (WIN)
    } else if (computer == 3 && user == 2) {
        return 0; // SCISSOR PAPER (LOSE)
    }
}

int main() {
    int choice;
    char buffer[16];

    printf("====================\n"
        " ROCK PAPER SCISSOR\n"
        "====================\n"
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

    int computerChoice = rand() % 3 + 1;

    int result = game(computerChoice, choice);

    printf("----------------------------------------\n"
        "YOU: %s vs COMPUTER: %s\n", choiceMsg(choice), choiceMsg(computerChoice));

    if(result == -1) {
        printf("Game Draw!\n");
    } else if(result == 1) {
        printf("Congratulations! You have won the game.\n");
    } else {
        printf("OH! You have lost the game!\n");
    }

    printf("----------------------------------------\n");

    return 0;
}