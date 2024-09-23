#include <stdio.h>

//Function prototypes - lets compiler know in advance of functions that are defined later
void modifyValue(int);
//Note that printf has its own protoype, declared within the included header stdio.h!

struct car {
	char* name;
	float price;
	int speed;
};


int main(void) {
	/*int i = 10;
	float f = 5.0;
	char* s = "Hello world!\n"; //char * is the string type 
	printf("%i is more than %f.  Also, %s", i, f, s);

	int x = 0;
	int y = 1;
	int w = -2;
	if (!x) {
		printf("x is false\n");
	}
	if (y && w) {
		printf("y is true and so is w!\n");
	}

	//ternary is not a control flow like a if statement.  It evaluates a value for a condition but it cannot use
	//control flows like end, continue, goto, etc.
	y += i > 4 ? 17 : 34;
	printf("%i\n", y);


	//Post/pre-increments
	int j = 0;

	i = 10;
	j = 5 + i++;  // Compute 5 + i, _then_ increment i

	printf("%d, %d\n", i, j);  // Prints 11, 15

	i = 10;
	j = 5 + ++i;  // Increment i, _then_ compute 5 + i

	printf("%d, %d\n", i, j);  // Prints 11, 16

	//Comma operator
	x = (1, 2, 3);

	printf("x is %d\n", x);  // Prints 3, because 3 is rightmost in the comma listh


	//sizeof
	int a = 999;

	// %zu is the format specifier for type size_t

	printf("%zu\n", sizeof a);      // Prints 4 on my system
	printf("%zu\n", sizeof(2 + 7)); // Prints 4 on my system
	printf("%zu\n", sizeof 3.14);   // Prints 8 on my system
	// If you need to print out negative size_t values, use %zd

	//Same size for a and 2 + 7 because they are the same type of expressions - int.  Char is always 1 on all systems.

	//Do-while
	i = 10;

	//Do-while will execute atleast ones because any condition can be false and also because the condition is only assesed
	// after the body of the loop is run.
	// this is executed once, because the loop condition is not checked until
	// after the body of the loop runs:

	do {
		printf("do-while: i is %d\n", i);
		i++;
	} while (i < 10);

	printf("All done!\n");

	//Use switches with integer types instead of float or strings, note that characters are secretly integer types.
	//Switch fall-throughs
	switch (x) {
	case 1:
		printf("1\n");
		// Fall through!
	case 2:
		printf("2\n");
		break;
	case 3:
		printf("3\n");
		break;
	};

	a = 5;
	modifyValue(a);
	printf("Value of a: %d\n", a); // 'a' is still 5, not 10



	//Pointers!
	//Pointer is a variable that holds an address.  Like in arrays, or the indexing of elements, - that is what an address is.
	//It tells us where to find a variable is that is holding some value in memory, instead of knowing what the variable
	//itself is.

	int u = 10;
	printf("Value of u is %i\n", u);
	printf("Size of u is %zu\n", sizeof(u));
	printf("Location of u is %p\n", (void*)&u);

	int o;  // o's type is "int"
	int* p; // p's type is "pointer to an int", or "int-pointer"
	p = &o; // p assigned to address of o, so it now points to it.

	o = 10;

	//deference operator/indirection operator - access values indirectly using the pointer.
	//Tells the computer to use the object that the pointer is pointing to instead of the pointer itself.
	//*p is kind of like an alias for o.
	*p = 20;

	//Pointer and functions
	//Functions will also create a copy of the pointer argument it is passed, i.e there is now a duplicate of a pointer
	//to the same variable, essentially you now have 2 addressses.
	//Eventhough the function has copied the pointer, because it points to the same object, any changes within the function
	//will now also change the original object the pointer was pointing to, even when it's a copy of the pointer argument!

	//Null pointer
	// p = NULL;
	//*p = 20;
	//results in crash dereferencing NULL is undefined behavior.
	//int pointers are still int and so have the same size as outputted by sizeof.
	*/
	//Arrays 
	float f[4]; //declare an array of 4 floats.  Index start at 0.
	//float (*g)[4] is different to float * g;
	//g = &f;
	f[0] = 3.14f;
	f[1] = 332.34f;
	f[2] = 9.31f;
	f[3] = 0.123f;

	for (int h = 0; h < 4; h++) {
		printf("%f\n", f[h]);
	}

	//Array sizes
	printf("total size of array: %zu, size of each element: %zu, length of array: %zu\n", sizeof(f), sizeof(int), sizeof(f) / sizeof(int));

	//Passing to function doesn't work as it only passes pointer to the first element, which sizeof measures. instead.
	//int a[5] = { 22, 37, 3490 };

	// is the same as:

	//int a[5] = { 22, 37, 3490, 0, 0 };
	//int a[10] = {0, 11, 22, [5]=55, 66, 77};
	//0 11 22 0 0 55 66 77 0 0


	//#define COUNT 5
	//int a[COUNT] = { [COUNT - 3] = 3, 2, 1 };
	//0 0 3 2 1

	//Multidimensional arrays
	//Below is the same 2 code as C only really needs the other dimensions apart from the first (that is not 0).
	//void print_2D_array(int a[2][3])
	//void print_2D_array(int a[][3])

	//strings
	//strings are pointers in c.  Use a \ to escape characters
	//using pointers means it points to the first character in the index;
	char *test = "When asked if this string had quotes in it, she replied, \"It does.\"";
	//Storage of a pointer to a string literal and an array of a string literal is different during initialisation.
	//Don't mutate a pointer pointing to a string literal
	//test[0] = 'z';  // BAD NEWS: tried to mutate a string literal!
	char t[] = "Hello, again!";  // t is an array copy of the string 
	t[0] = 'z'; //  No problem

	//string lengths are calculated in c using a zero-nul character as a terminator.
	char* s = "Hello!";  // Actually "Hello!\0" behind the scenes
	//strcpy() has the destination as a first argument and the source as the second - destination = source.

	//Structs!! a class with data members but no methods
	//done at global scope
	//initialising with order sensitive
	//struct car saturn = { "Saturn SL/2", 16000.99, 175 };
	//initialising with order non sensitive
	struct car saturn = { .speed = 175, .name = "Saturn SL/2" }; //price is initialise to be 0
	//pointers passed in functions to a struct cannot use the dot operator as that is a struct s * type not a struct s
	//an arrow is needed s->price, or (*s).price to dereference.  Preferably use arrow when passing a pointer to struct.

	//FIle I/O. FILE * data type which is streamed into the program.  3 streams is already avaiable by default.
	//stdin	Standard Input, generally the keyboard by default
	//stdout	Standard Output, generally the screen by default
	//stderr	Standard Error, generally the screen by default, as well
	//fgetc() return EOF when reaching the end of a file, as a int instead of char as it can fall out of the range of char,
	//meaning it needs to be able to return with a higher range of values - an int.  Although unless the return value is
	//something your comparing to like EOF, then it will just be a char otherwise.
	//fgets() reads lines which requires a pointer, maximum bytes to read, and a file to read from.
	
	//Binary files, raw stream of bytes with no translation.  "rb", "wb" modes, use fread() & fwrite().
	// In the call to fwrite, the arguments are:
	//
	// * Pointer to data to write
	// * Size of each "piece" of data
	// * Count of each "piece" of data
	// * FILE*
	// unsigned char bytes[6] = {5, 37, 0, 88, 255, 12};
	//fwrite(bytes, sizeof(char), 6, fp);
	//fread() returns the number of bytes read, so it will return 0 on EOF.
	//serialise the the binary data when writing to stream as it allows portability. endianess, different arhictecture, compilers.

	///////////////////////////////////////////////////////////////////////////
	//typedef, creates an alias for a data type.
	//  Anonymous struct! It has no name!
//         |
//         v
//      |----|
	typedef struct {
		char* name;
		int leg_count, speed;
	} animal;                         // <-- new name

	//struct animal y;  // ERROR: this no longer works--no such struct!
	animal z;


	/*
	Declaring struct variable (no definition and no initialisation)
	struct Person{
		int age;
		float height;
		char name[100];
	}

	Declaring struct variable (no initialisation)
	struct Person person1

	Declaring and Initializing a Struct at the Same Time
	struct Person person1 = {29, 188, "Steve"};

	using designated initialisators
	struct Person person4 = {
		.age = 29,
		.height = 188,
		.name = "Steve"
	}; <- Allows for ignoring order of inputs 'person4 = {.height = 188, .name = "Steve", .age =29};

	Using typedef
	typedef struct{
		int age;
		float height;
		char name[100];
	} Person;  <- can only refer by 'Person p1 = ...'

	typedef struct Person{
		int age;
		float height;
		char name[100];
	} Person;  <- can refer by 'Person p1 = ...'  OR 'struct Person p1 = ...'

	Declaring an array of structs
	struct Person p[2] = { {29, 188, "Steve"}, {30, 178, "Charlie"} };

	Using pointers
	using an existing variable
	struct Person p1;
	struct Person * p = &p1;

	using dynamic allocation
	struct Person * p = malloc(sizeof(struct Person));

	accessing with a pointer
	(*p).age = 30; or p->age = 30;

	*/
	/////////////////////////


	//Array pointer equivalence
	//a[b] == *(a + b), adding/subtracting for a pointer moves its index accordingly.
	/*
	int a[] = {11, 22, 33, 44, 55};

    int *p = a;  // p points to the first element of a, 11
	int *p = &a[0] // equivalent to above
	p++ //Moves to the next index
	(*p)++ // Adds 1 to the dereference - 11 +1 = 12;

	int (*p)[5] = &a // COMPLETELY DIFFERENT, pointing to an array of exactly 5 ints
	p++ //Therefore moves to the next INDEX OF EXACTLY 5 ints
	((*p)[0))++ //would add 1 to 11, as its dereferencing t the first ELEMENT OF EXACTLY 5 INTS, and then accessing the first index and then adding one to it

	Using the name of the array converts it to a pointer - passing the name of the array into a function also decays it to a pointer.


    // Print all elements of the array a variety of ways:

    for (int i = 0; i < 5; i++)
        printf("%d\n", a[i]);      // Array notation with a

    for (int i = 0; i < 5; i++)
        printf("%d\n", p[i]);      // Array notation with p

    for (int i = 0; i < 5; i++)
        printf("%d\n", *(a + i));  // Pointer notation with a

    for (int i = 0; i < 5; i++)
        printf("%d\n", *(p + i));  // Pointer notation with p

    for (int i = 0; i < 5; i++)
        printf("%d\n", *(p++));    // Moving pointer p
        //printf("%d\n", *(a++));    // Moving array variable a--ERROR!
	*/

	//memcpy
	void* memcpy(void* s1, void* s2, size_t n); //copies s2 into s1
	//void * pointers needed otherwise specialised memcpy would be needed for each datatype.
	//void * allows for functions that don't care about datatype.
	//1. You cannot do pointer arithmetic on a void*. 
	//2. You cannot dereference a void*. 
	//3. You cannot use the arrow operator on a void*, since it’s also a dereference. 
	//4. You cannot use array notation on a void*, since it’s also a dereference, as well.
	//Just convert the void * to another pointer before using it
	char a = 'X';  // A single char

	void* p = &a;  // p points to the 'X'
	char* q = p;   // q also points to the 'X'

	//printf("%c\n", *p);  // ERROR--cannot dereference void*!
	printf("%c\n", *q);  // Prints "X"
	//qsort() can sort anything according to the given format - qsort(array, count, size of each, format())
};


//Functions create a copy of the argument passed to it in its local scope, meaning that any modification to that
//copy does not affect the original - pass-by-value
void modifyValue(int num)
{
	num = 10; // This changes the copy of 'num', not the original argument
};