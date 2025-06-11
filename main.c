#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void display_banner(){
    FILE *file;
    char line[256];

    file = fopen("src/ascii_art.txt", "r");
    if (file != NULL) {
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("\n\nWelcome to the Number Guessing Game!\n");
    }
}

int attempt() {
    int guess;
    printf("\n\nGuess a number between 1 and 100: ");
    scanf("%d", &guess);
    return guess;
}

void win(){
    printf("\n====================================");
    printf("\nCongratulations ! You guessed it !!!");
    printf("\n====================================");

}

void lose(){
    printf("\n=========================================");
    printf("\nUps, you lose...Better luck next time !!!");
    printf("\n=========================================");

}

void playAgain(bool *gameIsRunning){
            char again;
        printf("\n\nWould you like to play again? (Y/N): ");
        scanf(" %c", &again);
        printf("\n\n");

        if (again == 'N' || again == 'n') {
            *gameIsRunning = false;
        }
}


int main(){

    bool gameIsRunning = true;
    bool won = false;
    int guess;
    int attempt_num;
    int rand_num;
    int min = 1;
    int max = 100;

    
    while(gameIsRunning){
        for(int i = 0; i < 10; i++){
            if(i == 0){
                srand(time(NULL));
                rand_num = (rand() % (max - min + 1)) + min;
                attempt_num = 10;
                display_banner();
                printf("\n\nYou have a total of %d attempts to guess the number. GOOD LUCK !!!\n", attempt_num);
            }
            guess = attempt();

                if(guess != rand_num){
                        if(guess > rand_num){
                                attempt_num -= 1;
                                printf("\nTO HIGH !\n");
                                printf("You have %d attempts left.\n", attempt_num);

                        }else if(guess < rand_num){
                                attempt_num -= 1;
                                printf("\nTO LOW !\n");
                            if(attempt_num >= 1){
                                printf("You have %d attempts left.\n", attempt_num);
                            }
                        }
                } else if (guess == rand_num){
                    win();
                    won = true;
                    playAgain(&gameIsRunning);
                    if (!gameIsRunning) break;
                    else break; 
                }
        }
                if(!won){
                    lose();
                    playAgain(&gameIsRunning);
                    if (!gameIsRunning) {
                        printf("\nThanks for playing! See you next time!\n");
                    break;
                }
                
                }
    }

    return 0;
}