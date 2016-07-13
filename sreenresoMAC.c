#include <stdio.h>
//#include <windows.h>
//#include <system.h>
#include <sys/utsname.h>
#include <stdlib.h>
//#include <libc.h>
//#include <IOKit/IOKitLib.h>


int OScall() {
  struct utsname name;
	if(uname(&name)) exit(-1);
}

void MacScreenCheckIt() {
  int w;
  int h;
  getScreenSize(&w,&h);
  printf("Your screen resolution is:\n");

  if(w == 1024 && h == 768){
    printf("1024 x 768\n");
  }
  else if(w == 800 && h == 600) {
    printf("800 x 600\n");
  }
  else if(w == 640 && h == 480) {
    printf("640 x 480\n");
  }
  else if(w == 832 && h == 624) {
    printf("832 x 624\n");
  }
  else if(w == 720 && h == 400) {
    printf("720 x 400\n");
  }
  else if(w == 640 && h == 400) {
    printf("640 x 400\n");
  }
  else if(w == 640 && h == 350) {
    printf("640 x 350\n");
  }
  else if(w == 1080 && h == 720){
    printf("1080 x 720\n");
  }
  else if(w == 3840 && h == 1200){
    printf("1920 x 1200\n");
  }
  else {
    printf("NULL, no resolution recieved, or unknown spectra\n");
    printf("Here is the size:\n%d x %d\n",w,h);
  }
}
int getScreenSize(int *w, int *h) {

  *w = CGDisplayPixelsWide();
  *h = CGDisplayPixelsHigh();
  bool check = CGDisplayIsActive();
    if(check == false) {
        printf("The screen resolution is restricted, check your permissions header.\n");
        return 0;
    }
}

int macGrab() {
 int w, h;
 MacScreenCheckIt(&w, &h);
 return 1;

}

int main () {
  struct utsname name;
  OScall();
  if(name.sysname == "Windows"){
  ]printf("oh\n");
}
  else if (name.sysname == "OSx") {
    printf("(%s@%s)\n", name.sysname, name.release);
    macGrab();
  }
  else{
    printf("Your Linux distro is:\n(%s, %s)\n", name.sysname, name.release);
  }
}
