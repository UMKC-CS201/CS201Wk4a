#include "examples.h"


void example1() {
	//demonstrate pointer assignment and usage
	int a = 10;
	int b = 20;
	int* a1, * b1;
	a1 = &a;
	b1 = &b;
	*a1 = b;
	*b1 = 30;
	cout << "*a1 = " << *a1 << " and *b1= " << *b1 << endl;   //value of the location at a1 & b1 (value of a & b)
	cout << "&a =  " << &a  << " and &b=  " << &b << endl;    //address of a & b
	cout << "a1 =  " << a1  << " and b1=  " << b1 << endl;    //address in a1 & b1 (same as address of a & b)
	cout << "&a1 = " << &a1 << " and &b1= " << &b1 << endl;   //address a1 & b1 
	cout << endl << endl;
}

void example2() {
	//demonstrate pointer assignment and usage
	{
		int* p1, * p2, v1, v2;
		p1 = &v1; //int *p1=&v1;
		*p1 = 10;

		p2 = &v2;
		*p2 = 20;

		*p1 = *p2;
		cout << "p1 = " << *p1 << " and p2 = " << *p2 << endl;
		cout << "v1 = " << v1 << " and v2 = " << v2 << endl;
		*p2 = 30;
		cout << "p1 = " << *p1 << " and p2 = " << *p2 << endl;
		cout << "v1 = " << v1 << " and v2 = " << v2 << endl << endl << endl;
	}
}

void example3() {
	//demonstrates dynamic variables, pointer assignment and usage
	int* p1 = nullptr, *p2 = nullptr;
	p1 = new int;
	p2 = new int;

	*p1 = 10;
	*p2 = 20;
	cout << "p1 = " << *p1 << " p2 = " << *p2 << endl;
	delete p1;
	p1 = p2;
	cout << "*p1 = " << *p1 << " *p2 = " << *p2 << endl;

	*p1 = 30;
	cout << "*p1 = " << *p1 << " *p2 = " << *p2 << endl << endl;
	delete p1, p2;
	p1 = nullptr;
	p2 = nullptr;
}

void test1(int* v) {
	//  v is at a new address (but it contains the address of x)
	*v = *v + 1;
	cout << setw(20) << "Test 1 &v: " << &v << "\t  v : " << v << "\t *v: " << *v << endl;
	//delete v;
}

void example4() {
	// demonstrates functions using pointers (by value) 
	// the value of ‘x’ changes because the function is pointing to the same location in memory

	int* x = nullptr;
	x = new int(80);

	cout << setw(20) << "Before Test1 & x: " << &x << "\t  x : " << x << "\t *x: " << *x << endl;
	test1(x);
	cout << setw(20) << "After Test1 & x: " << &x << "\t  x : " << x << "\t *x: " << *x << endl << endl;
}

void test2(int* v) {
    // the value of ‘x’ does NOT change because v contains a new location in memory (that is set to the value of x)
	v = new int(*v + 100);
	*v = *v + 5;
	cout << setw(20) << "Test 2 &v: " << &v << "\t  v: " << v << "\t *v: " << *v << endl;
}

void example5(){
	// demonstrates functions using pointers (by value)
	
	int* x = nullptr;

	x = new int(80);

	cout << setw(20) << "Before Test 2 &x: " << &x << "\t  x: " << x << "\t *x: " << *x << endl;
	test2(x);
	cout << setw(20) << "After Test 2 &x: " << &x << "\t  x: " << x << "\t *x: " << *x << endl;
	test2(x);
	cout << setw(20) << "After Test 2 &x: " << &x << "\t  x: " << x << "\t *x: " << *x << endl << endl;
}

void test3(int* &v) {
	// the value of ‘x’ changes because v contains a same location in memory
	// pass by reference -> v is updating the value of 'x'
	v = new int(*v + 100);
	*v = *v + 15;
	cout << setw(20) << "Test 3 &v: " << &v << "\t  v: " << v << "\t *v: " << *v << endl;
}

void example6(){
	// demonstrates functions using pointers (by reference)

	int* x = nullptr;

	x = new int(80);

	cout << setw(20) << "Before Test 3 &x: " << &x << "\t  x: " << x << "\t *x: " << *x << endl;
	test3(x);
	cout << setw(20) << "After Test 3 &x: " << &x << "\t  x: " << x << "\t *x: " << *x << endl;
	test3(x);
	cout << setw(20) << "After Test 3 &x: " << &x << "\t  x: " << x << "\t *x: " << *x << endl << endl;
}


void example7(){
	// demonstrates dynamic arrays
	int* x = nullptr;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* newArr;
	int arrSize;
	x = arr;

	for (int i = 0; i < 10; i++) 
		cout << x[i] << '\t';
	cout << endl << endl;

	cout << "Enter array size: ";
	cin >> arrSize;
	newArr = new int[arrSize];
	for (int i = 0; i < arrSize; i++) {
		newArr[i] = i * 10;
		cout << newArr[i] << '\t';
	}
	delete[] newArr;
	cout << endl << endl;
}