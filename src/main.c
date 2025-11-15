#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_MAX 100
#define DELIM ","

char *ifile, *ofile;
unsigned filter_age_max;
FILE *istream, *ostream;

const char USAGE[] =
    R"(Filters CSV rows, keeping only those with provided maximum age
%1$s max-age [input-file] [output-file]

Example: 
%1$s max-age input.csv output.csv
%1$s max-age input.csv (output to stdout)
%1$s max-age           (input from stdin, output to stdout)
)";

void filter_stream(FILE *istream, FILE *ostream) {
  char line[LINE_MAX];
  char *fgets_return;
  char *name, *age_str;
  size_t line_no = 0;

  while ((fgets_return = fgets(line, LINE_MAX, istream))) {
    ++line_no;

    if (fgets_return && *fgets_return != '\n') {
      if (strlen(line) > 1) {
        name = strtok(fgets_return, DELIM);
        age_str = strtok(NULL, DELIM);

        if (!age_str) {
          fprintf(stderr,
                  "Line %zu: no age was given my friend!!! I'm going to get "
                  "furious soon...\n",
                  line_no);

          continue;
        }
      }
    } else {
      fprintf(stderr, "Line %zu: Nothing to read here.\n", line_no);

      continue;
    }

    unsigned age;
    int recognized_count = sscanf(age_str, "%d", &age);
    if (recognized_count == 1) {
      if (age <= filter_age_max) {
        fprintf(ostream, "%s, %s", name, age_str);
      } else {
        fprintf(stderr, "Line %zu: Age is to high bro!\n", line_no);
      }
    } else {
      fprintf(stderr, "Line %zu: Age is not a number\n", line_no);
    }
  }
}

int main(int argc, char *argv[]) {
  switch (argc) {
  case 4:

    ofile = argv[3];
  case 3:

    ifile = argv[2];
  case 2:

    if (!sscanf(argv[1], "%d", &filter_age_max)) {
      puts("First argument is not an age.");
      exit(EXIT_FAILURE);
    }
    break;
  default:
    printf(USAGE, argv[0]);
    return EXIT_SUCCESS;
  }

  if (ifile && strcmp(ifile, "stdin") != 0) {
    istream = fopen(ifile, "r");
    if (!istream) {
      fprintf(stderr, "Cant open file! Maybe file does not exist?");

      return EXIT_FAILURE;
    }
  } else {
    istream = stdin;
  }

  if (ofile) {
    ostream = fopen(ofile, "w");
    if (!istream) {
      fprintf(stderr, "Cant create file! Maybe no permission to create file");

      return EXIT_FAILURE;
    }

  } else {
    ostream = stdout;
  }

  filter_stream(istream, ostream);
}