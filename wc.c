///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          Lab 3 - wc - SRE - Spring 2023
//
///
/// wc - print line, word, and byte counts for each file
/// wc -l
///
/// @see     https://linuxcommand.org/lc3_man_pages/wc1.html
///
/// @file    wc.c
/// @author  Thanh Ly  thanhly@hawaii.edu
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>          // printf()
#include <stdlib.h>         // exit(1)
#include <ctype.h>          // isspace(), isalpha()
#include <string.h>         // strcmp()


struct wc {
    int lines; 
    int words; 
    int character;
};

#ifdef DEBUG
  struct hex_to_ascii {
      char binary[20];
      char ascii;
  };
#endif

#define arg_file 1
#define arg_opt  2 

void word_counter(struct wc *count, FILE *file );
void command_line_display(int argc, char *argv[], struct wc *count);

int main(int argc, char *argv[]) {

#ifdef DEBUG

	for(int i = 1; i < argc; i++){
    printf("argc %d: %s ", i, argv[i]);
  }
  printf("\n");

#endif
   
// check if a file name was provided as an argument. ./wc "filename.txt"
if (argc != 2) {
    printf("Usage: ./wc FILE\n");
}
 
FILE *file = fopen(argv[arg_file], "r"); // open file from command
    
// check to see if the file was opened successfully
if (file == NULL) { 
      printf("Error opening %s\n", argv[arg_file]);
    exit(1); 
} 

// Initialize counters for lines, words, and characters 
struct wc count = {count.lines = 0, count.words = 0, count.character = 0};


word_counter(&count, file);   // Open a file from argv[1] "file from command 
                                  // line".
command_line_display(argc,argv, &count);

#ifdef DEBUG
    printf("Lines: %d \t Words: %d \t Characters: %d \t %s\n", count.lines, 
            count.words, count.character, argv[2]);
    printf("characters: %d \t%s\n", count.character,argv[2]);
    printf("Lines: %d\t%s\n", count.lines,argv[2]);
    printf("words: %d\t%s\n", count.words,argv[2]);  
#endif
    
fclose(file);   // Close the file before exiting the program 

return 0;  
}


///////////////////////////////////////////////////////////////////////////////
// This function if the 1st arguments is just the file, display words, character
// lines, and word. Otherwise if the argument is -m, -l, -w display its 
// respective information.
// @usage: -m prints out the character counts.
//         -l prints out the line counts.
//         -w prints out the word counts.
// @param: int argc, char *argv[], struct wc *count 
// @return: void function does not return anything.
///////////////////////////////////////////////////////////////////////////////
void command_line_display(int argc, char *argv[], struct wc *count) {
    if (argc == 2) {
     printf("Lines: %d \t Words: %d \t Characters: %d \t %s\n", count->lines, 
            count->words, count->character, argv[arg_file]);
  }
    else if (strcmp(argv[arg_opt], "-m") == 0) {
      printf("character: %d \t%s\n", count->character,argv[1]);
  }
    else if (strcmp(argv[arg_opt], "-l") == 0) {
        printf("line: %d\t%s\n", count->lines,argv[arg_file]);
  }
    else if (strcmp(argv[arg_opt], "-w") == 0) {
        printf("word: %d\t%s\n", count->words,argv[arg_file]);
  } 
}

///////////////////////////////////////////////////////////////////////////////
// This function takes in a struct wc, and a file. It count words, character,
// and lines.
// setting the struct wc members with it's respective value.
// @param: struct wc *word_count, FILE *file 
// @return: void function does not return anything.
///////////////////////////////////////////////////////////////////////////////
void word_counter(struct wc *count, FILE *file ) {
  char c;   // Stores each character as it is read from the file 
  int in_word = 0;  // need this to count word with delimiter
    
    while ((c = fgetc(file)) != EOF) {
    count->character++; // count the character in a file

    // count the line in a file
    // look how different machine compute new line.
    if (c == '\n') {
        count->lines++;
    }

    // see https://en.cppreference.com/w/c/string/byte for ascii chart of 
    // parsed character.
    if (isspace(c) || (iscntrl(c) && isalpha(c))) {

      if (in_word) {
      in_word = 0;    // completed parse next word.
        count->words++;
      }
    } else {
      in_word = 1;    // Words has not been completed.
    }
  }
}

// @todo: if time permit using word_counter() function to parse binary and hex
// file, possibly create a struct of vector and writing to a file from binary to
// ascii.

#ifdef DEBUG
    void hex_converter(struct hex_to_ascii *hex_in, FILE *file ) {

    }
#endif