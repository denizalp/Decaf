
# export CC := clang
# export CXX := $(CC)++
# export AR := /usr/local/opt/llvm/bin/llvm-ar
# export LD := /usr/local/opt/llvm/bin/lld


parser: parser.ypp lexer.l visitor/ast.h visitor/ast.cpp
	flex lexer.l
	bison -d parser.ypp


compiler: parser lex.yy.c visitor/ast.cpp
	clang++ -std=c++11 -o parser parser.tab.cpp lex.yy.c visitor/ast.cpp -ll -g -ldl `llvm-config --cppflags --libs --libfiles core --ldflags --system-libs` 


# TESTS #
adder: compiler
	./parser test/adder.decaf
empty: compiler
	./parser test2/emptyClasses.decaf
test0: compiler
	./parser test2/test0.decaf
test1: compiler
	./parser test/adder.decaf

.PHONY: clean

clean:
	rm *.o parser.tab.cpp parser.tab.hpp lex.yy.c
