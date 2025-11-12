#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_MAX 100
#define DELIM "," // CSV delimiter

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

// void filter_stream(FILE *istream, FILE *ostream) {
//   char line[LINE_MAX];
//   char *fgets_return;
//   char *name, *age_str;
//   size_t line_no = 0;

//   while (
//       // Read a line from `istream` and assign the return value to
//       // `fgets_return`
//       // YOUR CODE HERE
//   ) {
//     ++line_no;

//     if (fgets_return && *fgets_return != '\n') {
//       if (strlen(line) > 1) {
//         // Assign `name` and `age_str` using `strtok`
//         // YOUR CODE HERE

//         // Alternative to strtok:
//         // sscanf(line, "%*[^,],%d", &age);

//         if (!age_str) {
//           // Error message
//           // YOUR CODE HERE
//           continue;
//         }
//       }
//     } else {
//       // Error message
//       // YOUR CODE HERE
//       continue;
//     }

//     // Age processing
//     unsigned age;
//     auto recognized_count = sscanf(age_str, "%d", &age);
//     if (recognized_count == 1) {
//       if (age <= filter_age_max) {
//         // Forward input line to `ostream`
//         // YOUR CODE HERE
//       }
//     } else {
//       // Error message
//       // YOUR CODE HERE
//     }
//   }
// }

int main(int argc, char *argv[]) {
  switch (argc) {
  case 4:
    // max-age ifile ofile
    ofile = argv[3];
  case 3:
    // max-age ifile
    ifile = argv[2];
  case 2:
    // max-age
    if (!sscanf(argv[1], "%d", &filter_age_max)) {
      puts("First argument is not an age.");
      exit(EXIT_FAILURE);
    }
    break;
  default:
    printf(USAGE, argv[0]);
    return EXIT_SUCCESS;
  }

  if (ifile) {
    istream = fopen(ifile, "r");
    if (!istream) {
      perror("Cant open file! Maybe file does not exist?");
      return EXIT_FAILURE;
    }
    // Open `ifile` and assign it to `istream`
    // YOUR CODE HERE

    // Exit program with an error message if file cannot be opened
    // YOUR CODE HERE
  } else {
    istream = stdin;
    // Set `istream` if no file provided
    // YOUR CODE HERE
  }

  if (ofile) {
    ostream = fopen(ofile, "w");
    if (!istream) {
      perror("Cant create file! Maybe no permission to create file");
      return EXIT_FAILURE;
    }
    // Open `ofile` and assign it to `ostream`
    // YOUR CODE HERE

    // Exit program with an error message if file cannot be opened
    // YOUR CODE HERE
  } else {
    ostream = stdout;
    // Set `ostream` if no file provided
    // YOUR CODE HERE
  }

  // filter_stream(istream, ostream);
}