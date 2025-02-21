CC = gcc
CFLAGS = -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused \
-Wempty-body -Wlogical-op -Wold-style-declaration -Wmissing-parameter-type \
-Wignored-qualifiers -Winit-self -Wswitch-default -Wshadow -Wtype-limits \
-Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs \
-Wmissing-prototypes -Wmissing-declarations -Wold-style-definition \
-Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal \
-Wwrite-strings -Wno-long-long -std=gnu99 -Wstrict-prototypes \
-Wmissing-field-initializers -Wno-pointer-sign -O3
LIBS = -lm

.PHONY: all clean

all: testing_system.out

%.out: %.o function_applier.o main_test.o unit_tests.o
	$(CC) $^ -o $@ $(LIBS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

function_applier.o: function_applier.c function_applier.h
function_applier.o: main_test.c main_test.h
unit_tests.o: unit_tests.c unit_tests.h

clean:
	rm -f *.o *.out

