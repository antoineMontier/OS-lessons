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
- Execute a command in **background** `$ command [args] &`
- redirect the `stdout` of command1 to the `stdin` of command2, use "Pipe character" `$ command1 | command2`
- research a char in a file `grep`, for example `$ grep 9 < myfile.csv`
- display a file `cat`, for example `$ cat myfile.csv`

### character management

- `*` replace every char, even an empty set
- `?` replace one char (precisely one)
- `[a-z]` or `[xyz]` stands for one jocker char in this set
- `~` = `HOME`

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
```
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