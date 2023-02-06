# OS-lessons 

## User-Interface (UI) definition
	**Interface** between resources (CPU, RAM, files...) and user

## standard UI

### Very general, Utilisation with every device

- Windows : intuitive, Mutli-media, paying
- Linux : open source, secured
- Android : open source, intuitive, secured, Multi-media
- MacOs	: intuitive, Multi-media, paying
- Unix : open source, secured

## UI spécialisés
### In real time Systems

- coffee machine

- industrial machines

# ressources 

## RAM

## processors

- CPU : computer's "brain" responsible of the sofware instructions
CPU are smart enough to do multi-tasks

- GPU : made to treate parallelism (3D-render or animation movies)

- TPU made to treate auto-learn. Very efficient in training neronal files

## I/O Fichiers

## Terminal

## Protection

## Réseau

## Memory

malloc(size) => Pointeur
-> based on mmap. Bellow mmap, we need to know how the RAM works<br />

MMU : located on the processors (  [CPU]->[MMU]->[ RAM ]  ) the MMU is used to manage the memory

### STACK 
place where the launched code is launched (source code and variables)

### TAS
place where the mallocs are stored

## Ordonnanceur
decides which task need to be exectuted first and how to distribute the ressources (processors / memory) between the currenct tasks

## BIOS
Bellow the UI<br />
BIOS : Basic Interface Output System. It's located in the ROM (Read Only Memory)


## Kernel
just over BIOS

Shell :  Situé juste au-dessus du Kernel 
- bourne Shell, avaible on every Unix 
- Bash => linux & unix
<br />
Applications > Programs

In C programming, there are 3 flux : `stdin`, `stdout` and `stderr`


### Output

