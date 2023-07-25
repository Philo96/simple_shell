#include "shell.h"

void sig_handler(int sig);
int execute(char **args, char **front);

/**
 * sig_handler - Prints a new prompt upon a signal.
 * @sig: The signal.
 */
void sig_handler(int sig)
{
char *new_prompt = "\n$ ";

(void)sig;
signal(SIGINT, sig_handler);
write(STDIN_FILENO, new_prompt, 3);
}

/**
 * execute - executes command in a child process.
 * @args: array of arguments.
 * @front: double pointer to the beginning of args.
 *
 * Return: if an error occurs - a corresponding error code.
 *         O/w - The exit value of the last executed command.
 */
int execute(char **args, char **front)
{
pid_t child_pid;
int status, flag = 0, ret = 0;
char *command = args[0];

if (command[0] != '/' && command[0] != '.')
{
flag = 1;
command = get_location(command);
}

if (!command || (access(command, F_OK) == -1))
{
if (errno == EACCES)
ret = (create_error(args, 126));
else
ret = (create_error(args, 127));
}
else
{
child_pid = fork();
if (child_pid == -1)
{
if (flag)
free(command);
perror("Error child:");
return (1);
}
if (child_pid == 0)
{
execve(command, args, environ);
if (errno == EACCES)
ret = (create_error(args, 126));
free_env();
free_args(args, front);
free_alias_list(aliases);
_exit(ret);
}
else
{
wait(&status);
ret = WEXITSTATUS(status);
}
}
if (flag)
free(command);
return (ret);
}

/**
 * main - runs a simple UNIX command interpreter.
 * @argc: num of arguments supplied to the program.
 * @argv: array of pointers to the arguments.
 *
 * Return: return value of the last executed command.
 */
int main(int argc, char *argv[])
{
int ret = 0, retn;
int *exe_ret = &retn;
char *prompt = "$ ", *new_line = "\n";

name = argv[0];
hist = 1;
aliases = NULL;
signal(SIGINT, sig_handler);

*exe_ret = 0;
environ = _copyenv();
if (!environ)
exit(-100);

if (argc != 1)
{
ret = proc_file_commands(argv[1], exe_ret);
free_env();
free_alias_list(aliases);
return (*exe_ret);
}

if (!isatty(STDIN_FILENO))
{
while (ret != END_OF_FILE && ret != EXIT)
ret = handle_args(exe_ret);
free_env();
free_alias_list(aliases);
return (*exe_ret);
}

while (1)
{
write(STDOUT_FILENO, prompt, 2);
ret = handle_args(exe_ret);
if (ret == END_OF_FILE || ret == EXIT)
{
if (ret == END_OF_FILE)
write(STDOUT_FILENO, new_line, 1);
free_env();
free_alias_list(aliases);
exit(*exe_ret);
}
}

free_env();
free_alias_list(aliases);
return (*exe_ret);
}
