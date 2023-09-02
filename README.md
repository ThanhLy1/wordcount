# Word Count Program (wc)

A simple C program to replicate the 'wc' command in Linux, providing line, word, and character counts for text files.

## Overview

The **Word Count Program (wc)** aims to emulate the functionality of the 'wc' command in Linux, which prints line, word, and byte (character) counts for each specified file.

The program utilizes fundamental C programming concepts to achieve its goals. It parses text files character by character, identifying lines, words, and characters, and then provides appropriate count statistics. The program also includes an option to display specific count types when provided with command-line arguments such as '-m', '-l', and '-w'.

## Usage

To compile and run the program, follow these steps:

1. Open a terminal window.
2. Navigate to the directory containing the `wc.c` file using the `cd` command.
3. Compile the program by running the command: `gcc -o wc wc.c`
4. Run the program with the desired file as an argument. For example: `./wc filename.txt`

The program will display line, word, and character counts for the specified file. Additionally, you can use command-line options to display specific count types. For example:
- `-m`: Display the character count
- `-l`: Display the line count
- `-w`: Display the word count

## Additional Notes

- The program's core logic is implemented in the `word_counter` function, which counts lines, words, and characters in a file.
- The `command_line_display` function handles command-line arguments and displays count information accordingly.
- The program's `struct wc` stores the counts for lines, words, and characters.
- The program also includes optional debugging features when compiled with the `DEBUG` flag.

## Future Improvements

While the current version of the Word Count Program successfully accomplishes its intended purpose, there are potential enhancements that could be explored in the future:

- Implement additional options or statistics to further customize the output.
- Extend the program to handle binary and hexadecimal files using the `word_counter` function.
- Enhance error handling and user feedback to provide more informative messages in case of errors or incorrect usage.

For a more detailed understanding of the program's code and execution, you can explore the `wc.c` file directly.

## References

- [wc Command - Linux Command](https://linuxcommand.org/lc3_man_pages/wc1.html)

