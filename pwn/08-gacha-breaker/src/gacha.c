#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void init() {
  alarm(600);
  setbuf(stdin, NULL);
  setbuf(stdout, NULL);
  setbuf(stderr, NULL);
}

int get_int(int bottom, long int top) {
  long int value;
  char buf[12];
  read(0, buf, 11);
  value = atol(buf);
  if (value < bottom || value > top) {
    printf("Invalid Value\n>");
    value = get_int(bottom, top);
  }
  return value;
}

int* gacha(int** list, int n, int k, int* count) {
  int* gacha_result;
  int prob_man;  // Probability Manipulaton : increase possibility of overlapped
                 // result
  srand(time(0));

  printf("Doki Doki .....\n");
  sleep(1);
  gacha_result = malloc(sizeof(int) * k);
  printf("Your gacha No.%d\nresults :", n);
  prob_man = (1 < k - 4 ? k - 4 : k);
  for (int i = 0; i < prob_man; i++) {
    gacha_result[i] = rand() % 0x10000;
    printf(" [%#x]", gacha_result[i]);
  }
  for (int i = prob_man; i < k; i++) {
    if (n > 1 && count[n - 2] > 3)
      gacha_result[i] = list[n - 2][k - i - 1];
    else
      gacha_result[i] = rand() % 0x10000;
    printf(" [%#x]", gacha_result[i]);
  }
  printf("\n\n");
  return gacha_result;
}

void view_history(int** list, int n, int* count, int* is_free) {
  printf("----History----\n");
  for (int i = 0; i < n; i++) {
    if (is_free[i] == 0) {
      printf("[No. %d] Cleared\n", i);
      continue;
    }
    printf("[No.%d] Gacha\n", i);
    for (int k = 0; k < count[i]; k++) printf("[%#x] ", list[i][k]);
    printf("\n");
  }
  printf("\n");
}

void ceiling(int** list, int n, int* count) {
  int a, b, c;
  printf("Which No. gacha do you want to change? >");
  a = get_int(0, n);
  printf("What result do you want to change?[0-%d] >", count[a] - 1);
  b = get_int(0, count[a] - 1);
  printf("To which number do you want to change? (Dec) >");
  c = get_int(0, 0xFFFFFFFF);
  list[a][b] = c;
  printf("You successfully get [%#x]", c);
}

void menu() {
  printf(
      "1. do_gacha!\n2. view_history\n3. clear_history\n4. ceiling\n9. "
      "exit\n>");
}

void free_list(int** list, int* is_free) {
  for (int i = 6; i >= 0; i--) {
    if (is_free[i] != 0) {
      free(list[i]);
      is_free[i] = 0;
    }
  }
  printf("--History Cleared--\n");
}

int main() {
  int coin = 1500;
  int select;
  int* gacha_list[7] = {
      0,
  };
  int gacha_count[7] = {
      0,
  };
  int is_free[7] = {
      0,
  };
  int count;
  int i = 0;
  int stack = 0;

  init();
  while (select != 9) {
    printf("Coins : %d\nGacha stack : %d\n", coin, stack);
    menu();
    select = get_int(1, 9);
    switch (select) {
      case 1:
        printf("How many times? :");
        count = get_int(1, coin);
        gacha_count[i] = count;
        coin -= count;
        gacha_list[i] = gacha(gacha_list, i, count, gacha_count);
        stack += count;
        is_free[i] = 1;
        i++;
        break;
      case 2:
        view_history(gacha_list, i, gacha_count, is_free);
        break;
      case 3:
        free_list(gacha_list, is_free);
        break;
      case 4:
        printf(
            "You can change 1 result to what you want when you gacha "
            "200times\n");
        if (stack < 200) {
          printf("Not enough gacha counts for ceiling\n");
          break;
        }
        ceiling(gacha_list, i, gacha_count);
        stack -= 200;
    }
    if (i == 7) {
      printf("--History is full, clearing history--\n");
      free_list(gacha_list, is_free);
      memset(gacha_count, 0, 7);
      i = 0;
    }
  }
  printf("Bye~\n");
  free_list(gacha_list, is_free);
  return (0);
}
