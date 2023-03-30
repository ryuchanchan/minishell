# Minishell
This program is a simple shell written in C. It provides the following features:

- Command execution by searching and launching the appropriate executable, based on the PATH variable or using a relative or absolute path.
- Syntax errors are generated when unquoted input is encountered.
- Proper handling of single and double quotes.
- Four redirections are supported: `<`, `>`, `<<`, and `>>`.
- Pipeline functionality to connect the output of each command to the input of the next command via a pipe.
- Environment variables that begin with `$` are expanded. However, the format `${foobar}` is not supported.
- Support for `$?`.
- `Ctrl-C`, `Ctrl-D`, and `Ctrl-\` signals are properly handled.
- Basic built-in functions for the following commands:
  - `echo`		(option `-n`)
  - `cd`
  - `pwd`		(no options)
  - `export`	(no options)
  - `unset`		(no options)
  - `env`		(no options or arguments)
  - `exit`		(no options)

## Usage
To use the minishell program, first compile it by executing the following command:

```bash
make
```

This will create an executable file named minishell. Note that compilation requires [The GNU Readline Library](https://tiswww.case.edu/php/chet/readline/rltop.html) to be installed, and you may need to update the Makefile path depending on your installation.

Once the program has been compiled, run it using the following command:

```bash
./minishell
```

This will launch the shell, and you can enter commands as needed. Output will be displayed as appropriate, and errors will be reported if they occur.

## Limitations
This shell is a very basic implementation and has several limitations:

- It only supports basic commands and features.
- Error handling and messages are limited.
- Limited interpretation of special characters, restricted to pipelines and redirections.
- Complex command structures like loops or conditional statements are not supported.
- Compatibility with all shells and operating systems cannot be guaranteed.

## Credits
This program was created by [ryu](https://github.com/ryuchanchan/) and [toryoshi](https://github.com/hidaytours) as a 42 assignment.
