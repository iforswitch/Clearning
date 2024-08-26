#include <stdio.h>

//Function prototypes - lets compiler know in advance of functions that are defined later
void modifyValue(int);
//Note that printf has its own protoype, declared within the included header stdio.h!

int main() {
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


};

//Functions create a copy of the argument passed to it in its local scope, meaning that any modification to that
//copy does not affect the original - pass-by-value
void modifyValue(int num)
{
	num = 10; // This changes the copy of 'num', not the original argument
};