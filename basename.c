#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
  
  for (int i=1; i<argc; i++) {

    char* p = strrchr(argv[i], '/');
    puts((p==0) ? "" : p+1);
  }

  return  0;
}
