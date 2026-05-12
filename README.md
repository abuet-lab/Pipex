*This project has been created as part of the 42 curriculum by <abuet>.*

## Description

Pipex is a project that reproduces the behavior of the shell pipe mechanism.
It simulates the following shell command:
cmd1 < infile | cmd2 > outfile

## Instructions

**Compilation:**
make

**Execution:**
./pipex infile "cmd1" "cmd2" outfile

**Example:**
- ./pipex infile "grep bonjour" "wc -l" outfile 
- equivalent to: grep bonjour < infile | wc -l > outfile

## Resources

- Linux man pages: man pipe, man fork, man execve, man dup2
- 42 subject: pipex.pdf

**AI usage:**
- Claude was used to help understand and debug certain parts