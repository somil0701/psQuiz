#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

// Structure to store question data
typedef struct
{
    char content[100];
    char correct_option;
    char option_A[100];
    char option_B[100];
    char option_C[100];
    char option_D[100];
} question;

// Function to Calculate No of Digits in User balance

int digitsInBalance(int user_balance)
{
    static int user_balance_length;
    while (user_balance > 1)
    {
        user_balance = user_balance / 10;
        user_balance_length++;
    }
    return user_balance_length;
}

// Function to Operate Audience Poll Lifeline
char lifelineAudiencePoll(char correct_option)
{
    srand(time(0));
    char arr_of_options[] = {'A', 'B', 'C', 'D'};
    char random_option = arr_of_options[(rand() % 4)];
    int random_number;
    int chance_factor = 90;
    random_number = rand() % 10;

    chance_factor += random_number;
    if (chance_factor > 90)
        return correct_option;

    else
        return random_option;
}

// Function to Operate 50:50 Lifeline
char *lifeline5050(char correct_option)
{
    static char random_options[2];
    char arr_of_options[] = {'A', 'B', 'C', 'D'};
    int random_number, random_number2;
generateAgain:
    srand(time(0));
    random_number = rand()%4;
    random_number2 = rand()%4;


    if(arr_of_options[random_number] == correct_option || arr_of_options[random_number2] == correct_option)
        goto generateAgain;
    
    if (random_number != random_number2){
        random_options[0] = arr_of_options[random_number];
        random_options[1] = arr_of_options[random_number2];
        return random_options;
    }
    
    else
        goto generateAgain;
    
}

// Function to Print a Board showing user's status
void printStatusboard(int user_balance, int user_balance_length, int user_audiencepoll, int user_5050)
{
    printf("+-------------------");
    for (int i = 0; i < user_balance_length; i++)
        printf("-");
    printf("+\n");
    printf("| Balance - Rs. %d", user_balance);
    for (int i = 0; i < user_balance_length; i++)
        printf(" ");
    printf("\n");
    printf("+-------------------");
    for (int i = 0; i < user_balance_length; i++)
        printf("-");
    printf("+\n");
    printf("| Audience Pole (%d)", user_audiencepoll);
    for (int i = 0; i < user_balance_length + 1; i++)
        printf(" ");
    printf("|\n");
    printf("| 50:50 (%d)        ", user_5050);
    for (int i = 0; i < user_balance_length + 1; i++)
        printf(" ");
    printf("|\n");
    printf("+-------------------");
    for (int i = 0; i < user_balance_length; i++)
        printf("-");
    printf("+\n");
}

// Function to Print a Set of Questions
void printQuestions(char *question_content, char correct_option, char *option_A, char *option_B, char *option_C, char *option_D)
{
    printf("Q: %s?\n", question_content);
    printf("(A) %s\n", option_A);
    printf("(B) %s\n", option_B);
    printf("(C) %s\n", option_C);
    printf("(D) %s\n", option_D);
}

// Function to Check The User's Answer
bool answerChecker(char correct_option, char user_input)
{
    if (user_input == correct_option)
        return true;
    else
        return false;
}

