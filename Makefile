program = eenheid

extern_lib =

compiler = gcc $(develop_flags)

version = gnu99

release_flags = -std=$(version) -O3

develop_flags = -Wall -std=$(version) -g

source_dir = src
object_dir = obj
binary_dir = bin

source_sub = $(wildcard src/*/*.c)
object_sub = $(patsubst $(source_dir)/%.c,$(object_dir)/%.o,$(source_sub))

source = $(wildcard $(source_dir)/*.c)
object = $(patsubst $(source_dir)/%.c,$(object_dir)/%.o,$(source))

object_all = $(object) $(object_sub)

binary = $(binary_dir)/$(program)

sub_dirs = $(filter-out $(wildcard src/*.c) $(wildcard src/*.h),$(wildcard src/*))
objdirs = $(patsubst src/%,obj/%,$(sub_dirs))

all: $(objdirs) $(object_all) $(binary)

$(binary): $(object_all)
	$(compiler) -o $(binary) $(object_all) $(extern_lib)

$(object_dir)/%.o: $(source_dir)/%.c
	$(compiler) -c -o $@ $<

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
	mkdir -p $(source_dir) $(object_dir) $(binary_dir)

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

release: 
	compiler = gcc $(release_flags)

remove:
	sudo rm $(install_dir)/$(program)
