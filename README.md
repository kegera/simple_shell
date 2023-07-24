# Simple Shell in C

This is a simple shell program written in C, created by Caleb Kegera and John Mwanyambu. The purpose of this shell is to provide a basic command-line interface for users to interact with their operating system.

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

Caleb Kegera and John Mwanyambu
