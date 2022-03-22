#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	FILE *S1, *S2;
	int N = 0, conn = 0, f;
	char c[1023], v[20] = "";

	for (int i = 0; i < 1024; i ++) {
		c[i] = '/0';
	}
	S1 = fopen(argv[1], "r");
	fgets(c, 1024, S1);
	for (int i = 0; i < 1024; i ++) {
		if (c[i] == ' ')
			N++;
	}
	fclose(S1);
	S1 = fopen(argv[1], "r");
	S2 = fopen(argv[2], "w");
	fprintf(S2, "graph G {\n");

	for (int i = 0; i < N; i++) {
		f = 0;
		for (int j = 0; j < N; j++) {
			fscanf(S1, "%s ", &c);
			if (c[0] != '0')
				f = 1;
			if (c[0] != '0' && j >= i) {
				fprintf(S2, "\t%c -- %c [label = %s];\n", 'A' + i, 'A' + j, c);
				if (i != j)
					conn++;
			}
		}
		if (!f){
			fprintf(S2, "\t%c;\n", 'A' + i);
			conn = - (N - 1) * N;
			}	
	}
	fprintf(S2, "}");
	fclose(S1);
	fclose(S2);
	if(conn > (N-1)*(N-2)/2) {
		sprintf(v, "_связный");
		printf("Граф связный\n");
	}
	else {
		printf("По теореме невозможно однозначно определить связность\n");
		if (conn < N - 1)
			printf("Однако он, очевидно, несвязный\n");
	}
	sprintf(c, "dot %s -Tpng -o %s%s.png", argv[2], argv[3], v);
	int status = system(c);
	sprintf(c, "xdg-open %s%s.png", argv[3], v);
	status = system(c);
	return 0;
}
