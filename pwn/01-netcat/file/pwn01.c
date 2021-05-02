#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void init();

void win() {
  puts("congratulation!");
  puts("please enter \"ls\" command");
  system("/bin/sh");
  exit(0);
}

int main() {
  init();
  win();
}

void init() {
  alarm(30);
  setbuf(stdin, NULL);
  setbuf(stdout, NULL);
  setbuf(stderr, NULL);
}
