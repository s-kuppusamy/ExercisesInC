#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char words[10];
  puts("Please enter a word: \n");
  char* word = fgets(words,sizeof(words),stdin);
  printf("%s",word);
  FILE *fp;
  char ch;
  ch = getopt(argc,argv,"a:");
  while(ch!=-1)
  {
    switch(ch)
    {
      case 'a':
        fprintf(stdout,"%s",word);
        fp = fopen(optarg, "a+");
        fwrite(word,1,sizeof(word),fp);
        fclose(fp);
        break;
      default:
      fprintf(stderr,"Error");
    }
  }
  fprintf(stdout,"%s",word);
  fp = fopen(argv[1], "w+");
  fwrite(word,1,sizeof(word),fp);
  fclose(fp);
  argc += optind;
  argv += optind;
}

//what worked: Using the textbook as a resource, so I could use familiar
//structures. Using online resources/examples to understand what the problem
//was actually asking me to do. Using google to get syntax examples to make
//sure I was using fopen/fwrite etc. correctly.

//what slowed me down: Running into errors that I didn't completely understand
//and messing up pointer/int stuff. Using resources/examples beyond understanding
//what the problem was asking for because then I got into new things we
//haven't studied and tried to spend a long time understanding how to
//correctly implement it and just got lost (tried to use open instead fopen).
//Not understanding the problem slowed me down.

//Differently Next Time: I would try to trust that I have the knowledge to
//write the code. I would reach out early on to better understand what the
//problem is asking us to do/what's a general way to go about it because the
//documentation wasn't very helpful in that avenue.

//The professional ones use structures that we haven't learned yet that I
//don't completely understand. They also have a lot more error checking which
//I should begin to incorporate into my code. 
