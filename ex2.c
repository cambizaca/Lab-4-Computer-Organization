/* Example: bubble sort strings in array */
  
#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */


int my_compare_strings(char string1[], char string2[]) {
//printf("%s\n", string1);
//printf("%s\n", string2);

  int incraVal = 0;
  int okay = 0;

  if(strlen(string1) > strlen(string2)) {
    incraVal = strlen(string2);
  } else {
    incraVal = strlen(string1);
  }
  printf("%d\n", incraVal);

  for(int i = 0; i < incraVal; i++) {
    if (string1[i] > string2[i]) {
        return 1;
//      printf("1\n");
    } else if (string1[i] < string2[i]) {
        return -1;
//      printf("-1\n");
    }
  }
  return 0;
}


void my_swap_strings(char string1[], char string2[]) {
  char temp;

  for(int i = 0; i < LEN; i++) {
    while(string1[i] != '\0' || string2[i] != '\0') {
      temp = string1[i];
      string1[i] = string2[i];
      string2[i] = temp;
//      printf("%s\n",string1);
//      printf("%s\n",string2); 
      i++;
    }
    if(string1[i] = '\0') {
      while(string2[i] != '\0') {
        temp = string2[i];
        string1[i] = temp;
      }
    } else if (string2[i] = '\0') {
        while(string1[i] != '\0') {
          temp = string1[i];
          string2[i] = temp;
        }
    }
}
}

int main()
{
  char Strings[NUM][LEN];

  printf("Please enter %d strings, one per line:\n", NUM);


  for(int i = 0; i < NUM; i++) {
    fgets(Strings[i], LEN, stdin);
  }

  puts("\nHere are the strings in the order you entered:");

  /* Write a for loop here to print all the strings. */
  for(int i = 0; i < NUM; i++) {
    printf("%s",Strings[i]);
  }



  for(int outer = 0; outer < NUM; outer++) {
    int didswap = 0;
    for(int inner = outer; inner < NUM; inner++) {
      int compVal = strcmp(Strings[outer],Strings[inner]);
      //printf("%d\n", compVal);
      if(compVal >= 1) {
       // my_swap_strings(Strings[outer],Strings[inner]);
	char tempstring[LEN];
	strcpy(tempstring, Strings[outer]);
	strcpy(Strings[outer],Strings[inner]);
	strcpy(Strings[inner],tempstring);

      }
    }
  }

  puts("\nIn alphabetical order, the strings are:");     

  for(int i = 0; i < NUM; i++) {
    printf("%s", Strings[i]);
  }
}

