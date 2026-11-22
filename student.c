#include <stdio.h>

int main()
{
    int roll[5], marks[5];
    int choice, i, j, temp;
    int searchRoll, found;
    int dataEntered = 0;

    while(1)
    {
        printf("\n===== STUDENT RESULT SYSTEM =====\n");
        printf("1. Enter Student Data\n");
        printf("2. Display Rank Sheet\n");
        printf("3. Search by Roll Number\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter details of 5 students:\n");

                for(i = 0; i < 5; i++)
                {
                    printf("\nStudent %d Roll Number: ", i + 1);
                    scanf("%d", &roll[i]);

                    printf("Student %d Marks: ", i + 1);
                    scanf("%d", &marks[i]);

                    while(marks[i] < 0 || marks[i] > 100)
                    {
                        printf("Enter marks between 0 and 100: ");
                        scanf("%d", &marks[i]);
                    }
                }

                dataEntered = 1;
                printf("\nData entered successfully!\n");
                break;

            case 2:
                if(dataEntered == 0)
                {
                    printf("\nPlease enter student data first!\n");
                    break;
                }

                // Sorting students based on marks

                for(i = 0; i < 4; i++)
                {
                    for(j = 0; j < 4 - i; j++)
                    {
                        if(marks[j] < marks[j + 1])
                        {
                            temp = marks[j];
                            marks[j] = marks[j + 1];
                            marks[j + 1] = temp;

                            temp = roll[j];
                            roll[j] = roll[j + 1];
                            roll[j + 1] = temp;
                        }
                    }
                }

                printf("\n========== RANK SHEET ==========\n");
                printf("Rank\tRoll No\tMarks\n");
                printf("--------------------------------\n");

                for(i = 0; i < 5; i++)
                {
                    printf("%d\t%d\t%d\n", i + 1, roll[i], marks[i]);
                }

                break;

            case 3:
                if(dataEntered == 0)
                {
                    printf("\nPlease enter student data first!\n");
                    break;
                }

                printf("\nEnter Roll Number to search: ");
                scanf("%d", &searchRoll);

                found = 0;

                for(i = 0; i < 5; i++)
                {
                    if(roll[i] == searchRoll)
                    {
                        printf("\nStudent Found!\n");
                        printf("Roll Number: %d\n", roll[i]);
                        printf("Marks: %d\n", marks[i]);

                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("\nRoll Number %d Not Found!\n", searchRoll);
                }

                break;

            case 4:
                printf("\nExiting the program...\n");
                return 0;

            default:
                printf("\nInvalid choice! Please enter 1 to 4.\n");
        }
    }

    return 0;
}