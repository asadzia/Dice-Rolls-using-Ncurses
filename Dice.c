/*
* Created by: Asad Zia
* 
* Description:
* A program for counting the number of doubles while two dice are rolled. The program uses an ncurses implementation and stops
* after 20 doubles are seen for a particular number. 
*
*/

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
  
  int arr[6];
  int i,j;

  for (i = 0; i < 6; i++) {
    arr[i] = 0;
  }

  int num1, num2;
  srand(time(NULL));

  /* initializing ncurses */
  initscr();
  int length = 0;
  char buffer[200];
  
  /* loop until 20 astericks seen */
  while(1) {
    length = 0;
    num1 = rand()%6 + 1;
    num2 = rand()%6 + 1;
    
    /* incrementing the number of stars */
    if (num1 == num2) {
      arr[num2-1]++;
    }

    /* concatentating the strings to be printed using sprintf */
    length += sprintf(buffer + length,"%d %d\n\n", num1, num2);
    
    for (i = 0; i < 6; i++) {
      length += sprintf(buffer + length,"%d: ", i+1);
      
      for (j = 0; j < arr[i]; j++) {
	         length += sprintf(buffer + length, "*");
      }
      
      length += sprintf(buffer + length, "\n");
    }

    mvprintw(5,10,buffer);
    refresh();

    /* checking if 20 stars achieved */
     if (arr[num2-1] == 20) {
        printw("\nPress Any Key To Continue\n");
        getch();
        endwin();
        exit(1);

    }
    sleep(1);
  }
}
