# Simple Shell in C

This project is a simple UNIX command line interpreter written in C. The shell can handle basic commands and functionality, such as executing programs, handling arguments, and managing the PATH.

## Resources
- Unix shell
- Thompson shell
- Ken Thompson
- Everything you need to know to start coding your own shell concept page

## Learning Objectives
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?

## Installation

To install and use this simple shell, follow these steps:

1. Clone the repository:
```
git clone https://github.com/your_username/holbertonschool-simple_shell.git
```

2. Change to the project directory:
```
cd holbertonschool-simple_shell
```

3. Compile the source code with the following command:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

4. Run the shell in interactive mode:
```
./hsh
```

5. Alternatively, you can run the shell in non-interactive mode:
```
echo "/bin/ls" | ./hsh
```

## Usage

The simple shell can be used in both interactive and non-interactive mode. In interactive mode, the shell will display a prompt and wait for the user to type a command. In non-interactive mode, the shell can be used by piping commands to it.

This shell supports basic commands, handles command line arguments, manages the PATH, and implements `exit` and `env` built-ins.

### Example

Here is an example of using the shell in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

And in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
```
## Flowchart
![image](https://user-images.githubusercontent.com/124347057/233840291-eace86c9-1ec5-49db-a417-127849e1d6df.png)



## Contributing

Please read the [AUTHORS](AUTHORS) file for details on our code of conduct, and the process for submitting pull requests.

## License

This project is licensed under the MIT License.



