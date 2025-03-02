# Simple Shell

A simple UNIX command-line interpreter (shell) written in C. This project is a basic implementation of a shell, similar to `sh` or `bash`, but with limited functionality. It supports executing commands, handling built-ins, and basic error handling.

---

## Table of Contents
1. [Features](#features)
2. [Installation](#installation)
3. [Usage](#usage)
4. [Built-in Commands](#built-in-commands)
5. [File Structure](#file-structure)
6. [Contributing](#contributing)
7. [License](#license)

---

## Features
- **Command Execution**: Executes commands by forking and using `execvp`.
- **Built-in Commands**: Supports built-in commands like `cd` and `exit`.
- **Input Parsing**: Splits user input into tokens for execution.
- **Error Handling**: Displays errors for invalid commands or system call failures.
- **PATH Resolution**: Resolves the full path of commands using the `PATH` environment variable.

---

## Installation

### Prerequisites
- A UNIX-like operating system (Linux, macOS, etc.).
- GCC (GNU Compiler Collection) installed.

### Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/AhmedSaadKader/simple_shell.git

    Navigate to the project directory:
    bash
    Copy

    cd simple_shell

    Compile the shell using gcc:
    bash
    Copy

    gcc -Wall -Werror -Wextra -o shell main.c shell.c builtins.c helpers.c path.c

    Run the shell:
    bash
    Copy

    ./shell

## Usage

Once the shell is running, you can enter commands just like in a regular shell. For example:
bash
Copy

$ ls -l
$ pwd
$ cd /path/to/directory
$ exit

Example
bash
Copy

$ ./shell
$ ls
README.md  shell.c  main.c  builtins.c  helpers.c  Makefile
$ cd ..
$ pwd
/home/user
$ exit

Built-in Commands

The shell supports the following built-in commands:

    cd [DIRECTORY]: Change the current working directory.

    exit: Exit the shell.

File Structure

Here’s an overview of the files in the repository:
File	Description
shell.h	Header file with function prototypes, includes, and struct definitions.
main.c	Entry point of the shell. Handles the main loop and user input.
shell.c	Core logic for parsing and executing commands.
builtins.c	Implements built-in commands like cd and exit.
helpers.c	Utility functions for string manipulation, printing, etc.
path.c	Resolves the full path of commands using the PATH environment variable.
Makefile	Compilation rules for building the shell.
Contributing

Contributions are welcome! If you’d like to contribute, please follow these steps:

    Fork the repository.

    Create a new branch for your feature or bugfix.

    Commit your changes with clear and descriptive messages.

    Submit a pull request.

License

This project is licensed under the MIT License. See the LICENSE file for details.
Acknowledgments

    Inspired by the sh shell and other UNIX shells.

    Special thanks to the ALX Software Engineering program for guidance on this project.
