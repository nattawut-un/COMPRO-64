#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define NUM(a) (sizeof(a) / sizeof(*a)) // auto find size of array lol

void gameplay(char *word);

void randmai(char *words, int wordsLength);

void randmai(char *words, int wordsLength)
{
    int stackerChecker[wordsLength];
    int counter = 0;

    for (int i = 0; i < wordsLength; i++)
    {
        stackerChecker[i] = -1;
    }

    while (1)
    {
        int checked = 0;
        int random = rand() % wordsLength + 1;

        for (int i = 0; i < sizeof(stackerChecker) / sizeof(1); i++)
        {
            if (stackerChecker[i] == random)
            {
                checked = 1;
            }
        }

        int passed = 1;
        for (int i = 0; i < wordsLength; i++)
        {
            if (stackerChecker[i] == -1)
            {
                passed = 0;
            }
        }

        if (passed == 1)
        {
            break;
        }

        if (checked == 0)
        {
            stackerChecker[counter] = random;
            counter++;
        }
        else
        {
            continue;
        }
    }

    for (int i = 0; i < wordsLength; i++)
    {

        printf("%c ", words[stackerChecker[i] - 1]);
    }
    printf("\n");
}

void gameplay(char *word)
{
    int wordsLength = strlen(word);
    srand(time(0));
    randmai(word, wordsLength);
}

