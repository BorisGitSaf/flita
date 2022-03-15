#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
        FILE *S1, *S2;
        int N = 0;
        char c[1024];

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
                for (int j = 0; j < N; j++) {
                        fscanf(S1, "%s ", &c);
                        if (c[0] != '0' && j >= i)
                                fprintf(S2, "\t%c -- %c [label = %s];\n", 'A' + i, 'A' + j, c);
                }
        }
        fprintf(S2, "}");
        fclose(S1);
        fclose(S2);
        sprintf(c, "dot %s -Tpng -o image.png", argv[2]);
        int status = system(c);
        return 0;
}
