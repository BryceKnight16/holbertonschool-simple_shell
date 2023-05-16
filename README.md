# Holberton School Simple Shell

This is a simple Unix shell implementation developed as part of the curriculum at Holberton School. The shell supports both interactive and non-interactive modes, basic command execution, including built-in commands and external commands.

## Getting Started

To get a copy of the simple shell up and running on your local machine, you can clone the repository using the following command:

```
git clone https://github.com/BryceKnight16/holbertonschool-simple_shell.git
```

## Features

- Interactive command execution
- Non-interactive command execution
- Executing commands from a file
- Handling command arguments
- Environment variable expansion
- Error handling and exit status
- Signal handling (Ctrl+C)
- Custom prompt display

## Usage

### Interactive Mode

To compile the shell, navigate to the project directory and use the following command:

```
make
```

This will compile the shell and create an executable file named `hsh`.

Once the shell has been compiled successfully, you can run it in interactive mode by executing the following command:

```
./hsh
```

You will then be presented with a command prompt `$`, where you can start entering commands.

### Non-Interactive Mode

To run the shell in non-interactive mode, you can pass a file containing commands as an argument to the shell executable. For example:

```
echo "/bin/ls" | ./hsh
```

This will execute the commands present in `/bin/ls` and then exit the shell.

## Built-in Commands

The shell supports the following built-in commands:

- `exit`: Exit the shell
- `env`: Print the current environment
- `pwd`: Show the path of the current working directory

## External Commands

The shell is capable of executing external commands by searching for the corresponding executable files in the directories listed in the `PATH` environment variable. It uses the `execve` system call to launch external programs.

## Makefile

The project includes a Makefile that simplifies the compilation process. Here are some useful commands:

- `make`: Compile the shell
- `make clean`: Remove object files
- `make re`: Perform a clean recompilation

## Contributing
Please read the [AUTHORS](AUTHORS) file for details on our code of conduct, and the process for submitting pull requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.