int main()
{
    printf("\n\n\n");
    srand(time(0));

    int score = 0;
    int hp = 3;
    int action;
    int maxRound = 5;
    char currentDifficulty[50][32];

    // vocabulary
    // https://docs.google.com/spreadsheets/d/1aOzZ7S9hzu2j1UsaDbN5wZ8wNBTzzicwgPpWZ_mem3Q/edit#gid=0
    char wordsEZ[50][32] = {"ACCIDENT", "ACTIVITY", "ADVENTURE", "BLANKET", "BRIDGE", "CELEBRATE", "CHURCH", "DANGEROUS", "DONATE",
                            "EDUCATION", "ENERGY", "FUTURE", "FRUIT", "GARLIC", "GHOST", "HAMMER", "HEALTH", "HOSPITAL", "IDEA", "IMPORTANT", "JOB", "JOURNEY",
                            "KNIFE", "LAKE", "LEARN", "MAGIC", "MISTAKE", "NATURE", "NEVER", "OCEAN", "PAINT", "PAIR", "QUICK", "QUIET", "RADIO", "RAIN", "SAFE",
                            "SCREAM", "TASTE", "TELEPHONE", "UNTIL", "USUALLY", "VACATION", "VISIT", "WATERFALL", "WAVE", "YAWN", "YESTERDAY", "ZOO", "ZEBRA"};
    char wordsNM[50][32] = {"ADULT", "ADVANTAGE", "ADVICE", "BALCONY", "BELIEVE", "CALENDAR", "CATEGORY", "DECISION", "DISAPPEAR",
                            "ENVIRONMENT", "ENOUGH", "FAMOUS", "FOREIGN", "GARBAGE", "GENERAL", "HAPPEN", "HEAVEN", "HEAVY", "IDENTITY", "INFORMATION", "JEALOUS",
                            "JUDGE", "KNOWLEDGE", "LABEL", "LANGUAGE", "METHOD", "MUSEUM", "NECESSARY", "NEGATIVE", "OBEY", "OCCUR", "POLLUTION", "POSITIVE", "PREDICT",
                            "QUANTITY", "REALIZE", "RECOGNIZE", "RESULT", "SCHEDULE", "SEPARATE", "STRANGER", "TEMPERATURE", "TERRIBLE", "TROUBLE", "UNIVERSITY",
                            "USEFUL", "VIOLENT", "VISION", "WEATHER", "WEAPON"};
    char wordsHD[50][32] = {"ABANDON", "ABORTION", "ACCOMPANY", "ACCOMPLISH", "BEHAVIOR", "BRILLIANT", "CAUTION", "CEREMONY", "CONTRAST",
                            "DEDICATION", "DEMONSTRATION", "DIVORCE", "ENCOURAGE", "ENSURE", "FAMILIAR", "GENERATE", "GORGEOUS", "HARVEST", "HUMBLE", "ILLEGAL",
                            "IMMIGRANT", "INJURE", "LOYAL", "MAGNIFICENT", "MANUFACTURE", "MINOR", "NUMEROUS", "NUTRITION", "OPPORTUNITY", "ORDINARY", "PARTICULAR",
                            "PREDOMINANT", "PREFER", "QUALIFICATION", "RECOGNIZE", "REGRET", "REMAIN", "RIDICULOUS", "SATISFACTION", "SLIGHTLY", "SUBSTANCE", "SUBSTITUTE",
                            "SUBURB", "SUPERVISOR", "TRIAL", "TROPICAL", "UNIQUE", "URBAN", "VALID", "VALUABLE"};

    printf("**************************************************************************************\n");
    printf("**************************************************************************************\n\n");

    printf("  ______   _______    ______          ______    ______   __       __  ________\n");
    printf(" /      \\ /       \\  /      \\        /      \\  /      \\ /  \\     /  |/        |\n");
    printf("/$$$$$$  |$$$$$$$  |/$$$$$$  |      /$$$$$$  |/$$$$$$  |$$  \\   /$$ |$$$$$$$$/ \n");
    printf("$$ |__$$ |$$ |__$$ |$$ |  $$/       $$ | _$$/ $$ |__$$ |$$$  \\ /$$$ |$$ |__    \n");
    printf("$$    $$ |$$    $$< $$ |            $$ |/    |$$    $$ |$$$$  /$$$$ |$$    |   \n");
    printf("$$$$$$$$ |$$$$$$$  |$$ |   __       $$ |$$$$ |$$$$$$$$ |$$ $$ $$/$$ |$$$$$/    \n");
    printf("$$ |  $$ |$$ |__$$ |$$ \\__/  |      $$ \\__$$ |$$ |  $$ |$$ |$$$/ $$ |$$ |_____ \n");
    printf("$$ |  $$ |$$    $$/ $$    $$/       $$    $$/ $$ |  $$ |$$ | $/  $$ |$$       |\n");
    printf("$$/   $$/ $$$$$$$/   $$$$$$/         $$$$$$/  $$/   $$/ $$/      $$/ $$$$$$$$/ \n\n");

    printf("**************************************************************************************\n");
    printf("**************************************************************************************\n\n");

    while (1) {
        printf("[1] EASY\n[2] NORMAL\n[3] HARD\n\n[4] CHANGE AMOUNT OF ROUNDS (current: %d)\n[5] CHANGE AMOUNT OF HP (current: %d)\n\n[0] EXIT\n\n", maxRound, hp);
    printf(">> ");
    scanf("%d", &action);
    printf("\n");

    if (action == 0) {
        printf("GOODBYE.\n\n");
        break;
    }
    if (action == 4) {
        printf("AMOUNT OF ROUNDS (number) >> ");
        scanf("%d", &maxRound);
        printf("\n");
        continue;
    }
    if (action == 5) {
        printf("AMOUNT OF HP (number) >> ");
        scanf("%d", &hp);
        printf("\n");
        continue;
    }

    printf("[ START ] ****************************************************************************\n\n");

    switch (action)
    {
    case (1):
        for (int i = 0; i < maxRound; i++)
        {
            int hpRound = hp;
            char answer[64]; //Storing user input
            int randomNumber = rand() % NUM(wordsEZ); //Random a words from string array
            char randomWord[101]; 
            strcpy(randomWord, wordsEZ[randomNumber]); //For saving random words.

            printf("[ WORD %d/%d ]\n\n", i+1, maxRound);

            gameplay(randomWord);

            while (1) {
                printf(">> ");
                scanf("%s", answer);

                if(strcmpi(answer, wordsEZ[randomNumber]) == 0){
                    score++;
                    printf("[ PASS - Your score is %d/%d ]\n", score, maxRound);
                    break;
                }else{
                    hpRound--;
                    printf("[ WRONG - %d tries left. ]\n\n", hpRound);
                    if (hpRound == 0) {
                        printf("[ ANSWER: %s ]\n", wordsEZ[randomNumber]);
                        break;
                    }
                    else {continue;}
                }
            }
            printf("\n**************************************************************************************\n\n");
        }
        break;
    case (2):
        for (int i = 0; i < maxRound; i++)
        {
            int hpRound = hp;
            char answer[64]; //Storing user input
            int randomNumber = rand() % NUM(wordsNM); //Random a words from string array
            char randomWord[101]; 
            strcpy(randomWord, wordsNM[randomNumber]); //For saving random words.

            printf("[ WORD %d/%d ]\n\n", i+1, maxRound);

            gameplay(randomWord);

            while (1) {
                printf(">> ");
                scanf("%s", answer);

                if(strcmpi(answer, wordsNM[randomNumber]) == 0){
                    score++;
                    printf("[ PASS - Your score is %d/%d ]\n", score, maxRound);
                    break;
                }else{
                    hpRound--;
                    printf("[ WRONG - %d tries left. ]\n\n", hpRound);
                    if (hpRound == 0) {
                        printf("[ ANSWER: %s ]\n", wordsNM[randomNumber]);
                        break;
                    }
                    else {continue;}
                }
            }
            printf("\n**************************************************************************************\n\n");
        }
        break;
    case (3):
        for (int i = 0; i < maxRound; i++)
        {
            int hpRound = hp;
            char answer[64]; //Storing user input
            int randomNumber = rand() % NUM(wordsHD); //Random a words from string array
            char randomWord[101]; 
            strcpy(randomWord, wordsHD[randomNumber]); //For saving random words.

            printf("[ WORD %d/%d ]\n\n", i+1, maxRound);

            gameplay(randomWord);

            while (1) {
                printf(">> ");
                scanf("%s", answer);

                if(strcmpi(answer, wordsHD[randomNumber]) == 0){
                    score++;
                    printf("[ PASS - Your score is %d/%d ]\n", score, maxRound);
                    break;
                }else{
                    hpRound--;
                    printf("[ WRONG - %d tries left. ]\n\n", hpRound);
                    if (hpRound == 0) {
                        printf("[ ANSWER: %s ]\n", wordsHD[randomNumber]);
                        break;
                    }
                    else {continue;}
                }
            }
            printf("\n**************************************************************************************\n\n");
        }
        break;
    }

    printf("[ YOUR SCORE: %d/%d ]\n\n", score, maxRound);
    printf("**************************************************************************************\n\n");
    }

    return 0;
}
