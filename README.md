# OS-lessons

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


### timer
the user can know how many time an executable took by adding "time" before the executable name
```
$ time ./outputfile
```