#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
  
  int fd = open("image.ppm", O_CREAT | O_WRONLY, 0644);
  
  int width = 256 * 2;
  int height = 256 * 2;
  
  char buff[sizeof("255 255 255  ")];
  sprintf(buff, "P3\n%d\n%d\n%d\n", width, height, 255);
  write(fd, buff, strlen(buff));

  int i, j, k;
  for(i = 0; i < width/2; i++){
    for(j = 0; j < height/2; j++){
      k = i + j;
      if (k > 255) k -= 256;
      sprintf(buff, "%d %d %d  ", i, j, k);
      write(fd, buff, strlen(buff));
    }
    for(j = height/2-1; j >= 0; j--){
      k = i + j;
      if (k > 255) k -= 256;
      sprintf(buff, "%d %d %d  ", i, j, k);
      write(fd, buff, strlen(buff));
    }
    write(fd, "\n", strlen("\n"));
  }
  
  for(i = width/2-1; i >= 0; i--){
    for(j = 0; j < height/2; j++){
      k = i + j;
      if (k > 255) k -= 256;
      sprintf(buff, "%d %d %d  ", i, j, k);
      write(fd, buff, strlen(buff));
    }
    for(j = height/2-1; j >= 0; j--){
      k = i + j;
      if (k > 255) k -= 256;
      sprintf(buff, "%d %d %d  ", i, j, k);
      write(fd, buff, strlen(buff));
    }
    write(fd, "\n", strlen("\n"));
  }
  
  close(fd);
  
  return 0;
}
