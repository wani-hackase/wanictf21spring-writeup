#include <stdio.h>
#include <unistd.h>

int super_complex_flag_print_function(void);

// https://www.patorjk.com/software/taag/#p=display&f=ANSI%20Shadow&t=Timer
int show_description(void) {
  puts("");
  puts("  ████████╗██╗███╗   ███╗███████╗██████╗ ");
  puts("  ╚══██╔══╝██║████╗ ████║██╔════╝██╔══██╗");
  puts("     ██║   ██║██╔████╔██║█████╗  ██████╔╝");
  puts("     ██║   ██║██║╚██╔╝██║██╔══╝  ██╔══██╗");
  puts("     ██║   ██║██║ ╚═╝ ██║███████╗██║  ██║");
  puts("     ╚═╝   ╚═╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝");
  puts("");
  puts("I'll show the flag when the timer is 0 seconds.");
  puts("");
}

int timer(void) {
  int totalSeconds = 259200;
  int pastSeconds = 0;

  while (pastSeconds < totalSeconds) {
    printf("%d seconds left.\n", totalSeconds - pastSeconds);
    sleep(1);
    pastSeconds += 1;
  }
  return 0;
}

int main(void) {
  show_description();
  timer();
  super_complex_flag_print_function();

  return 0;
}
