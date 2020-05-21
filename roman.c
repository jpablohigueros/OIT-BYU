//3:53h used to complete

//Include libraries used in project
#include <cs50.h> //Currently using this library in a course I am enrolled in.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Calling function defined latter
int values(char r);


int main(void)
{
    //ask user for number
    string number = get_string("Enter number: ");
    int n = strlen(number);
    
    int sum = 0;
    
    //Numbers to romans
    for (int i = 0; i < n; i++)
    {
        if (number[i] >= 48 && number[i] < 58)
            {
                int num = atoi(number);
                int nM = num / 1000;
                int nD = (num % 1000) / 500;
                int nC = ((num % 1000) % 500) / 100;
                int nL = (((num % 1000) % 500) % 100) / 50;
                int nX = ((((num % 1000) % 500) % 100) % 50) / 10;
                int nV = (((((num % 1000) % 500) % 100) % 50) % 10) / 5;
                int nI = (((((num % 1000) % 500) % 100) % 50) % 10) % 5;
                
                printf("Roman number: ");
                //Print romans
                for (int j = 0; j < nM; j++)
                {
                    printf("M");
                }
                for (int j = 0; j < nD; j++)
                {
                    printf("D");
                }
                for (int j = 0; j < nC; j++)
                {
                    printf("C");
                }
                for (int j = 0; j < nL; j++)
                {
                    printf("L");
                }
                for (int j = 0; j < nX; j++)
                {
                    printf("X");
                }
                for (int j = 0; j < nV; j++)
                {
                    printf("V");
                }
                for (int j = 0; j < nI; j++)
                {
                    printf("I");
                }
                printf("\n");
                return 0;
            }
            // Romans to number
            if (number[i] >= 65 && number[i] <= 90)
            {
                //Rules of which numbers can come before which ones
                if (number[i + 1] == 68 && (number[i] != 77 && number[i] != 68 && number[i] != 67))
                {
                    printf("Invalid characters\n");
                    return 1;
                }
                if (number[i + 1] == 67 && (number[i] != 77 && number[i] != 67 && number[i] != 68 && number[i] != 88))
                {
                    printf("Invalid characters\n");
                    return 1;
                }
                if (number[i + 1] == 76 && (number[i] != 77 && number[i] != 67 && number[i] != 68 && number[i] != 88 && number[i] != 76))
                {
                    printf("Invalid characters\n");
                    return 1;
                }
                if (number[i + 1] == 88 && (number[i] != 77 && number[i] != 67 && number[i] != 68 && number[i] != 88 && number[i] != 76 && number[i] != 73))
                {
                    printf("Invalid characters\n");
                    return 1;
                }
                if (number[i + 1] == 86 && (number[i] != 77 && number[i] != 67 && number[i] != 68 && number[i] != 88 && number[i] != 76 && number[i] != 73 && number[i] != 86))
                {
                    printf("Invalid characters\n");
                    return 1;
                }
                
                //Converting to Decimal numbers
                if(values(number[i]) >= values(number[i + 1]))
                {
                    sum = sum + values(number[i]);
                }
                //Condition for when a smaller value comes before a larger one for substractive notation
                else
                {
                    sum = sum + (values(number[i + 1]) - values(number[i]));
                    i++;
                }
                //print converted number
                if (i == (n - 1))
                {
                    printf("Number in decimal: %i\n", sum);
                }
                    
            }

            
            //Invalid characters
            else
            {
                printf("Invalid characters\n");
                return 1;
            }
    }   
}


//Function to compare each letter and return the value of each different roman character in decimal
int values(char r)
{
    int rom = 0;
    
    switch(r)
    {
        case 'M': 
            rom = 1000;
            break;
        case 'D':
            rom = 500;
            break;
        case 'C': 
            rom = 100;
            break;
        case 'L':
            rom = 50;
            break;
        case 'X': 
            rom = 10;
            break;
        case 'V':
            rom = 5;
            break;
        case 'I': 
            rom = 1;
            break;
    }
    return rom;
}
