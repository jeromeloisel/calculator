#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct calc_func {
	int (*compute)();
	char key;
	char *name;
};

int add() {
	int x, res=0;
	char cmd[20];
	printf("Enter numbers to add\n");
	while( fgets(cmd, 20, stdin) && cmd[0] != '\n' ) {
		res += atoi(cmd);
	}
	printf("Result is %d\n", res);
}

int subtract() {
	int x, res=0;
	char cmd[20];
	printf("Enter numbers to subtract\n");
	while( fgets(cmd, 20, stdin) && cmd[0] != '\n' ) {
		res -= atoi(cmd);
	}
	printf("Result is %d\n", res);

}

int multiply() {
	int x, res=1;
	char cmd[20];
	printf("Enter numbers to multiply\n");
	while( fgets(cmd, 20, stdin) && cmd[0] != '\n' ) {
		res *= atoi(cmd);
	}
	printf("Result is %d\n", res);
}

int fact()
{
	int i;
	int res = 1;
	char cmd[20];
	
	printf("Enter number to have its factoriel\n");
	if ( fgets(cmd, 20, stdin) && cmd[0] != '\n' ) {
		if (atoi(cmd) != 1) {
			for (i=1; i < atoi(cmd) + 1; i++) {
			res = res*i;
		}
		}
		printf("Result is %d\n", res);
	}
}

int quit() {
	printf("Good Bye\n");
	exit(0);
}

struct calc_func functions[] = {
	{
		.key = 'q',
		.compute = quit,
		.name = "quit",
	},
	{
		.key = '+',
		.compute = add,
		.name = "addition",
	},
	{
		.key = '-',
		.compute = subtract,
		.name = "subtraction",
	},
	{
		.key = '*',
		.compute = multiply,
		.name = "multiplication",
	},
	{
		.key = 'F',
		.compute = fact,
		.name = "factorial",
	}

};

#define NB_FUNCS (sizeof(functions)/sizeof(struct calc_func))

void print_function(struct calc_func *f) {
}

void print_all_functions() {
	int i;
	for (i = 0 ; i < NB_FUNCS ; i++) {
		printf("Press key %c for %s\n", functions[i].key, functions[i].name);
	}
}

int main(){
	int i;
	char cmd[20];
	printf("Welcome to Calculator 2.1 \n");
	printf("========================= \n\n");
	print_all_functions();
	printf("========================= \n\n");

	while(1) {
		printf("Enter a command\n");
		fgets(cmd, 20, stdin);
		
		for (i = 0 ; i < NB_FUNCS ; i++) {
			if (functions[i].key == cmd[0]) {
				printf("Calling command: %s\n", functions[i].name);
				functions[i].compute();
				break;
			}
		}
	}
}
