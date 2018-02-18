#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <stdlib.h>

/*
 * 'open_port()' - Open serial port 1.
 *
 * Returns the file descriptor on success or -1 on error.
 * 
 * See e.g. https://support.dce.felk.cvut.cz/pos/cv5/doc/serial.html
 */
int open_port(const char* device, speed_t baud_rate) {
  int fd;
  struct termios toptions;
  
  fd = open(device, O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1) {
    perror("Unable to open port");
  } else {
    fcntl(fd, F_SETFL, 0);
  }
  cfsetispeed(&toptions, baud_rate);
  
  return (fd);
}

int close_port(int fd) {
  return close(fd);
}

int read_line(int fd, char* buf, int buf_size) {
  char b[1];
  int i = 0;
  int n = 0;
  
  while ( ((n = read(fd, b, 1)) != -1) &&  (b[0] != '\n') && (i < buf_size - 1)) {
    if( n==0 ) {
      usleep( 10 * 1000 ); // wait 10 msec try again
      continue;
    }
    buf[i] = b[0];
    i++;
  }; 

  if (b[0] == '\n') {
    buf[i] = read(fd, b, 1); //read one more char, it send two \n
  }
  buf[i++] = 0;  // null terminate the string
  
  return 0;
}


int main(int argc, char **argv) {

  if (argc < 2) {
    printf("At leat one argument (number of line to be read) required, exiting...\n");
    exit(1);
  }
  
  int fd = open_port("/dev/ttyACM0", B9600);
  if (fd == -1) {
    exit(1);
  }

  int buf_size = 1024;
  char buf[buf_size];
  for (int i = 0; i < atoi(argv[1]); i++) {
    read_line(fd, buf, buf_size);
    printf("[%i]: %s\n", i, buf); //TODO not sure why \n in formatting is needed to work properly
  }
  return close_port(fd);
  
}
