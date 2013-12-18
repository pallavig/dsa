int main(int argc, char const *argv[])
{
	int *a = (int*)malloc(sizeof(int)*2);
	a[0] = 1;
	a[1] = 34;
 	printf("%d\n",a[1] );
 	free(a);
 	free(a);
 	free(a);
 	free(a);
	return 0;
}