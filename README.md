# pipex

> School project (42 / Epitech curriculum) — C

A program that reproduces the behaviour of a **shell pipe** between two commands, using low-level UNIX system calls.

```sh
./pipex infile "cmd1" "cmd2" outfile
# equivalent to:  < infile cmd1 | cmd2 > outfile
```

## How it works

The program creates a pipe, forks child processes, redirects file descriptors with `dup2`, resolves command paths from the `PATH` environment variable, and executes each command with `execve` — connecting the output of the first command to the input of the second.

## Tech stack

- **Language:** C
- **System calls:** `pipe`, `fork`, `dup2`, `execve`, `wait`
- **Build:** `Makefile`

## Build

```sh
make
```

## What I learned

- UNIX process creation and inter-process communication
- File descriptor redirection and pipes
- Parsing the `PATH` and executing external binaries
