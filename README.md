# Simple Shell in C

This is a simple shell program written in C, created by Caleb Kegera and John Mwanyasi. The purpose of this shell is to provide a basic command-line interface for users to interact with their operating system.

## Features

- **Command Execution**: Users can execute various commands available in their operating system, such as running programs, navigating directories, and managing files.
- **Built-in Commands**: The shell supports a set of built-in commands, including   cd   (change directory) and   exit   (terminate the shell).
- **Input/Output Redirection**: Users can redirect input and output streams to and from files, allowing for flexible handling of data.
- **Background Execution**: The shell supports running commands in the background, enabling users to continue using the shell while a command is running.
- **Signal Handling**: Proper signal handling ensures the shell responds appropriately to signals such as Ctrl+C.

## Getting Started

To compile and run the shell, follow these steps:

1. Clone the repository:   git clone https://github.com/mwanyambu/simple-shell.git   
2. Navigate to the project directory:   cd simple-shell  
3. Compile the source code:   gcc shell.c -o shell  
4. Run the shell:   ./shell  

## Usage
Usage: simple_shell
Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)
You don’t have to:

use the PATH
implement built-ins
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments
execve will be the core part of your Shell, don’t forget to pass the environ to it…
Handle command lines with arguments
Handle the PATH
fork must not be called if the command doesn’t exist
Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit
Implement the env built-in, that prints the current environment
Write your own getline function
Use a buffer to read many chars at once and call the least possible the read system call
You will need to use static variables
You are not allowed to use getline
You don’t have to:

be able to move the cursor
ou are not allowed to use strtok
handle arguments for the built-in exit
Usage: exit status, where status is an integer used to exit the shell
Implement the setenv and unsetenv builtin commands

setenv
Initialize a new environment variable, or modify an existing one
Command syntax: setenv VARIABLE VALUE
Should print something on stderr on failure
unsetenv
Remove an environment variable
Command syntax: unsetenv VARIABLE
Should print something on stderr on failure
Implement the builtin command cd:

Changes the current directory of the process.
Command syntax: cd [DIRECTORY]
If no argument is given to cd the command must be interpreted like cd $HOME
You have to handle the command cd -
You have to update the environment variable PWD when you change directory
Handle the commands separator ;
Handle the && and || shell logical operators
Implement the alias builtin command
Usage: alias [name[='value'] ...]
alias: Prints a list of all aliases, one per line, in the form name='value'
alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value
Handle variables replacement
Handle the $? variable
Handle the $$ variable
Handle comments (#)
Usage: simple_shell [filename]
Your shell can take a file as a command line argument
The file contains all the commands that your shell should run before exiting
The file should contain one command per line
In this mode, the shell should not print a prompt and should not read from stdin
Once the shell is running, you can start entering commands. Here are a few examples:

- Execute a program:   ls -l  
- Change directory:   cd /path/to/directory  
- Redirect input/output:   command < input.txt > output.txt  
- Run a command in the background:   command &  

For a complete list of supported commands and their usage, please refer to the documentation.

## Contributing

We welcome contributions to improve this simple shell. If you encounter any bugs, have suggestions, or would like to add new features, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgements

We would like to thank all team lead of  ALX SE  especially Julien Barbier  for providing the platform


Happy coding!

Caleb Kegera and John Mwanyasi
