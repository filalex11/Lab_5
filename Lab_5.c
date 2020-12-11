#include <stdio.h>
#include <stdlib.h>
/*
Ввести строку. Вывести её, заменив сокращения на полные слова (т.к. - "так как", т.е. - "то есть", т.д. - "так далее", т.п. - "тому подобное"). Можно использовать английские аналоги.
*/
void sdvig (char *string, int length, int index, int shift) {
	int i = 0, j = 0;
	for (j = 0; j < shift; j++) {
		for (i = length - 1; i > index; i--) {
			string[i] = string[i - 1];
		}
		index++;
	}
}

void paste (char *string, char *word, int index) {
	int i = 0;
	while (word[i] != '\0') {
		string[index] = word[i];
		index++;
		i++;
	}
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
	printf("New string:\n");
	while (string[i] != '\0') {
		if ((string[i] == 'e') && (string[i + 1] == '.') && (string[i + 2] == 'g') && (string[i + 3] == '.')) {
			sdvig(string, length, i, 14);
			paste(string, "exempli gratia", i);
			i += 13;
		}
		
		if ((string[i] == 't') && (string[i + 1] == 'y')) {
			sdvig(string, length, i, 9);
			paste(string, "thank you", i);
			i += 8;
		}
		
		if ((string[i] == 'e') && (string[i + 1] == 't') && (string[i + 2] == 'c')) {
			sdvig(string, length, i, 9);
			paste(string, "et cetera", i);
			i += 8;
		}
		
		if ((string[i] == 'v') && (string[i + 1] == 's')) {
			sdvig(string, length, i, 6);
			paste(string, "versus", i);
			i += 5;
		}
		i++;
	}
	for (i = 0; i < length + 14; i++) {
		printf("%c", string[i]);
	}
	printf("%c\n", '\0');
	free(string);
    return 0;
}
