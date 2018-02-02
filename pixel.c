#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
  int width = 256;
  int height = 256;
  char buff[sizeof("100 100 200 ")];
  char s[sizeof("100 100 200 ") * width * height * 4];
  sprintf(s, "P3 %d %d %d  ", width * 2, height * 2, 255);

  int i, j, k;
  for(i = 0; i < width; i++){
    for(k = 0; k < 2; k++){
      for(j = 0; j < height; j++){
	sprintf(buff, "%d %d %d  ", i, j, i+j);
	strcat(s, buff);
	strcat(s, buff);
	memset(buff, 0, sizeof(buff));
      }
    }
  }
  
  int fd = open("image.ppm", O_CREAT | O_WRONLY, 0644);
  write(fd, s, strlen(s));
  close(fd);
}
