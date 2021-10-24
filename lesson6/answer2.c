#include <stdio.h>
#include <stdlib.h>

static void do_word_count(FILE *f);

int main(int argc, char *argv[]) {
  
  if (argc == 1) {
    do_word_count(stdin);
  }
  else {
    
    int i;

    for (i = 1; i < argc; i++) {

      FILE *f = fopen(argv[i], "r");
      if (!f) {
        perror(argv[i]);
        exit(1);
      }
      do_word_count(f);
      fclose(f);
    }
  }
  exit(0);
}

static void do_word_count(FILE *f) {

  unsigned long count = 0;
  int c;
  int prev = '\n';

  while ((c = fgetc(f)) != EOF) {
    if (c == '\n') {
      count++;
    }
    prev = c;
  }
  if (prev != '\n') {
    count++;
  }
  printf("%lu\n", count);
}

