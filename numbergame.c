#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

int main(){
    
    time_t t; 
    // random time 
    srand((unsigned) time(&t));
    // declare file 
    FILE *file;

    //set static maxNumber
    static int maxNumber = 10;
    // create string array of size 10 char
    char buff [10];
    // open file name "numbergame.txt"
    file = fopen("numbergame.txt", "r");
    if(file == NULL){
        //file does not exist, keep Maxnumber
        maxNumber = maxNumber;

    }
    else{
        //if file exist then read the first input on file
        fgets(buff,10, file);
        maxNumber = buff[0];
        //close file
        fclose(file);

    }

      // select guessNumber to be random
    int guessNumber = rand() % maxNumber; 
    // print out choice menu 
    printf("Press 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\n");
    // declare and intialize user input at 0 
    int userInput = 0; 
    // take in user input for the menu selection 
    scanf("%d", &userInput);
    char userguess[20]; 
    int guessValue; 
    if(userInput == 1){
        // if selected 1, begin this if statement 
        printf("Pick a number between 1 and %d. ", maxNumber); 
        scanf("%s", &userguess);
        if(strcmp("q", userguess) == 0){
//if q is enter return to menu
            main();
        } 
        else{
            guessValue = atoi(userguess);
        }

     // if the user guess is not equal to the correct answer
        while(guessValue != guessNumber){
            //if the user input is less than the guess number, request a larger number 
            while(guessValue < guessNumber){
                printf("Pick a larger number!\n");
                // take user input 
                scanf("%s", &userguess);
                if(strcmp("q", userguess) == 0){
                    main();
                }
                guessValue = atoi(userguess);
            }
            //if user guess is larger than guess number, request a smaller number 
            while(guessValue > guessNumber){
                printf("Pick a smaller Number!\n");
                // take user input 
                scanf("%s", &userguess);

                if(strcmp("q", userguess) == 0){
                    main();
                }
                guessValue = atoi(userguess);
            }
        }
        //if player got the number correct
        printf("Congraulations! You got the right number!\n");
        // use a recursive call
        main(); 
    }
    // if user input =2, move into menu to change the max number 
    else if(userInput == 2){
        // declare new temp integer 
        int tempnumber; 
        int highestnumber =100;
        // request a new max number 
        printf("Pick a new Max Number between 0 and 100! ");
        // take user input for the temp integer 
        scanf("%d", &tempnumber); 
        if(tempnumber>0 && tempnumber< highestnumber){
            // replace max number with the temp integer 
            maxNumber = tempnumber; 

            FILE *file;
            file = fopen("numbergame.txt", "w");
            putw(maxNumber,file);
            fclose(file);

             // send message declaring new max number is made 
            printf("\nThe New Max Number is %d\n", maxNumber); 
            // use another recursive call 
            main();
        }
        else{
            // number input was not within the parameters, so it returns 
            printf("Number does not meet the parameters! The Max Number will stay as %d",maxNumber);
            // return to menu, use recursive 
            main();
        }
    }
    // if input is 3, exit the program 
    else if(userInput == 3){
        printf("Thanks for playing!");
        return 0; 
    }
    return 0; 
}