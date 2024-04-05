program = eenheid

extern_lib =

compiler = gcc $(develop_flags)

develop_flags = -Wall -Wextra -pedantic -pedantic-errors -g
release_flags = -O3 -DRELEASE

source_dir = src
object_dir = obj
binary_dir = bin
tests_dir = tests

source_sub = $(wildcard $(source_dir)/*/*.c)
object_sub = $(patsubst $(source_dir)/%.c,$(object_dir)/%.o,$(source_sub))

source = $(wildcard $(source_dir)/*.c)
object = $(patsubst $(source_dir)/%.c,$(object_dir)/%.o,$(source))

object_all = $(object) $(object_sub)

binary = $(binary_dir)/$(program)

sub_dirs = $(filter-out $(wildcard $(source_dir)/*.c) $(wildcard $(source_dir)/*.h),$(wildcard $(source_dir)/*))
objdirs = $(patsubst $(source_dir)/%,obj/%,$(sub_dirs))

all: $(objdirs) $(object_all) $(binary)

$(binary): $(object_all)
	$(compiler) -Llib -o $(binary) $(object_all) $(extern_lib) 

$(object_dir)/%.o: $(source_dir)/%.c
	$(compiler) -Iinc -c -o $@ $<

$(objdirs):
	@mkdir -p $@

run: all
	./$(binary)

gdb:
	gdb ./$(binary)

clean:
	rm $(object_dir)/* -rf
	rm $(binary) -f

init:
	mkdir -p $(source_dir) $(object_dir) $(binary_dir) $(tests_dir)
	cp ../Makefile.tests $(tests_dir)/Makefile
	$(MAKE) -C $(tests_dir) init

install_dir = /usr/bin

install: compiler := gcc $(release_flags)
install: clean all
	sudo cp $(binary) $(install_dir)

install_library: compiler := gcc $(release_flags)
install_library: clean all
	mkdir -p lib
	ar rcs ./lib/libeenheid.a ./obj/eenheid/e_test.o
	sudo cp ./src/eenheid/eenheid_internal.h /usr/include
	sudo cp ./src/eenheid/eenheid.h /usr/include
	sudo cp ./lib/libeenheid.a /usr/lib

remove:
	sudo rm $(install_dir)/$(program)

tests: all
	$(MAKE) -C tests run

bear: clean
	bear -- make
