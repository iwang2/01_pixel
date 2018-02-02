#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fd = open("image.ppm", O_CREAT | O_WRONLY | O_APPEND, 0644);
  char * head = "P3 100 100 255 ";
  write(fd, head, sizeof(head)-1);

  char buff[sizeof("100 100 200 ")];
  int i, j;
  for(i = 0; i < 100; i++){
    for(j = 0; j < 100; j++){
      sprintf(buff, "%d %d %d  ", i, j, i+j);
      write(fd, buff, sizeof(buff)-1);
    }
  }
  close(fd);
}
