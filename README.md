# pipex

![Language](https://img.shields.io/badge/language-C-blue)
![School](https://img.shields.io/badge/school-42-black)

A C program that reproduces the behavior of a **Unix shell pipe** with input and output redirection. It is an introduction to process management on Unix: creating processes, connecting them with pipes and running external programs.

> Project from the [42 school](https://42.fr/) curriculum, written in C following the 42 coding standard (the *Norm*).

---

## What it does

This command:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

behaves exactly like this shell command:

```bash
< infile cmd1 | cmd2 > outfile
```

`cmd1` reads from `infile`, its output is sent through a pipe to `cmd2`, and the result is written to `outfile`.

### Example

```bash
./pipex input.txt "grep hello" "wc -l" output.txt
# same as: < input.txt grep hello | wc -l > output.txt
```

## How it works

```text
 infile ──► [ child 1: cmd1 ] ──► pipe ──► [ child 2: cmd2 ] ──► outfile
```

1. **Create a pipe** with `pipe()`, which gives a read end and a write end.
2. **Fork a first child** with `fork()`. It redirects its input to `infile` and its output to the write end of the pipe using `dup2()`, then runs `cmd1` with `execve()`.
3. **Fork a second child**. It redirects its input to the read end of the pipe and its output to `outfile`, then runs `cmd2`.
4. **Find each command's path** by searching the directories listed in the `PATH` environment variable, as a shell would.
5. **Close unused file descriptors** and wait for both children with `waitpid()`.

### Error handling

- Missing or unreadable input file
- Output file that cannot be created or written
- Command not found or not executable
- Wrong number of arguments
- Failure of system calls (`pipe`, `fork`, `execve`…)

Error messages follow the format of the shell, and file descriptors and memory are released in every case.

## Project structure

```text
.
├── libft/      # My own C library (reused from a previous project)
├── pipex.c     # Process creation, redirections and command execution
├── pipex.h     # Prototypes and includes
├── main.c      # Entry point and argument checking
└── Makefile
```

## Build

```bash
git clone https://github.com/abuet-lab/<Pipex>.git
cd <Pipex>
make
```

| Rule          | Description |
|---------------|-------------|
| `make`        | Compiles libft and the `pipex` executable |
| `make clean`  | Removes object files |
| `make fclean` | Removes object files and executables |
| `make re`     | Rebuilds everything from scratch |

## Testing

Compare the output of `pipex` with the real shell:

```bash
./pipex infile "ls -l" "wc -l" outfile1
< infile ls -l | wc -l > outfile2
diff outfile1 outfile2
```

Check for leaks and unclosed file descriptors:

```bash
valgrind --leak-check=full --track-fds=yes ./pipex infile "cat" "wc -l" outfile
```

## What I learned

- How a shell runs pipelines under the hood
- Creating and synchronizing processes with `fork` and `waitpid`
- Inter-process communication with **pipes**
- Redirecting input and output with **`dup2`** and **file descriptors**
- Running programs with **`execve`** and resolving their path through `PATH`
- Careful resource management: closing every file descriptor and freeing all memory
