#include <stdio.h>
#include <string.h>

void show_description(void) {
  puts("");
  puts("   ▄▀▀▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄▀▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▀▀█▀▀▄");
  puts("  █ █   ▐ ▐  ▄▀   ▐ █ █    ▌ █   █   █ ▐  ▄▀   ▐ █    █  ▐");
  puts("     ▀▄     █▄▄▄▄▄  ▐ █      ▐  █▀▀█▀    █▄▄▄▄▄  ▐   █");
  puts("  ▀▄   █    █    ▌    █       ▄▀    █    █    ▌     █");
  puts("   █▀▀▀    ▄▀▄▄▄▄    ▄▀▄▄▄▄▀ █     █    ▄▀▄▄▄▄    ▄▀");
  puts("   ▐       █    ▐   █     ▐  ▐     ▐    █    ▐   █");
  puts("           ▐        ▐                   ▐        ▐");
  puts("");
}

int main(void) {
  char input[50];
  char flag[42];
  int key[41] = {49, 45, 47, 46, 36, 8,  29,  62, 69, 17, 31, 58, 60, 91,
                 1,  8,  58, 0,  0,  45, 8,   0,  95, 30, 62, 13, 29, 59,
                 54, 11, 39, 17, 11, 16, 104, 18, 48, 68, 5,  10, 92};

  show_description();
  printf("Input secret key : ");
  scanf("%s", input);

  if (strlen(input) != 41) {
    puts("Incorrect");
    return 1;
  }

  if (strncmp(input, "wani_is_the_coolest_animals_in_the_world!", 41) == 0) {
    for (size_t i = 0; i < 41; i++) {
      flag[i] = input[i] ^ key[i];
    }
    flag[41] = 0;
    printf("Correct! Flag is %s\n", flag);
  } else {
    puts("Incorrect");
    return 1;
  }
  return 0;
}
