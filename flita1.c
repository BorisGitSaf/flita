#include <stdio.h>

int ai[1000], bi[1000];

int insert(int* a);

void out(int* a);

int add(int* a, int d);

int del(int* a, int d);

void help();

int clear(int* a) {
	for (int i = 0; i < 1000; i++) {
		a[i] = 0;
	}
	return 0;
}

int insert(int* a) {
	char c, dc;
	int di, i;
	double dl;
	clear(a);
	while (c != '\n') {
		scanf("%d%c", &di, &c);
		add(a, di);
	}
	return 0;
}



int update() {
	int olen = 0, inp;
	int *a;
	char c, op[3];
	while ((c = getchar()) != '\n') {
		if (c == ' ') {
			scanf("%d", &inp);
			break;
		}
		if (olen >= 0) {
			op[olen] = c;
			olen++;
		}
	}
	if (op[0] == 'e' || op[0] == EOF || op[0] == '\e')
		return 1;
	if (op[0] == '?' || op[0] == 'h') {
		help();
		return 0;
	}
	if (op[0] == 'a' || op[0] == 'A' || op[0] == 'b' || op[0] == 'B') {
		if (op[0] == 'a' || op[0] == 'A')
			a = &ai;
		else
			a = &bi;
		if (olen == 1) {
			out(a);
			return 0;
		}
		else if (olen == 2) {
			switch(op[1]){
				case '+':
					if (add(a, inp))
						printf("Множество уже содержит такой элемент\n");
				return 0;
				case '-':
					if (del(a, inp))
						printf("Множество не содержит такой элемент\n");
					return 0;
				case 'c':
					clear(a);
					return 0;
				case 'i':
					insert(a);
					return 0;
			}
		}
	}
	return 0;
}

void out(int* a) {
	for (int i =0; i < 998; i++) {
		if (a[i] == a[i + 1])
			break;
		printf("%d ", a[i]);
	}
	printf("\n");
}

int add(int* a, int d) {
	for (int i = 0; i < 998; i++) {
		if (i > 0) {
			if (a[i - 1] == d)
				return 1;
		}
		if (a[i] == a[i + 1]) {
			if (d == a[i]) {
				for (int j = i; j < 1000; j++) {
					a[j] = !d;
				}
			}
			a[i] = d;
			return 0;
		}
	}
}

int del(int* a, int d) {
	for (int i = 0; i < 1000; i++) {
		if (a[i] == d && a[i] != a[i + 1]) {
			for (int j = i; j < 999; j++) {
				a[j] = a[j + 1];
			}
		return 0;
		}
		if (a[i] == a[i + 1]){
			return 1;}
	}
	return 1;
}

void help() {

	printf("В вашем распоряжении есть два множества A и B (можно a и b)\n"
		"Изначально оба множества пустые. Элементами могут быть десятичные целые числа\n"
		"Основные функции для множества A (для B аналогичны):\n"
		"A - вывод элементов A\n"
		"Аi - перезапись множества. После этого с новой строки ввести элементы через пробел\n"
		"Ac - очищение множества\n"
		"A+ x - добавление x в А\n"
		"A- x - удаление x из A\n"
		"Для выхода введите e или Esc\n"
		"Для вызова этого сообщения - h или ?\n\n");
}

int main() {
	help();
	while (!update()) {}
	return 0;
}
