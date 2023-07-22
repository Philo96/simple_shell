# Simple Shell Team Project

## Overview

The Simple Shell Team Project is a collaborative effort completed using the powerful C programming language and adhering to the guidelines of the Shell Betty linter. This project aims to create a user-friendly, efficient, and reliable UNIX command language interpreter known as "hsh."

## General Requirements

To maintain consistency and ensure a high-quality codebase, all project files are compiled on Ubuntu 20.04 LTS using the gcc compiler. The compilation process follows strict options, including -Wall, -Werror, -Wextra, -pedantic, and -std=gnu89, to catch any potential issues at compile time. Additionally, each file in the project ends with a new line, maintaining a clean code structure.

## Project Structure

A well-organized project is essential for clear communication and easy collaboration. Therefore, the root folder of the project must contain a mandatory README.md file. This README provides a comprehensive description of the project, its functionality, and its usage guidelines. Throughout the development process, the Betty style is adhered to, using betty-style.pl and betty-doc.pl for consistency and readability.

## Memory Leak-Free Shell

One of the primary goals of this project is to create a reliable and efficient shell. As such, utmost care has been taken to ensure that the hsh shell is entirely free from memory leaks. A rigorous testing and debugging process has been employed to guarantee that the shell's memory usage remains stable and efficient.

## Code Modularity

To maintain a clean and organized codebase, each file is designed to contain no more than five functions. This ensures that each function remains focused and handles a specific set of tasks, promoting code readability and maintainability.

## Header Files

In keeping with best practices, all header files are protected with include guards. This approach prevents duplicate inclusion of header files, preventing potential compilation issues and promoting a clean, error-free codebase.

## Project Description

The hsh (simple shell) is a user-friendly UNIX command language interpreter. It enables users to interact with the system by reading commands from either a file or standard input and executing them efficiently.

## How hsh Works

1. **Prompt Display:** Upon launching the hsh shell, it prints a welcoming prompt, eagerly waiting for user commands.

2. **Child Process Creation:** When a command is entered, hsh creates a child process to handle its execution, ensuring smooth and independent execution.

3. **Command Verification:** The child process checks for built-in commands, searches for aliases in the PATH, and validates the presence of local executable programs to execute the user's command efficiently.

4. **Command Execution:** Once the command is verified, the child process replaces itself with the user's command, which can accept arguments for more dynamic functionality.

5. **Post-Execution and Re-prompting:** After the command execution completes, the program returns to the parent process, printing the prompt again, ready for a new command.

## Exiting hsh

To exit the hsh shell, users can simply press Ctrl-D or enter the command "exit" (with or without a status). This convenient feature allows users to terminate the shell gracefully whenever they wish.

## Non-Interactive Mode Support

The hsh shell is not only interactive but also supports non-interactive mode. This enables users to run scripts and execute multiple commands sequentially, extending its versatility.

## Compilation Process

Compiling the hsh shell is a straightforward process. Using the following command with gcc, all the necessary C files are combined and transformed into an executable named "hsh."

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
