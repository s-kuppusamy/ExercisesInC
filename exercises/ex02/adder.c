#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char numbers[10];

void print_sum()
{
  int sum = 0;
  for (int i=0;i<sizeof(numbers);i++)
  {
    sum += numbers[i];
  }
  printf("The sum is: %d\n",sum);
}

void create_array(int i, int val)
{
  if (i < 10)
  {
    numbers[i]=val;
  }
  else
  {
    printf("Error! Too many integers entered. Exceeds array bounds.\n");
    exit(0);
  }
}

void get_integer(char *prompt, char *integ)
{
int val = 0;
bool eof = false;
int i = 0;
int size = 10;
do
{
printf("%s\n",prompt);
eof = fgets(integ,size,stdin) == NULL;
// I got the following three lines from stack overflow, but I went back to
// read through the documentation to understand what happens. strchr finds
// the first instance of the character of interest in the string. Thus, if no
// newline character is found, it is NULL. so if that holds true, then there
// are extra characters past the buffer limit. So then, while the character
// inputted from the keyboard does not equal newline, it prints an error
// statement and continues back to the start of the do loop.
if (strchr(integ, '\n') == NULL) {
   int c;
    while((c = getc(stdin)) != '\n');
      printf("Error! Input too long. Try again.\n");
      continue;
}
val = atoi(integ);
if (val==0 && *integ != '0' && !eof)
{
  printf("Error! This input cannot be converted to an integer. Try again.\n");
  continue;
}
if(!eof)
{
create_array(i,val);
i+=1;
}
}
while(!eof);
print_sum();
}

int main()
{
  char integ[4];
  get_integer("Enter an integer: ", integ);
  return 0;
}
