// Q1
void layout(void) {
	int a = 5;
	int b = 123;

	int *pa = &a;
	int *pb = &b;

	*pa = 6;
	*pb = 234;

	int c = *pa;
	*pa = *pb;
	*pb = c;

	pa = pb;
	*pa = 345;
}

/** Q2 */

void swap(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void brokenSwap(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void fixedSwap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void) {
	int a = 5;
	int b = 6;
	brokenSwap(a, b);
}
