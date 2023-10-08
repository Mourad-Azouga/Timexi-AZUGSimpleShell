![AZUG__1_-removebg-preview](https://github.com/Mourad-Azouga/simple_shell/assets/130150919/956af586-2f4b-42ad-bbf5-34370625ae27)
# PROJECT AZUG - Simple shell for ALX SE projects


## Table of Contents

- Description
- Learning Objectives
- Requirements
- Usage
- Compilation
- Testing
- Allowed Functions and System Calls
- Authors

---

## Description

This is a custom shell (hsh) project developed as part of the Holberton School curriculum. The goal of this project is to create a simple Unix shell that mimics the basic functionality of the `/bin/sh` shell. The project involves designing and implementing various shell features, system calls, and functions.

---

## Learning Objectives

Upon completing this project, you should be able to explain the following concepts without the need for external references:

- The original Unix operating system's designer and implementer.
- The first version of the UNIX shell.
- The inventor of the B programming language (predecessor to C).
- Ken Thompson's contributions to computing.
- How a shell works.
- The meaning of PID (Process ID) and PPID (Parent Process ID).
- How to manipulate the environment of the current process.
- The difference between a function and a system call.
- How to create processes in Unix.
- The three prototypes of the main function.
- How the shell uses the PATH variable to locate programs.
- How to execute another program using the execve system call.
- How to suspend the execution of a process until one of its children terminates.
- The concept of EOF (End-of-File).

---

## Requirements

### General

- Editors allowed: vi, vim, emacs.
- All code files will be compiled on Ubuntu 20.04 LTS using `gcc` with the following flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- All code files should end with a newline.
- A `README.md` file at the root of the project folder is mandatory.
- Code should follow the Betty style guidelines and will be checked using `betty-style.pl` and `betty-doc.pl`.
- The shell should not have any memory leaks.
- Each source file should contain no more than 5 functions.
- All header files should be include guarded.
- System calls should be used only when necessary.
- Write a detailed README describing your project.
- Include an AUTHORS file listing all contributors to the repository.
- Use a single project repository for the group, and collaborate with your partner by adding them as a collaborator.

### Output

- Your shell should produce the same output as `/bin/sh` and the exact same error output.

---

## Usage

To use this custom shell (hsh), follow these instructions:

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/your-username/hsh.git
2. Navigate to the project directory:
    ```bash
    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
3. Run the shell in interactive mode:
     ```bash
     ./hsh
4. You can also use the shell in non-interactive mode by piping commands:
     ```bash
    echo "/bin/ls" | ./hsh
5. Exit the shell when you're done:
     ```bash
     exit
## Compilation

AZUG shell can be compiled using the following code:
   ```bash
    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