- redirect a program output to a file `$ ./main>>file.txt`
- redirect a program error output to a file `$ ./main 2> file1.txt` (`2>` stands for stderr)
- redirect the error output to trash (if we don't care about it) `$ ./main 2> /dev/null`

# terminal commands

bash = Born Again SHell

## basic terminal shortcuts

- Ctrl+C : **interruption**
- Ctrl+Z : **suspension** ; `fg` (relaunch in foreground) ; `bg` (relaunch in background)
- Ctrl+/ : **interruption** with a memory clean-up
- Ctrl+S : turn **off** the screen update
- Ctrl+Q : turn **on** the screen update
- Ctrl+D : **kills** the entrance flux
- Ctrl+U : **erase** the actual line

## commands

- `$ whereis file` returns the path of the desired file
- to compile a bash file, use `$ chmod 700 file_name`, then `$ ./file_name`
- `$ find start_point -name "file_name" <-print>` (recursive ls)

### Normal execution 
`stdin` => command execution => `stdout`
- Output 1 is `stdin`
- Output 2 is `stdout`
- Output 3 is `stderr`
- Execute a command in **background** `$ command [args] &`
- redirect the `stdout` of command1 to the `stdin` of command2, use "Pipe character" `$ command1 | command2`
- research a char in a file `grep`, for example `$ grep 9 < myfile.csv`
- display a file `cat`, for example `$ cat myfile.csv`

### character management

- `*` replace every char, even an empty set
- `?` replace one char (precisely one)
- `[a-z]` or `[xyz]` stands for one jocker char in this set
- `~` = `HOME`
- `${string%xxxx}` parse the output : `abcdxxxx > abcd`
  
### Variables

`env` shows all the environment variables, for example `USER` is username
- assign or initialization `$ VAR=value` (VAR isn't an environnement variable)
- set the variable as an environment variable `$ export VAR`
- get the value of the variable `$VAR` for example : `$ echo $VAR`
- char variables : `$ VAR2="toto $VAR"` won't replace `$VAR` with it's value use `$ VAR2='toto $VAR'` instead

### aliases
`$ \command` will execute the original linux command even if an alias is defined

### control structures

#### if
`$ if [condition]; then command ; fi` <br />
`$ if [condition]; then command elif [condition]; then command2 else fi`
#### for
`$ for variable in [list]; do command; done` <br />
`$ for variable in 'seq 1 10'; do echo $i; done`
#### calcul
`$ echo "5*4"` returns 5*4<br />
`$ echo "5*4" | bc` returns 20

### arguments
the arguments of a bash function should be passed this way : `$ function arg1 arg2 arg3`.<br />
In a bash file (`.sh`) there are two special arguments : 
- `$#` : return the number of arguments passed to the bash script
- `$*` : copy the arguments passed to the bash scrpit

### bash execution
You can write a bash script (`.sh` file) before the first execution, make `$ chmod 700 myfile.sh`<br />
to execute the bash script, do this : `$ ./myfile.sh arg1 arg2...` where the arguments can be optional

# C compilation
when compiling a c program, the user can define a value.<br />
for example :
```
$ gcc -D MYDEFINE=value -D MYDEFINE2=value2 -o outputfile sourcefile.c
```

`sourcefile.c` might starts with
```C
#ifndef MYDEFINE
    #define MYDEFINE init
#endif
#ifndef MYDEFINE2
    #define MYDEFINE2 init_else
#endif
```

###   optimisation
when compiling a c program, the user can optimize the output executable file
- `$ gcc -O0 -o outputfile sourcefile.c` stands for **no** optimisation
- `$ gcc -O1 -o outputfile sourcefile.c` stands for a **little** optimization
- `$ gcc -O2 -o outputfile sourcefile.c` stands for a **big** optimization
- `$ gcc -O3 -o outputfile sourcefile.c` stands for the **best** optimization


### step by step compilation
1. `$ gcc -c -Wall -Wextra file.c` creates an object file
2. `$ gcc files_to_link.o -lm -o output` transform the object file into an executable file

### quick compilation

`$ gcc file.c -o output`

### Makefile
`$ make` standard command to make (compile) the .c files only if they've been touched<br />
`$ make all` standard command to compile every files even if not touched

### Profiler
looks how the code is working (function calls, memory use...). Compile with `-pg` flag.<br />Run the program once `$ ./executable_name`. Then use gprof :<br />`$ gprof executable_name gmon.out > file_output`.

### timer
the user can know how many time an executable took by adding "time" before the executable name
```
$ time ./outputfile
```

## Function libraries
It's a bunch of functions already compiled with `gcc -c`, the functions are in a `.o` file

### static
- the code is copied to the final executable
- autonaumous program, no need to have another file
- the executable is bigger, that's a bad point considering the executable is loaded in memory
- creation : compile into **objects** ; then create the **archive**
```
$ gcc -c source1.c, source2.c
$ ar -r lib<NAME>.a source1.o source2.o
```

### dynamic (DLL)
- the code is linked (as a pointer) to the final executable
- better gestion of the memory
- no need to recompile the program after a verion change
- loaded once in memory (even if multiple programs calls it)
- creation : compile into **objects** ; then create the **archive**
```
$ gcc -c -fpic source1.c, source2.c
$ gcc -shared source1.o source2.o -o lib<NAME>.so
```
- use : `$ gcc file.c -l<NAME> -I. -o file`
- use : `$ gcc file.c -Wl,-rpath=/home/user/... -L/home/user/... -o file -l<NAME>`

# Processes
duplication process for example a calcul thread and an interactive thread finaly fetch the two threads<br />
Each thread have :
- state
- PID (unique number) > know if the thread is parent or son
- own stdout and stdin streams
....

### main process

**Init** process is the main process : load the memory (RAM and SWAP), check the BIOS, CPU... load the WIFI card...<br />The following command will display all the Processes:
- `$ ps f aux`
- use `$ ps f aux | grep <name>` to search a specific process
The pid of a process can be know with `getpid()` : int ; the father of the process is `getpspid()` : int

## Create a process
Using C programming, you can create a process : 
```C
#include <unistd.h>

pid_t myPid = fork();
```

the fork created will read the code the same way as the parent process, the only difference will be the pid value : 

1. `pid_t = -1` : error
2. `pid_t = 0` : son process
3. `pid_t > 0` : father process (the PID is the child PID)

### Advanced process options

Use `vfork` for a more **precise** fork process (no memory duplication). Use `clone` in **Linux** to fork and control every fork parameter.

### End a process

Use `exit()` function

Return values :
- `exit() = 0` : exit successful
- `0 < exit() < 255` : exit failed with error code in ] 0 ; 255 ]

