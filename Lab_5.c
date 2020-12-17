#include <stdio.h>
#include <stdlib.h>
/*
Ввести строку. Вывести её, заменив сокращения на полные слова (т.к. - "так как", т.е. - "то есть", т.д. - "так далее", т.п. - "тому подобное"). Можно использовать английские аналоги.
*/
int strcomp (char *string, char *word) {/*Функция принимает строку и слово, а возвращает индекс первой буквы этого слоова в данной строке*/
	int i = 0, j = 0, cmp = 0, len = 0, res = -1;
	while (word[i] != '\0') {
		len++;
		i++;
	}
	i = 0;
	while (string[i] != '\0') {
		if (string[i] == word[j]) {
			cmp++;
			j++;
		} else {
			cmp = 0;
		}
		
		if (cmp == len) {
			res = i - len + 1;
			break;
		}
		i++;
		if (j == len) {
			j = 0;
			cmp = 0;
		}
	}
	return res;
}

int main () {
	int a = 0, length = 0, i = 0, volume = 50;
	char *string = malloc (volume * sizeof(char));
	while ((a = getchar()) != '\n') {
		if (length == volume) {
			volume *= 2;
			string = realloc(string, volume * sizeof(char));
		}
		string[length] = a;
		length++;
	}
	string[length] = '\0';
	printf("%d\n", length);
	printf("New string:\n");
	/*printf("%d", strcomp(string, "e.g."));*/
	while (string[i] != '\0') {
		if ((string[i] == 'e') && (string[i + 1] == '.') && (string[i + 2] == 'g') && (string[i + 3] == '.')) {
			printf("exempli gratia");
			i += 3;
		} else {
			printf("%c", string[i]);
		}
		i++;
	}
	printf("%c\n", '\0');
	free(string);
    return 0;
}
