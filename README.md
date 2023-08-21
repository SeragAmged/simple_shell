# 0x16. C - Simple Shell

Welcome to the repository for the **0x16. C - Simple Shell** project. This project is a simple implementation of a shell program in the C programming language.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Features](#features)
- [Getting Started](#getting-started)

## Introduction

The **0x16. C - Simple Shell** project is a basic shell program that allows users to interact with their operating system through a command-line interface. It provides a simplified version of the typical shell functionality, such as executing commands, managing processes, and handling I/O redirection.

## Usage

To use the Simple Shell, compile the provided C source files and run the resulting executable. Once the shell is running, you can enter commands just like you would in a regular terminal.

```
$ gcc -o simple_shell *.c
$ ./simple_shell
Simple Shell $ ls -l
total 32
-rw-r--r-- 1 user user  234 Aug 22 10:00 main.c
-rw-r--r-- 1 user user 1376 Aug 22 10:01 shell.c
-rw-r--r-- 1 user user  879 Aug 22 09:59 shell.h
-rw-r--r-- 1 user user  567 Aug 22 09:57 utils.c
-rw-r--r-- 1 user user  312 Aug 22 09:57 utils.h
Simple Shell $
```

## Features

- Command execution: Run commands just like you would in a regular shell.
- Built-in commands: Includes a few basic built-in commands such as `cd` and `exit`.

## Getting Started

1. Clone this repository using `git clone https://github.com/your-username/simple-shell.git`.
2. Compile the source files using `gcc -o simple_shell *.c`.
3. Run the executable with `./simple_shell`.
4. Start entering commands and interacting with the shell.
