# Decaf

A compiler for Compilers and Program Analysis [CS126](http://cs.brown.edu/courses/cs126/) by [Alex Varga](https://github.com/asvarga) and [Denizalp Goktas](https://github.com/denizalp).

## Compiler Summary
The compiler makes use of Flex to build a lexer to tokenize the input file. The output of this lexer is then fed to the the parser generated by Bison. This parser then builds an abstract syntax tree from the tokenized input. Following this step, we do one pass over the input to set links in each node of the AST to the parent class to facilitate the code generation. Finally, when the pass is done we use a visitor pattern and LLVM's IR to generate the code.

## Optimizations
We opted to use LLVM as it allowed automatic optimization of the operation. One can look further at the end of `parser.ypp` file and through the `codeGenV.cpp` file in order to see these optimizations in more detail. Broadly, the optimizations that LLVM takes care of are:
- Control flow graph simplification
- Expression re-associations
- Common sub-expression re-association.
- Peephole optimizations.

## Explanation of files
- `lexer.l`: This is the lex file that details the lexeme of the decaf language. This is the lexer we have used.
- `parser.ypp`: This is bison file that details the grammar of decaf. This is the parser we used. This file parses the decaf file based on the tokenization outputed by the lexer.
- `ast.h/ast.cpp`: These files contain the definition of each node in the AST.
- `printerV.h/printerV.cpp`: These files contain a printing class that makes use of the visitor pattern to print the parsed structure of a file. It can be used for debugging purposes.
- `pass1V.h/pass1V.cpp`: These files contain a pass class that makes used of the visitor pattern to set certain variables in each node of the AST tree, once the file has been parsed.
- `codeGenV.h/codeGenV.cpp`: These files contain a code generation class that makes use of the visitor pattern. Each function in codeGenV.cpp, uses the LLVM API to generate an LLVM Internal Representation (IR). This IR can then be used to generate machine code.
- `symbolTable.h/symbolTable.cpp`: These files contain the symbol table structure that we used. We organized the symbol table so that we have a global table that stores symbols for each class. Each class then stores in a map functions and class variables. Furthermore, each class has a list of scopes that store a separate variable table in order to distinguish the different scopes withing the functions of one program.
- `makeClasses.py`: A simple python script to output a basic AST structure given a set of AST node names. This allowed the automation of some of our coding process.
- `decaf`: A simple python script that automates and decomposes the parses, compiling and linking phases of our compiler.

## Output example
```
$ ./test/fib.decaf
How many fibs? : 10
fib(1) = 1
fib(2) = 1
fib(3) = 2
fib(4) = 3
fib(5) = 5
fib(6) = 8
fib(7) = 13
fib(8) = 21
fib(9) = 34
fib(10) = 55

$ ./test/adder.decaf
Enter two integers:
3
4
3 + 4 = 7
```

## Requirements
In order for the compiler to run correctly, make sure to have flex 2.6.4, GNU Bison 3.0.4 and LLVM 6.0.0.

## Building the Compiler

```
$ cd [PathToDecaf]/src
$ make
```

## Running a Program

Once the compiler is `make`'d, the `decaf` python script will compile and run your program.

It takes the optional flags `-c`, `-l`, `-r` for restricting to compilation/linking/running respectively.

```
$ cd [PathToDecaf]
$ ./decaf [PathToProgram]
```

Alternatively, you can add `[PathToDecaf]` to your $PATH or add a symlink to the `decaf` python script.

Then `.decaf` files with hashbangs can be run like:

```
$ cd [PathToDecaf]/src/test2
$ ./test0.decaf
```

## To-do
Currently, the compiler is able to output code correctly for most test cases except those making use of parent/child class structures.
