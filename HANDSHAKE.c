/*HANDSHAKE

Author: James A. Novorita

HANDSHAKE is an open source project that involves automatic authentication
between a server and a host for a VNC desktop stream.  Specifcally for a
PiWall stream.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include<unistd.h>
#define MAX_CMN_LEN 100

//This function runs through a simple malloc to assure a proper allocation for future variables.
pid_t proc_find(const char* vncserver, int x) {
    DIR* dir;
    struct dirent* ent;
    char buf[512];

    long  pid;
    char pname[100] = {0,};
    char state;
    x = 0;
    FILE *fp=NULL;

    if (!(dir = opendir("/home/zygal-mis/.vnc/"))) {
        perror("can't open /.vnc");
        x = 1;
        return -1;
    }

    while((ent = readdir(dir)) != NULL) {
        long lpid = atol(ent->d_name);
        if(lpid < 0)
            continue;
        snprintf(buf, sizeof(buf), "/home/zygal-mis/.vnc/%ld/stat", lpid);
        fp = fopen(buf, "r");

        if (fp) {
            if ( (fscanf(fp, "%ld (%[^)]) %c", &pid, pname, &state)) != 3 ){
                printf("fscanf failed \n");
                fclose(fp);
                closedir(dir);
                x = 1;
                return -1;
            }
          }
    }

    printf("n\n\nLocal date and time - ");
    strftime(buffer, 26, "%Y:%m:%d %H:%M:%Sn\n\n\n", tm_info);
    puts(buffer);

}

int Memcheck() {
  int *sack, *sack1;
  printf("Loading...\n");
  sack = malloc(1*sizeof(*sack));
  sack1 = malloc(1*sizeof(*sack1));
  if(sack == NULL) {
    printf("Error, out of memory. Error Code: 1\n");
    free(sack);
    return 1;
  }
  else {
    printf("\n");
    int *temp = realloc(sack, 1*sizeof(int));
      if(temp != NULL) {
        sack = temp;
      }
      else{
        free(sack);
        printf("Error, plumbing unsuccessful. Error Code 3.\n");
      }

  }
  if(sack1 == NULL) {
    printf("Error, out of memory.  Error Code 2\n");
    free(sack1);
    return 1;
  }
  else{
    printf("Load successful.\n");
    int *temp1 = realloc(sack1, 1*sizeof(int));
      if(temp1 != NULL) {
        sack1 = temp1;
      }
      else{
        free(sack1);
        printf("Error, plumbing not successful.  Error Code 4.\n");
      }
  }
}

int SSH_SETUP() {

  unsigned short int IP11, IP12, IP13, IP14;
  char configure[3];
  char sys_buffer[40];
  char buffer69[20];
  char userz[25];

  printf("Do you want to configure your SSH settings?\n");
  scanf("%s",&configure);
  if(strlen(configure) == 3) {
    printf("First, you will need to create a file to store it in.  Note your directory.  Then a passphrase to authenticate.  This can be as long as needed, punctuation and numbers included.\n");
    sprintf(sys_buffer, "ssh-keygen -t dsa");
    system((char*)sys_buffer);
    printf("Username on device to connect to?\n");
    scanf("%s", &userz);
    printf("What is the IP for the device you would like to send the key to?\n");
    scanf("%d.%d.%d.%d", &IP11, &IP12, &IP13, &IP14);
    sprintf(buffer69, "ssh-copy-id %s@%d.%d.%d.%d", userz, IP11, IP12, IP13, IP14);
    system((char*)buffer69);

  }
  else {
    return -1;
  }
}

int SSH_Tunnel() {
  unsigned short int IP1, IP2, IP3, IP4;
  char buffer[20];
  char buffer_2[20];
  char user_SHH[25];
  int port = 5;
  int SSH_Rogue = 0;
  /*char user[3] = "pi";
  char host[14] = "192.168.1.139"; */
  printf("Starting VNC SERVER on port 590%d\n", port);
  sprintf(buffer_2, "vncserver");
  system((char*)buffer_2);
  printf("What is the username in the SSH Portal?\n");
  scanf("%s",user_SHH);
  printf("What is the IP for the device?\n");
  scanf("%d.%d.%d.%d", &IP1, &IP2, &IP3, &IP4);
  sprintf(buffer, "ssh -X %s@%d.%d.%d.%d", user_SHH, IP1, IP2, IP3, IP4);
  system((char*)buffer);
  int y = 1;
  SSH_Rogue = 1;
  return 1;
}

/*int SSH_PIPE_PIWALL() {
  unsigned short int IP5, IP6, IP7, IP8;
  char buffer_4[20];
  char buffer_5[20];
  char user_SHH1[25];
  int port = 1;
  int SSH_Rogue = 0;
  /*char user[3] = "pi";
  char host[14] = "192.168.1.139";
  printf("Starting VNC SERVER on port 590%d\n", port);
  sprintf(buffer_4, "vncserver");
  system((char*)buffer_4);
  printf("What is the username in the SSH Portal?\n");
  scanf("%s",user_SHH1);
  printf("What is the IP for the device?\n");
  scanf("%d.%d.%d.%d", &IP5, &IP6, &IP7, &IP8);
  sprintf(buffer_5, "ssh -X %s@%d.%d.%d.%d", user_SHH1, IP5, IP6, IP7, IP8);
  system((char*)buffer_5);
  fork(printf("What dimensions of the video wall exist?\n")
  int y = 1;
  SSH_Rogue = 1;
  return 1;
}

void PiWALL() {
  char yawinaw[3];
  printf("Is this tunnel for the Piwall software?\n");
  scanf("%s\n", &yawinaw);
    if(strlen(yawinaw) == 3) {
      SSH_PIPE_PIWALL();
    }
    else {
      main();
    }
}
*/
//Main Call
int main() {
  time_tee();
  int x;
  int SSH_Rogue;
  const char* vncserver;
  char buffer_3[20];
  char yawornaw[3];
  printf("Welcome to HANDSHAKE\nWould you like to connect?\n");
  scanf("%s", &yawornaw);

  if(strlen(yawornaw) == 3) {
    printf("Starting HANDSHAKE\n");
    printf("Checking memory...\n");
    Memcheck();
    SSH_SETUP();
    SSH_Tunnel();
    if(SSH_Rogue == 0) {
      printf("There was a fatal error, exit status %d\n", SSH_Rogue);
      return 0;
    }
    else {
      printf("Thank you for using HANDSHAKE!\n");
      proc_find(vncserver, x);
      //printf("x = %d", x);
      if(x != 1) {
        printf("Killing all VNC sessions\n");
        for(int i = 0; i<=5; i++) {
          sprintf(buffer_3, "vncserver -kill :%d",i);
          system((char*)buffer_3);
        }
      }
      else {
      return 0;
      }
    }
  }
  else {
    return 0;
  }
}
