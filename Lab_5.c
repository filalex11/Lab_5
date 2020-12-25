#include <stdio.h>
#include <stdlib.h>
/*
Ввести строку. Вывести её, заменив сокращения на полные слова (т.к. - "так как", т.е. - "то есть", т.д. - "так далее", т.п. - "тому подобное"). Можно использовать английские аналоги.
*/
int strcomp (char *word, int len, char *reduct) {
	int i = 0, j = 0, cmp = 0, res = 0;
	while (word[i] != '\0') {
		if (word[i] == reduct[j]) {
			cmp++;
			j++;
		} else {
			break;
		}
		if (cmp == len) {
			res++;
		}
		i++;
	}
	return res;
}

char* change (char *word) {
	if (strcomp(word, 4, "e.g.") == 1) {
		word = "exempli gratia";
	}
	if (strcomp(word, 3, "etc") == 1) {
		word = "et cetera";
	}
	if (strcomp(word, 3, "pls") == 1) {
		word = "please";
	}
	return word;
}

int is_letter (char str) {
	if (((str >= 'A') && (str <= 'Z')) || ((str >= 'a') && (str <= 'z')) || (str == '.')) {
		return 1;
	} else {
		return 0;
	}
}

int word_count (char *string) {
	int i = 0, in_word = 0, count = 0;
	while (string[i] != 0) {
		if (is_letter(string[i]) == 1) {
			in_word = 1;
		} else {
			if (in_word == 1) {
				count++;
				in_word = 0;
			}
		}
		i++;
	}
	if (in_word == 1) {
		count++;
	}
	return count;
}

int main () {
	int a = 0, length = 0, i = 0, volume = 100, k = 0, j = 0;
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
	printf("New string:\n");
	int count = word_count(string);
	i = 0;
	char **words = (char**)malloc(count * sizeof(char*));
	for (i = 0; i < count; i++) {
		words[i] = (char*)malloc(length * sizeof(char));
	}
	i = 0;
	int symbols = 0;
	while (string[k] != 0) {
		if (is_letter(string[k]) == 1) {
			words[i][j] = string[k];
			j++;
			symbols = 0;
		} else {
			symbols++;
			if (symbols == 1) {
				i++;
				j = 0;
			}
		}
		k++;
	}
	i = 0;
	while (i != count) {
		printf("%s ", change(words[i]));
		free(words[i]);
		i++;
	}
	printf("%c\n", '\0');
	free(words);
	return 0;
}
