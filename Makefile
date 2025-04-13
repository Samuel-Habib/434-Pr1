all: main core_dump

main: main.c
	gcc main.c -o main

core_dump: core_dump.c
	gcc core_dump.c -o core_dump

clean:
	rm -f main core_dump
