## Integration with gdb


`make`

`valgrind --vgdb=yes --vgdb-error=0 ./valgrind-gdb-test`

```
==4067== Memcheck, a memory error detector
==4067== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==4067== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==4067== Command: ./valgrind-gdb-test
==4067==
==4067== (action at startup) vgdb me ...
==4067==
==4067== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==4067==   /path/to/gdb ./valgrind-gdb-test
==4067== and then give GDB the following command
==4067==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=4067
==4067== --pid is optional if only one valgrind process is running
==4067==
```
In a different console open gdb:
`gdb ./valgrind-gdb-test`

`(gdb) target remote | vgdb`

```
(gdb) target remote | vgdb
Remote debugging using | vgdb
relaying data between gdb and process 4067
warning: remote target does not support file transfer, attempting to access files from local filesystem.
Reading symbols from /lib64/ld-linux-x86-64.so.2...Reading symbols from /usr/lib/debug//lib/x86_64-linux-gnu/ld-2.23.so...done.
done.
0x0000000004000cc0 in _start () from /lib64/ld-linux-x86-64.so.2
(gdb)
```


```
mo leak_check
```
