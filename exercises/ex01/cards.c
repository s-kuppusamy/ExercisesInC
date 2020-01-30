#include <stdio.h>
#include <stdlib.h>
/*
 * Program to evaluate face values of the card and accordingly icrement or
 decrement the card count.
 * Shirin Kuppusamy
 * Released under the Vegas Public License.
 * (c)2014 The College Blackjack Team.
*/

/* Keeps track of the count based on the value of the card.

   Prints out the current card count and returns it.

   value: the value of the card
   count: the resulting count
*/
int count_tracker(int value, int count)
{
  if ((value>2)&&(value<7)){
    count++;
  }
  else if (value==10){
    count--;
  }
  printf("Current count: %i\n", count);
  return count;
}

/* Prompts the user for input and puts the reply in the given buffer.

   User input is truncated to the first two characters.

   prompt: string prompt to display
   card_name: buffer where result is stored
*/
void get_card_name(char *prompt, char *card_name)
{
  int count = 0;
  int val = 0; // I moved this outside the do loop to fix the warning
  do{
      puts(prompt);
      scanf("%2s", card_name);
      switch(card_name[0]){
        case 'K':
        case 'Q':
        case 'J':
          val = 10;
          break;
        case 'A':
          val = 11;
          break;
        case 'X':
          continue;
        default:
          val = atoi(card_name);
          if ((val<1)||(val>10)){
            puts("I don't understand that value!");
            continue;
          }
}
count = count_tracker(val,count);
}
while(card_name[0]!='X');
}

/* Calls get_card_name and returns 0.

   card_name: parameter (an array) passed into get_card_name
*/
int main()
{
  char card_name[3];
  get_card_name("Enter the card name: ", card_name);
  return 0;
}

/*
-ansi enables the ANSI standard language and turns off features incompatible
with this. -pedantic is often used with -ansi and tells the compile to adhere
directly to the ANSI standard and reject anything that doesn't conform. -Wall
enables all compiler warning messages.

When I ran the compiler with these flags, I got a warning that said that there
is a mixed declaration with code for the variable val.
*/
