
/*
7th Jan, 2022
Problem 3

Roll Number: cs21btech11001
Name: Abhay Shankar K

*/

#include <stdio.h>

int balanced(char expression[]) 
{
	int o_par_count = 0;
    int c_par_count = 0;
    int o_box_count = 0;
    int c_box_count = 0;
	for(int i = 0; expression[i] != '\0'; i++){
		if(expression[i] == '(' && expression[i + 1] == ']') return 0;
		if(expression[i] == '[' && expression[i + 1] == ')') return 0;

		
		if(expression[i] == '(') o_par_count++;
		if(expression[i] == ')'){
			if (o_par_count <= c_par_count) return 0;
			c_par_count++;
		}

		if(expression[i] == '[') o_box_count++;
		if(expression[i] == ']'){
			if (o_box_count <= c_box_count) return 0;
			c_box_count++;
		}
	}

	if((o_par_count != c_par_count) || (o_box_count != c_box_count)) return 0;

	return 1;
}

int main() {
    int n, element, search;
    char expression[50];

	int out;

    while (scanf("%s", expression) != -1) {
		
		printf("%d\n", balanced(expression));
    }
    return 0;
}
