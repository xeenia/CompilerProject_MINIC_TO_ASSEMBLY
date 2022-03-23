 MINIC_TO_ASSEMBLY_PROJECT
# MINIC_TO_ASSEMBLY
Translate a C program to Assembly.
--------------------------------------
* In this I created a compiler which translates a mini C program to Assembly. 
* This project has been written in C++ and with flex/bison and I programmed it in Visual Studio 2019.
* In order to see this program working you need to write a C program in "CProgram.txt" file and then rebuild.
* The results will be appeared in "AssemblyProgram.txt"
* Also, in file "examples.txt" I have write some examples so you can easily use.
--------------------------------------
## What you can write in CProgram.txt
1. Arithmetic Operators
  * +, -
  * ++, --
2. Relational Operators
  * < , >
  * <=, >=
  * ==, !=
3. Logical Operators
  * &&
  * ||
  * !
4. Bitwise Operators
  * ^
  * ~
5. Misc Operators
  * ()?
6. Loops
  * FOR: for( ; ; ), for( ; ; ){}
  * WHILE: while(), while(){}
  * DO WHILE: do{}while();
7. Conditional Statements
  * IF: if(), if(){}
  * IF ELSE: if() else, if(){}else{}, if(){}else, if()else{}
--------------------------------------
-  For example:
```
a=5;
a=a+10;
b=0;
b+=a;
while(b){
  d=10;
  b--;
}
for(a;a>10;a--)
  while(d)
    d--;
```
-------------------------------------------
