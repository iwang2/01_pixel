#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
  int size = 10;
  char buff[sizeof("100 100 200 ")];
  char s[sizeof("100 100 200 ") * size * size];
  sprintf(s, "P3 %d %d %d ", size, size, 255);

  int i, j;
  for(i = 0; i < 10; i++){
    for(j = 0; j < 10; j++){
      sprintf(buff, "%d %d %d  ", i, j, i+j);
      strcat(s, buff);
      memset(buff, 0, sizeof(buff));
    }
  }
  /*
  size = strlen(s) / sizeof(char);
  s[size-1] = 0;
  */
  
  int fd = open("image.ppm", O_CREAT | O_WRONLY, 0644);
  write(fd, s, strlen(s));
  
  close(fd);
}
