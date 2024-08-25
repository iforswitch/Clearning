#include <stdio.h>

//Function prototypes - lets compiler know in advance of functions that are defined later
void modifyValue(int);
//Note that printf has its own protoype, declared within the included header stdio.h!

int main() {
	int i = 10;
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
	printf("Location of u is %p\n", (void*) & u);
};

//Functions create a copy of the argument passed to it in its local scope, meaning that any modification to that
//copy does not affect the original - pass-by-value
void modifyValue(int num)
{
	num = 10; // This changes the copy of 'num', not the original argument
};