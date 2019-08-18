#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

char alpha[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char guessed[50],input[50];

void displayOptions(void);
void hangman(int);
void display(int);
void initialize(int);
void upperString(int);
char upperChar(char);
int check(int);
int check_Existing_Alpha(char);

int main()                                                    //Main Function
{
  int i,count = 0,flag = 0;
  char inputletter;
  printf("Enter a word: ");
  scanf("%s",input);
  int n = strlen(input);
  upperString(n);
  initialize(n);
  while(strcmp(guessed,input)!=0)
  {
    system("cls");

    if(check(count) == 0)
    {
      return 0;
    }

    flag = 0;
    hangman(count);
    printf("\n\n");
    displayOptions();
    display(n);

    printf("\n\nEnter a letter: ");
    scanf(" %c",&inputletter);                                   //Taking Letter Input

    inputletter = upperChar(inputletter);
    if(check_Existing_Alpha(inputletter) == 0)
    {
      printf("Already Guesses Alphabet. Try Another!\n");
      printf("Press Enter to continue.\n");
      getch();
      continue;
    }

    for(i=0;i<n;i++)                                            //Checking if Input Letter exists in word given
    {
      if(input[i] == inputletter)
      {
        guessed[i] = inputletter;
        flag = 1;
      }
    }

    alpha[inputletter - 'A'] = ' ';

    if(flag == 0)
      count++;

    if(check(count) == 0)
    {
      return 0;
    }
  }                                                                 //While Ends
  return 0;
}                                                                   //Main Ends

char upperChar(char inputletter)                                 //Converting Input character to UPPERCASE
{
  if(inputletter>=97 && inputletter <= 122)
    inputletter-=32;
  return inputletter;
}

int check_Existing_Alpha(char inputletter)             //Check Existing Alphabets function
{
  if(alpha[inputletter - 'A'] == ' ')
    return 0;
  return 1;
}

void displayOptions(void)                         //Displaying alphabets available for guessing
{
  int i;
  printf("\t");
  for(i=0;i<26;i++)
    printf("%c  ",alpha[i]);
  printf("\n\n");
}



void display(int n)                                    //Display Function
{
  for(int i=0;i<n;i++)
  {
    if(guessed[i] == '0')
      printf(" _ ");
    else
      printf(" %c ",guessed[i]);
  }
}

void initialize(int n)                             //Iniitializing String from User
{
  for(int i=0;i<n;i++)
    guessed[i] = '0';
}

void upperString(int n)                          //Changing String from user to UPPERCASE
{
  for(int i=0;i<n;i++)
  {
    if(input[i]>=97 && input[i]<=122)
      input[i] -= 32;
  }
}

int checkAlpha(char inputletter)                    //Checking if alphabet is already used
{
  if(alpha[inputletter - 'A'] == ' ')
    return 0;
  return 1;
}

int check(int count)                            //Checking if game is over
{
  if(count == 8)
  {
    system("cls");
    hangman(count);
    printf("\n\nGame Over! You Lost :( \n");
    return 0;
  }
  else if(strcmp(guessed,input) == 0)
  {
    system("cls");
    hangman(count);
    printf("You Won! Congratulations!");
    return 0;
  }
  return 1;
}

void hangman(int count)                             //Printing the hangman graphic(sort of)
{
  if(count == 0)
  {
    for(int i=0;i<=10;i++)
      printf("\n");
  }


  if(count > 0)
  {
    printf("\t -------\n");

    if(count == 1)
    {
      for(int i=0;i<9;i++)
        printf("\t|\n");
    }

    if(count>=2 && count!=8)
    {
      printf("\t|\n");
      printf("\t|      ___\n\t|     |___|\n");
    }

    if(count==2)
    {
      for(int i=0;i<6;i++)
        printf("\t|\n");
    }

    else if(count>=3 && count!=8)
    {
      if(count == 3)
        printf("\t|       |\n");
      else if(count == 4)
        printf("\t|      /|\n");
      else if(count >= 5)
          printf("\t|      /|\\\n");
      printf("\t|       |\n");

      if(count == 6)
        printf("\t|      /\n");
      else if(count == 7)
        printf("\t|      / \\\n");
    }


    if(count == 8)
    {
      printf("\t|       |\n");
      printf("\t|      _|_\n\t|     |___|\n");
      printf("\t|      /|\\\n");
      printf("\t|       |\n");
      printf("\t|      / \\\n");
    }

    if(count >= 6)
    {
      for(int i=0;i<3;i++)
        printf("\t|\n");
    }

    else if(count >= 3)
    {
      for(int i=0;i<4;i++)
        printf("\t|\n");
    }
    printf("  --------------\n");
  }

  return;
}