// Main Starts Here
int main()
{
    // Declaring Variables

    starting:
    question question_1, question_2, question_3, question_4, question_5;
    int user_balance = 0;
    int user_score = 0;
    int user_audiencepoll = 1;
    int user_5050 = 1;
    int user_balance_length = digitsInBalance(user_balance);
    char user_input, user_input2;
    char player_name[50];
    char arr_of_incorrect_options[2];

    // Assigning Questions and Their Options

    strcpy(question_1.content, "Who was Napolean Bonaparte");
    strcpy(question_1.option_A, "Hero");
    strcpy(question_1.option_B, "Villan");
    strcpy(question_1.option_C, "Clown");
    strcpy(question_1.option_D, "Weeb");
    question_1.correct_option = 'C';

    strcpy(question_2.content, "Who was Uzumaki Naruto");
    strcpy(question_2.option_A, "Hero");
    strcpy(question_2.option_B, "Villan");
    strcpy(question_2.option_C, "Clown");
    strcpy(question_2.option_D, "Weeb");
    question_2.correct_option = 'A';

    strcpy(question_3.content, "Who was Eren Yeager");
    strcpy(question_3.option_A, "Hero");
    strcpy(question_3.option_B, "Villan");
    strcpy(question_3.option_C, "Clown");
    strcpy(question_3.option_D, "Weeb");
    question_3.correct_option = 'B';

    strcpy(question_4.content, "Who was Kurosaki Ichigo");
    strcpy(question_4.option_A, "Hero");
    strcpy(question_4.option_B, "Villan");
    strcpy(question_4.option_C, "Clown");
    strcpy(question_4.option_D, "Weeb");
    question_4.correct_option = 'A';

    strcpy(question_5.content, "Who was Luffy D Monkey");
    strcpy(question_5.option_A, "Hero");
    strcpy(question_5.option_B, "Villan");
    strcpy(question_5.option_C, "Clown");
    strcpy(question_5.option_D, "Weeb");
    question_5.correct_option = 'A';

// Loop Starts Here


    printf("Greeings Player! Enter Your Name to further proceed with the QUIZ!: ");
    scanf("%s", player_name);

    while (true)
    {
        system("clear");
        // Printing the Status Board
        printStatusboard(user_balance, user_balance_length, user_audiencepoll, user_5050);

        // Printing the Question

        switch (user_score)
        {
        case 0:
            printQuestions(question_1.content, question_1.correct_option, question_1.option_A, question_1.option_B, question_1.option_C, question_1.option_D);
            break;

        case 1:
            printQuestions(question_2.content, question_2.correct_option, question_2.option_A, question_2.option_B, question_2.option_C, question_2.option_D);
            break;

        case 2:
            printQuestions(question_3.content, question_3.correct_option, question_3.option_A, question_3.option_B, question_3.option_C, question_3.option_D);
            break;

        case 3:
            printQuestions(question_4.content, question_4.correct_option, question_4.option_A, question_4.option_B, question_4.option_C, question_4.option_D);
            break;

        case 4:
            printQuestions(question_5.content, question_5.correct_option, question_5.option_A, question_5.option_B, question_5.option_C, question_5.option_D);
            break;

        default:
            printf("Game is Over! You Won %d \n", user_balance);
            goto starting;
            break;
        }

    // Taking Answer Inupt from the User
    takinginputagain:
        printf("Your Input? (l  A/B/C/D): ");
        scanf("\n%c", &user_input);

        // Using Lifeline function(if used by the user)
        if (user_input == 'l')
        {
            if (user_5050 == 0 && user_audiencepoll == 0){
                printf("You don't have any lifelines left.... \n");
                goto takinginputagain;}
            printf("Which Lifeline do you want to use? \n");
            printf("Press 1 for Audience Poll \n");
            printf("Press 2 for 50:50 \n");
            
            scanf("\n%c", &user_input2);
            if (user_input2 == '1' && user_audiencepoll == 0){
                printf("You don't have Audience Poll Lifeline... \n");
                user_input2 = '\0';
                goto takinginputagain;
            }
            if (user_input2 == '2' && user_5050 == 0){
                printf("You don't have 50:50 Lifeline.... \n");
                user_input2 = '\0';
                goto takinginputagain;
            }
        }

        // Condition for Using Audience Poll Lifeline
        if (user_input2 == '1' && user_audiencepoll!=0)
        {
            switch (user_score)
            {
            case 0:
                printf("The majority of the audience vouches for Option %c\n",
                       lifelineAudiencePoll(question_1.correct_option));
                user_audiencepoll = 0;
                user_input2 = '\0';
                goto takinginputagain;
                break;
            case 1:
                printf("The majority of the audience vouches for Option %c\n",
                       lifelineAudiencePoll(question_2.correct_option));
                user_audiencepoll = 0;
                user_input2 = '\0';
                goto takinginputagain;
                break;
            case 2:
                printf("The majority of the audience vouches for Option %c\n",
                       lifelineAudiencePoll(question_3.correct_option));
                user_audiencepoll = 0;
                user_input2 = '\0';
                goto takinginputagain;
                break;
            case 3:
                printf("The majority of the audience vouches for Option %c\n",
                       lifelineAudiencePoll(question_4.correct_option));
                user_audiencepoll = 0;
                user_input2 = '\0';
                goto takinginputagain;
                break;
            case 4:
                printf("The majority of the audience vouches for Option %c\n",
                       lifelineAudiencePoll(question_5.correct_option));
                user_audiencepoll = 0;
                user_input2 = '\0';
                goto takinginputagain;
                break;

            default:
                break;
            }
        }

        // Condition for Genrating 50:50 Lifeline
        if (user_input2 == '2' && user_5050!=0)
        {
            switch (user_score)
            {
            case 0:
                arr_of_incorrect_options[0] = *lifeline5050(question_1.correct_option);
                arr_of_incorrect_options[1] = *(lifeline5050(question_1.correct_option) + 1);
                printf("Options which are incorrect are: %c, %c\n", arr_of_incorrect_options[0], arr_of_incorrect_options[1]);
                user_5050 = 0;
                user_input2 = '\0';
                goto takinginputagain;
                break;

            case 1:
                arr_of_incorrect_options[0] = *lifeline5050(question_2.correct_option);
                arr_of_incorrect_options[1] = *(lifeline5050(question_2.correct_option) + 1);
                printf("Options which are incorrect are: %c, %c\n", arr_of_incorrect_options[0], arr_of_incorrect_options[1]);
                user_5050 = 0;
                user_input2 = '\0';
                goto takinginputagain;
                break;

            case 2:
                arr_of_incorrect_options[0] = *lifeline5050(question_3.correct_option);
                arr_of_incorrect_options[1] = *(lifeline5050(question_3.correct_option) + 1);
                printf("Options which are incorrect are: %c, %c\n", arr_of_incorrect_options[0], arr_of_incorrect_options[1]);
                user_5050 = 0;
                user_input2 = '\0';
                goto takinginputagain;
                break;

            case 3:
                arr_of_incorrect_options[0] = *lifeline5050(question_4.correct_option);
                arr_of_incorrect_options[1] = *(lifeline5050(question_4.correct_option) + 1);
                printf("Options which are incorrect are: %c, %c\n", arr_of_incorrect_options[0], arr_of_incorrect_options[1]);
                user_5050 = 0;
                user_input2 = '\0';
                goto takinginputagain;
                break;

            case 4:
                arr_of_incorrect_options[0] = *lifeline5050(question_5.correct_option);
                arr_of_incorrect_options[1] = *(lifeline5050(question_5.correct_option) + 1);
                printf("Options which are incorrect are: %c, %c\n", arr_of_incorrect_options[0], arr_of_incorrect_options[1]);
                user_5050 = 0;
                user_input2 = '\0';
                goto takinginputagain;
                break;

            default:
                break;
            }
        }

        // Checking if the User's Answer is Correct or Not

        switch (user_score)
        {
        case 0:
            if (answerChecker(question_1.correct_option, toupper(user_input)))
            {
                printf("Correct Answer! :)\n");
                user_score++;
                if (user_balance == 0)
                    user_balance = 2000;
                else
                    user_balance = user_balance * 2;
            }

            else
            {
                printf("Wrong Answer! :(\n");
                user_score = 0;
                user_balance = 0;
                break;
            }
            break;

        case 1:
            if (answerChecker(question_2.correct_option, toupper(user_input)))
            {
                printf("Correct Answer! :)\n");
                user_score++;
                if (user_balance == 0)
                    user_balance = 2000;
                else
                    user_balance = user_balance * 2;
            }

            else
            {
                printf("Wrong Answer! :(\n");
                user_score = 0;
                user_balance = 0;
                break;
            }
            break;

        case 2:
            if (answerChecker(question_3.correct_option, toupper(user_input)))
            {
                printf("Correct Answer! :)\n");
                user_score++;
                if (user_balance == 0)
                    user_balance = 2000;
                else
                    user_balance = user_balance * 2;
            }

            else
            {
                printf("Wrong Answer! :(\n");
                user_score = 0;
                user_balance = 0;
                break;
            }
            break;

        case 3:
            if (answerChecker(question_4.correct_option, toupper(user_input)))
            {
                printf("Correct Answer! :)\n");
                user_score++;
                if (user_balance == 0)
                    user_balance = 2000;
                else
                    user_balance = user_balance * 2;
            }

            else
            {
                printf("Wrong Answer! :(\n");
                user_score = 0;
                user_balance = 0;
                break;
            }
            break;

        case 4:
            if (answerChecker(question_5.correct_option, toupper(user_input)))
            {
                printf("Correct Answer! :)\n");
                user_score++;
                if (user_balance == 0)
                    user_balance = 2000;
                else
                    user_balance = user_balance * 2;
            }

            else
            {
                printf("Wrong Answer! :(\n");
                user_score = 0;
                user_balance = 0;
                break;
            }
            break;

        default:
            printf("Game is Over! You Won %d \n", user_balance);
            goto starting;
            break;
        }
    }

    return 0;
}