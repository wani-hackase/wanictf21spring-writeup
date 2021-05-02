#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

char* name_gadgets[16];
u_int64_t addr_gadgets[16];
char binsh[] = "/bin/sh";

void rop_pop_rdi();
void rop_syscall();

void init() {
  alarm(300);
  setbuf(stdin, NULL);
  setbuf(stdout, NULL);
  setbuf(stderr, NULL);
}

void create_gadgets_table() {
  name_gadgets[0] = "execute";
  name_gadgets[1] = "push value";
  name_gadgets[2] = "pop rdi; ret";
  name_gadgets[3] = "system";

  addr_gadgets[0] = 0;
  addr_gadgets[1] = 0;
  addr_gadgets[2] = ((u_int64_t)rop_pop_rdi) + 8;
  addr_gadgets[3] = ((u_int64_t)system);
}

void rop_pop_rdi() {
  __asm__(
      "pop %rdi\n\t"
      "ret\n\t");
}

char* get_rop_name(u_int64_t addr) {
  int i;
  for (i = 0; i < 7; i++) {
    if (addr_gadgets[i] == 0) {
      continue;
    }

    if (addr_gadgets[i] == addr) {
      return name_gadgets[i];
    }
  }

  return NULL;
}

void print_menu() {
  printf("\n\"%s\" address is %p\n", binsh, binsh);
  printf(
      "\n[menu]\n"
      "1. append hex value\n"
      "2. append \"pop rdi; ret\" addr\n"
      "3. append \"system\" addr\n"
      "8. show menu (this one)\n"
      "9. show rop_arena\n"
      "0. execute rop\n");
}

u_int64_t get_uint64() {
  char buf[64];
  u_int64_t ret;
  ret = read(0, buf, 63);
  buf[ret] = 0;
  ret = strtoul(buf, NULL, 16);
  return ret;
}

u_int64_t menu() {
  u_int64_t ret;

  printf("> ");
  ret = get_uint64();
  return ret;
}

void show_arena(u_int64_t* rop_arena, int index) {
  int i;
  puts("     rop_arena");
  puts("+--------------------+");
  for (i = 0; i < index; i++) {
    char* name = get_rop_name(rop_arena[i]);
    if (name != NULL) {
      printf("| %-18s |", name);
    } else {
      printf("| 0x%016lx |", rop_arena[i]);
    }

    if (i == 0) {
      printf("<- rop start");
    }

    printf("\n");
    puts("+--------------------+");
  }
}

void rop_machine() {
  u_int64_t rop_arena[128];
  u_int64_t* top = rop_arena;
  int index = 0;
  u_int64_t ret;

  print_menu();

  while (1) {
    int cmd = menu();
    switch (cmd) {
      case 1:
        printf("hex value?: ");
        ret = get_uint64();
        rop_arena[index] = ret;
        index++;
        printf("0x%016lx is appended\n", ret);
        break;
      case 2:
      case 3:
        rop_arena[index] = addr_gadgets[cmd];
        printf("\"%s\" is appended\n", name_gadgets[cmd]);
        index++;
        break;
      case 8:
        print_menu();
        break;
      case 9:
        show_arena(rop_arena, index);
        break;
      case 0:
        show_arena(rop_arena, index);
        {
          register u_int64_t rsp asm("rsp");
          rsp = (u_int64_t)rop_arena;
          __asm__("ret");
          exit(0);
        }
      default:
        puts("bye beginner!!\n");
        exit(1);
        break;
    }
  }
}

int main() {
  init();
  create_gadgets_table();
  rop_machine();
}
