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
Declaration  of the variable of type integer named a

./marvin "int a; int b;"
Declaration  of the variable of type integer named a
Declaration  of the variable of type integer named b

./marvin "int a, b;"
Declaration  of the variable of type integer named a and of the variable of type integer named b
```
Hard tests
```
./marvin "long (*f)(void)(char *str);"
Declaration  of the pointer on function f who take of the variable of type void into parameter and resending a long

./marvin "int a, *b;"
Declaration  of the variable of type integer named a and of the variable of type pointer on integer named b

./marvin "int a, (*b)(int c);"
Declaration  of the variable of type integer named a and of the pointer on function b who take of the variable of type integer named c into parameter and resending a integer
```
functions
```
./marvin "int aff_nbr(int a);"
Declaration  of the function aff_nbr who take into paramter of the variable of type integer named a and resending a integer

./marvin "t_ex *eve(void);"
Declaration  of the function eve who take into paramter of the variable of type void and resending a pointer on t_ex
```

### Known Bugs

 * Gramaticals mistakes
 * In some cases pointer on functions parsing doesn't work
 * Some errors are not catched

### Team

The team was made of:
 * [melis_m](https://github.com/melis-m)
 * [planch_j](http://github.com/plean)
