#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
  int width = 256;
  int height = 256;
  char buff[sizeof("100 100 200 ")];
  char s[sizeof("100 100 200 ") * width * height];
  sprintf(s, "P3 %d %d %d  ", width, height, 255);

  int i, j;
  for(i = 0; i < width; i++){
    for(j = 0; j < height; j++){
      sprintf(buff, "%d %d %d  ", i, j, i+j);
      strcat(s, buff);
      memset(buff, 0, sizeof(buff));
    }
  }
  
  int fd = open("image.ppm", O_CREAT | O_WRONLY, 0644);
  write(fd, s, strlen(s));
  close(fd);
}
