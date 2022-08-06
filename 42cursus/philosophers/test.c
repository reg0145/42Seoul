int main(void)
{
	func_t f, *pf;
	struct hack
	func_t f;
	} *phack;

	f = printf;
	printf("%-10s has address: %p\n", "printf", (void*)printf);
	f("%-10s has address: %p\n", "f", (void*)f);

	/* Non portable conv between void* and function pointer */
	pf = malloc(sizeof *pf);
	if (pf == NULL)
	exit(EXIT_FAILURE);

	*pf = printf;
	(*pf)("%-10s has address: %p\n", "*pf", (void*)(*pf));
	/* Try to hack a malloc function pointer */
	phack = malloc (sizeof *phack);
	if (phack == NULL)
	exit(EXIT_FAILURE);

	phack->f = printf;
	phack->f("%-10s has address: %p\n", "phack->f", (void*)(phack->f));
	free((void*)pf);
	free(phack);

	return 0;
}