#include <stdio.h>
//#include <windows.h>
//#include <system.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <X11/Xlib.h>


int OScall() {
  struct utsname name;
	if(uname(&name)) exit(-1);
}

void LinuxScreenCheckIt() {
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

/*int getRootWindowSize(int *w, int *h) {
    Display* pdsp = NULL;
    Window wid = 0;
    XWindowAttributes xwAttr;

    pdsp = XOpenDisplay( NULL );
    if ( !pdsp ) {
      fprintf(stderr, "Failed to open default display.\n");
      return -1;
      }

      wid = DefaultRootWindow( pdsp );
    if ( 0 > wid ) {
      fprintf(stderr, "Failed to obtain the root windows Id "
      "of the default screen of given display.\n");
      return -2;
    }

    Status ret = XGetWindowAttributes( pdsp, wid, &xwAttr );
    *w = xwAttr.width;
    *h = xwAttr.height;

    XCloseDisplay( pdsp );
    return 0;
  }
*/

int getScreenSize(int *w, int*h) {
  Display* pdsp = NULL;
  Screen* pscr = NULL;

  pdsp = XOpenDisplay( NULL );
  if ( !pdsp ) {
    fprintf(stderr, "Failed to open default display.\n");
    return -1;
  }
  pscr = DefaultScreenOfDisplay( pdsp );
  if ( !pscr ) {
    fprintf(stderr, "Failed to obtain the default screen of given display.\n");
    return -2;
  }

 *w = pscr->width;
 *h = pscr->height;

  XCloseDisplay( pdsp );
  return 0;
}

int LinuxGrab()
{
 int w, h;

 LinuxScreenCheckIt(&w, &h);

 return 1;

}

int main () {
  struct utsname name;
  OScall();
  if(name.sysname == "Windows"){
  /*unsigned int dwpiWallx = GetSystemMetrics(SM_CXSCREEN);
  unsigned int dwpiWally = GetSystemMetrics(SM_CYSCREEN);
  printf("The screen resolution for your OS (%s@%s) is:\n  %u x %u", name.sysname, name.release, dwpiWallx, dwpiWally);
  */ printf("oh\n");
}
  else if (name.sysname == "OSx") {
    printf("(%s@%s)\n", name.sysname, name.release);
    printf("foo\n");
  }
  else{
    printf("Your Linux distro is:\n(%s, %s)\n", name.sysname, name.release);
    LinuxGrab();
  }
}
