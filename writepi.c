#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define MAX_CMN_LEN 100

/*int Create() {

  DIR* dir = opendir("PiWallHAND");
  if (dir)
  {
      closedir(dir);
  }
  else if (ENOENT == errno)
  {
    struct stat st = {0};
    if (stat("/home/PiWallHAND", &st) == -1) {
      mkdir("/home/PiWallHAND", 0700);
    }
  }
  else
  {
      printf("ERROR, could not open file directory.\n");
  }

}
*/
int WALLsetup (int w, x, y, s1, s2, h, l, checkSUMLengthx, checkSUMLengthy;) {

int w, x, y, s1, s2, h, l, checkSUMLengthx, checkSUMLengthy;

FILE *OutFile = fopen("home/PiWallHAND/.piwall","w");

printf("What are the dimensions of the video wall? Seperated by a space (all will be the same format)\n");
scanf("%d %d", &x, &y);
printf("What is the point you would like to start your video wall?\n(x , y)\n");
scanf("%d %d", &s1, &s2);
printf("What is the height and length of each screen?\n");
scanf("%d %d", &h, &l);
printf("Are the credentials correct?\n");
printf("Dimensions of the video wall: %d x %d\nStart point (%d , %d)\nHeight and length of each screen: %d x %d\n", x, y, s1, s2, h, l);

checkSUMLengthx = (y*l);
checkSUMLengthy = (x*h);
printf("The wall will be %d wide and %d high.\n", checkSUMLengthx, checkSUMLengthy);
}


int ScreenSLUG(int w, x, y, s1, s2, h, l, checkSUMLengthx, checkSUMLengthy;) {

int w, x, y, s1, s2, h, l, checkSUMLengthx, checkSUMLengthy;



}


int SSH_Tunnel() {
  unsigned short int IP1, IP2, IP3, IP4;
  char buffer[20];
  char buffer_2[20];
  char user_SHH[25];
  int port = 5;
  int SSH_Rogue = 0;

  printf("What is the username in the SSH Portal?\n");
  scanf("%s",user_SHH);
  printf("What is the IP for the device?\n");
  scanf("%d.%d.%d.%d", &IP1, &IP2, &IP3, &IP4);
  sprintf(buffer, "ssh -X %s@%d.%d.%d.%d", user_SHH, IP1, IP2, IP3, IP4);
  system((char*)buffer);
  sprintf(buffer_2, "exit");
  system((char*)buffer_2);
  int y = 1;
  SSH_Rogue = 1;
  return 1;
}
int main () {
  WALLsetup();
  return 0;
}