Use `on_exit(void* f(int void*), void* arg)` or `atexit(void* function)` (less customizable) function to execute those functions at the process exit.
<br />Use `#include <sys/wait.h>`<br /> the function `_exit()` will not call the `atexit()` and `on_exit()`.

- `wait()` wait for the process to be ended (block the execution) function will return -1 > error or > PID or the ended process
- `waitpid()` it's not blocking the execution. Customizable version of `wait()` but other return values

`abort()` function kills the process. Creates a core file to store the stack trace<br />`assert()` macro will test a condition. If false, the program will be stop. (`#include <assert.h>`). The `-NDEBUG` parameter is present in the compilation command, no asserts will be execute.

#### unistd functions
functions included in `<unistd.h>` 
- `sleep(int)` sleeps for a specified amount of time in Seconds
- `usleep(int)` sleeps for a specified amount of time microSeconds
- `getenv(char*)` gets the env value for the specified variable
- `getgid()` get the gid of a process group
- `setgid(int)` set the gid of a process group

### error handling

get the error code : 

```C
#include <erno.h>
extern int errno;
```

displays the error message with `perror("fork")`


### Ressource 

Know about the Ressource disponibility : 

```C
#include <sys/resource.h>
int getrusage(int who, struct rusage *usage);
```
`who` can be : `RUSAGE_CHILDREN` or `RUSAGE_SELF`

Set the ressource limit : 

```C
int setrlimit (int ressource, const struct rlimit∗rlim)
```


Know about the time took by a process : 

```C
#include <sys/times.h>
clock_t times (struct tms∗ temps);
```


### Execute a program 

```C
#include <unistd.h>
int execve (const char∗ prog, const char∗∗ argv, const char∗∗ env) // program title, program arguments and program environment variables
execve ("./myprog", {"./myprog", "arg1", "arg2", NULL}, "environment_variables");
int execv (const char∗ prog, const char∗∗ argv) // same as above but without environment variables
int execl (const char* path, const char* prog, argv[1], argv[2]...); // last arg needs to be NULL
```
No code will be executed after the exec functions

```C
#include <stdlib.h>
int system(const char* command);
```

The code after the system function will be executed


## communication between processes

the return of a `main()` is like an `exit()`

from a parent code, you can find the returned value with the `wait(int*)` function, this function returns a 32-bit integer. To transform it into a 8-bit integer, you can use the macro `WEXITSTATUS(int)`. this is an example :

```C
int n = -1;
wait(&n);
n = WEXITSTATUS(n);
printf("return value: %d\n", n);
```

# Thread
A processor is multi-thread if it can handle at least two independant control flows. A thread can cut an application into multiple activities to run the part separately. It improve the processor usage. More work done every second. Programmation is easier because of the thread logic.

A thread is the same process (same PID) But each execute different code. The storage space is share between threads. If we change a variable in one thread, it will be change in all other threads.

It is possible to lock a variable inside of a thread.

In java, to use threads, we have to extends our personnal class with the thread class.

### Compilate a thread program
use this command : 
`$ gcc-D_REENTRANT -lpthread`

### Create a new thread

```C
#include <pthread.h>

int a = pthread_create(pthread_t *thread, pthread_attr_t *attr, void* (*function_to_execute) (void* arg), void *arg);
if(a == 0)
    printf("sucess\n");
else if(a > 0)
    printf("error with code: %d\n", a);
```