#include <stdio.h>

int super_complex_flag_print_function(void) {
  int enc[59] = {100, 110, 99,  101, 89,  113, 18,  80,  80,  91, 125, 106,
                 67,  84,  17,  125, 91,  77,  87,  125, 64,  17, 71,  76,
                 125, 85,  67,  75,  21,  75,  76,  69,  125, 78, 77,  76,
                 20,  29,  125, 108, 77,  125, 107, 125, 72,  87, 23,  86,
                 125, 69,  18,  86,  125, 74,  71,  80,  17,  95, 34};

  char flag[59];

  for (int i = 0; i < 59; i++) {
    flag[i] = enc[i] ^ 0x22;
  }

  printf("The time has come. Flag is \"%s\"\n", flag);
  return 0;
}
