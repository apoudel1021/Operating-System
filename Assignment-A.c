
#include <stdio.h>
#include <stdlib.h>

void main(int argch, char * argh[]){
if (argch<3)
	{
		printf("Please run as %s [filename]\n", argh[0]);
		return;
	}
    FILE *fi;
    FILE *wi;
    
    //     lfileIn = fopen("input.txt", "r");
    // lfileOut = fopen("output.txt", "wi");
    
    
    if (!(fi = fopen(argh[1], "r")))
	{
		printf("File %s does not exist\n", argh[1]);

		return;
	}

	printf("file content in %s:\n", argh[1]);
    wi = fopen(argh[2],"wi");
    int digit;
	while (fscanf(fi, "%d ", &digit )!=EOF)
	{
		
		printf("%d ", digit);
        fprintf(wi,"%d ",digit);

	}


    fclose(fi);
    fclose(wi);

    
}
