#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void readFile(char *file_location, char **text_in_file,unsigned long* buffer_size) {

  printf("Reading File...\n");

  char linebuffer[256];
  int imaginary_buffer_size = 0;

  FILE *file = fopen(file_location, "r");

  while (fgets(linebuffer, sizeof(linebuffer), file)) {
    size_t line_length = strlen(linebuffer);

    if (line_length + imaginary_buffer_size + 1 > *buffer_size) {
      *buffer_size *= 2;
      char* temp = realloc(*text_in_file, *buffer_size);
      if (temp == NULL) {
          perror("Error Assigining memory to heap");
          fclose(file);
          exit(1);
      }
     *text_in_file = temp;
  }
    strcat(*text_in_file,linebuffer);
    imaginary_buffer_size += line_length;
  }
  fclose(file);

  printf("Reading File Sucess\n");
  printf("-----------------------------------------------------------------\n");
}

