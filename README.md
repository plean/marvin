# marvin

A c program that interprate c declaration.
We did this program in a weekend.
You can compile it in french or english:
 * `make en`
 * `make fr`

### Bonus

You can:
 * Decalre multiple variables
 * Program point user mistake 

### Exemples

Errors
```
./marvin "int"
Line must finish with a ';'.
int
   ^

./marvin "int ;"
Empty declaration.
int
   ^
```
Simples tests
```
./marvin "int a;"
Declaration of a variable of type integer named a

./marvin "int a; int b;"
Declaration of a variable of type integer named a
Declaration of a variable of type integer named b

./marvin "int a, b;"
Declaration of a variable of type integer named a and of a variable of type integer named b
```
Hard tests
```
./marvin "long (*f)(char *str);"
Declaration of a pointer on function f who take a variable of type pointer on character named str into parameter and return a long

./marvin "int a, *b;"
Declaration of a variable of type integer named a and a variable of type pointer on integer named b

./marvin "int a, (*b)(int c);"
Declaration of a variable of type integer named a and a pointer on function b who take a variable of type integer named c into parameter and return a integer
```
functions
```
./marvin "int aff_nbr(int a);"
Declaration of a function aff_nbr who take into parameter a variable of type integer named a and return a integer

./marvin "t_ex *eve(void);"
Declaration of a function eve who take into parameter a variable of type void and return a pointer on t_ex
```

### Known Bugs

 * Gramaticals mistakes
 * In some cases pointer on functions parsing doesn't work
 * Some errors are not catched

### Team

The team was made of:
 * [melis_m](https://github.com/melis-m)
 * [planch_j](http://github.com/plean)
