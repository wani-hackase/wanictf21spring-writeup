#include <stdio.h>
#include <unistd.h>

void call_syscall() { __asm__("syscall; ret;"); }

void set_rax() { __asm__("mov $0xf, %rax; ret;"); }

int main() {
  char buff[50];
  setbuf(stdin, NULL);
  setbuf(stdout, NULL);
  setbuf(stderr, NULL);
  printf("buff : %p\nCan you get the shell?\n", buff);
  read(0, buff, 0x200);
  return 0;
}
