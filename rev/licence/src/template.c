#include <stdio.h>
#include <string.h>

int check(char *flag) { ? ? ? ? }

int main(int argc, char *argv[]) {
  if (argc != 2) {
    puts("Failed to execute. Usage: ./licence <key file name>");
    return 1;
  }

  FILE *fp;
  if ((fp = fopen(argv[1], "r")) == NULL) {
    puts("Failed to open file");
    return 1;
  }

  /* ライセンスファイル1行目 */

  char begin[29];
  if (fgets(begin, 29, fp) == NULL) {
    puts("Failed to read file");
    return 1;
  }

  if (strcmp(begin, "-----BEGIN LICENCE KEY-----\n") != 0) {
    puts("Failed to activate.");
    return 1;
  }

  /* ライセンスファイル2行目 */
  char flag[65];
  if (fgets(flag, 65, fp) == NULL) {
    puts("Failed to read file");
    return 1;
  }

  if (check(flag)) {
    puts("Failed to activate.");
    return 1;
  }

  /* ライセンスファイル3行目 */
  char end[27];
  if (fgets(end, 27, fp) == NULL) {
    puts("Failed to read file");
    return 1;
  }

  if (strcmp(end, "-----END LICENCE KEY-----\n") != 0) {
    puts("Failed to activate.");
    return 1;
  }

  fclose(fp);

  puts("Correct! This software is successfully activated!");
  return 0;
}
