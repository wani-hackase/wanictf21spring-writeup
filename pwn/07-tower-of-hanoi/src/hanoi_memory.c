#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define HANOI_SIZE 32

void init_hanoi(int *a1) {
  alarm(30);
  for (int i = 1; i <= HANOI_SIZE; i++) {
    a1[i - 1] = i;
  }
}
int is_solved(int (*rod)[HANOI_SIZE]) {
  if (rod[0][HANOI_SIZE - 1] == 0 && rod[1][HANOI_SIZE - 1] == 0 &&
      rod[2][HANOI_SIZE - 1] == HANOI_SIZE)
    return 1;
  else
    return 0;
}

void move_hanoi(char from, char to, int *pivot, int (*rod)[HANOI_SIZE]) {
  int src = (int)from - 65;
  int dst = (int)to - 65;
  if (abs(src) > 2 || abs(dst) > 2) {  // ???
    printf("That rod isn't where you can access!\n");
    return;
  }
  if (rod[src][pivot[src]] < rod[dst][pivot[dst]] ||
      rod[dst][pivot[dst]] == 0) {
    printf("Moved %d from %c to %c\n", rod[src][pivot[src]], from, to);
    if (rod[dst][pivot[dst]] != 0) pivot[dst]--;
    rod[dst][pivot[dst]] = rod[src][pivot[src]];
    rod[src][pivot[src]] = 0;

    if (pivot[src] < HANOI_SIZE - 1) pivot[src]++;
  } else
    printf("You can't move that way!\n");
}

int get_flag(char *flag) {
  FILE *fp;
  fp = fopen("./FLAG", "r");
  fscanf(fp, "%s", flag);
  fclose(fp);
}

int main() {
  int solved_flag = 0;
  int rod_pivot[3] = {0, HANOI_SIZE - 1, HANOI_SIZE - 1};
  char name[16];
  int rod[3][HANOI_SIZE] = {
      0,
  };
  char selection[3];
  char flag[28];
  setbuf(stdin, NULL);
  setbuf(stdout, NULL);
  setbuf(stderr, NULL);
  init_hanoi(rod[0]);

  printf(
      "\nIf you move all disks from A to C 'in time'\nI'll give you the "
      "flag\ninput ex) if from rod_a to rod_c > AC\n");
  write(1, "Name : ", 8);
  read(0, name, 16);
  while (solved_flag != 1) {
    solved_flag = is_solved(rod);
    printf("Top and bottom of the each rod\n  A     B     C\n%3d   %3d   %3d\n",
           rod[0][rod_pivot[0]], rod[1][rod_pivot[1]], rod[2][rod_pivot[2]]);
    printf(" ...............\n%3d   %3d   %3d\n", rod[0][HANOI_SIZE - 1],
           rod[1][HANOI_SIZE - 1], rod[2][HANOI_SIZE - 1]);
    write(1, "Move > ", 7);
    read(0, selection, 3);
    printf("Moving...\n");
    sleep(1);
    move_hanoi(selection[0], selection[1], rod_pivot, rod);
  }
  printf("How fast you are!!\n");
  get_flag(flag);
  printf("%s", flag);
  return 0;
}
