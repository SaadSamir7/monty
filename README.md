# Monty Bytecode Interpreter

![License](https://img.shields.io/badge/License-MIT-green)

## Project Overview

- **Project Name**: Monty Bytecode Interpreter
- **Project Type**: Group project
- **Author**: Julien Barbier
- **Weight**: 2
- **Team**: Youssef Elzedy, Saad Samir
- **Start Date**: October 16, 2023, 7:00 PM
- **End Date**: October 19, 2023, 7:00 PM
- **Checker Release Date**: October 17, 2023, 1:00 PM
- **Auto Review**: Will be launched at the deadline

## Learning Objectives

By the end of this project, you are expected to be able to explain without using Google:

### General
- What LIFO and FIFO mean.
- What a stack is and when to use it.
- What a queue is and when to use it.
- Common implementations of stacks and queues.
- Most common use cases of stacks and queues.
- The proper way to use global variables.

### Copyright and Plagiarism
- Understand the importance of creating original solutions.
- Avoid plagiarism and adhere to program rules.
- Strictly avoid publishing project content.

## Requirements

### General
- Allowed Editors: vi, vim, emacs
- Compilation on Ubuntu 20.04 LTS using `gcc` with options `-Wall -Werror -Wextra -pedantic -std=c89`.
- All files should end with a new line.
- A mandatory `README.md` file at the root of the project folder.
- Code should follow the Betty style and will be checked using `betty-style.pl` and `betty-doc.pl`.
- Maximum of one global variable allowed.
- No more than 5 functions per file.
- C standard library usage is allowed.
- Prototypes of all functions should be included in the header file named `monty.h`.
- Don't forget to push your header file.
- Include guards are required for all header files.
- Tasks should be completed in the order specified in the project.

### GitHub
- One project repository per group.
- Cloning, forking, or using a project repository with the same name before the second deadline will result in a 0% score.

## Resources

Please refer to the following resources for this project:

- [Google](https://www.google.com)
- [How do I use extern to share variables between source files in C?](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files-in-C)
- Stacks and Queues in C
- Stack operations
- Queue operations

## Tests

Collaboration on a set of tests is strongly encouraged to ensure project correctness.

## License

This project is licensed under the MIT License. Please refer to the [LICENSE](LICENSE) file for details.

## Data Structures

Please use the following data structures for this project. Ensure they are included in your header file, `monty.h`.

```c
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

## Compilation & Output

Compile your code using the following command:

```shell
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

- All output must be printed to `stdout`.
- Any error messages should be printed to `stderr`.

## The Monty Language

### Monty Bytecode Files

Monty bytecode files typically have the `.m` extension. Although the industry commonly uses this standard, it's not required by the language specification. Each file contains one instruction per line, with optional leading/trailing spaces.

Example Monty bytecode file (`example.m`):

```
push 0
push 1
push 2
  push 3
                   pall    
push 4
    push 5    
      push    6        
pall
```

Monty bytecode files can contain blank lines, and any additional text after the opcode or its required argument is not considered.

### The Monty Program

Usage:

```shell
$ ./monty file
```

- `file` is the path to the Monty bytecode file.
- If no file is provided or more than one argument is given, the program should print: "USAGE: monty file" and exit with `EXIT_FAILURE`.
- If it's not possible to open the file, it should print: "Error: Can't open file <file>" and exit with `EXIT_FAILURE`.
- If the file contains an invalid instruction, it should print: "L<line_number>: unknown instruction <opcode>" and exit with `EXIT_FAILURE`.
  - `<line_number>` starts at 1.
- The program runs the bytecode line by line, stopping if:
  - Every line is executed properly.
  - An error is found in the file.
  - An error occurs.
- If you run out of memory (`malloc` fails), the program should print: "Error: malloc failed" and exit with status `EXIT_FAILURE`.
- You must use `malloc` and `free` and are not allowed to use any other functions from `man malloc` (e.g., `realloc`, `calloc`, etc.).
