//
// Created by james on 2019-11-09.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct note {
	long int flag;//是否存在笔记
	long int length;//笔记内容的长度
	char *content;//笔记内容
} note;
typedef struct notes {
	long int max;
	long int length;
	note notes256[256];
} notes;

notes *base;

void allocate_space() {
	base = (notes *) malloc(sizeof(notes));
	for (int i = 0; i < 256; i++) {
		base->notes256[i].flag = 0;
		base->notes256[i].length = 0;
		base->notes256[i].content = NULL;
	}
}

int read_choice() {
	int choice;
	puts("== 0ops Free Note ==");
	puts("1. List Note");
	puts("2. New Note");
	puts("3. Edit Note");
	puts("4. Delete Note");
	puts("5. Exit");
	puts("====================");
	printf("Your choice: ");
	scanf("%d", &choice);
	return choice;
}

void list() {
	for (int i = 0;; i++) {
		if (i >= 256) {
			break;
		}
		if (base->notes256[i].flag == 1) {
			printf("%d. %s\n", i, base->notes256[i].content);
		}
	}
}

void read_content(char *temp, int str_len) {
	int i;
	int read_num;
	for (i = 0; i < str_len; i += read_num) {
		read_num = read(0, (void *) (temp + i), str_len - i);
		if (read_num <= 0) {
			break;
		}
	}
}

void new_note() {
	int str_len;//字符串长度
	char *temp;
	void *str;
	if (base->length < base->max) {
		for (int i = 0;; i++) {
			if (i >= base->max) {
				break;
			}
			if (!base->notes256[i].flag) {
				printf("Length of new note: ");
				scanf("%d", &str_len);
				if (str_len > 0) {
					if (str_len > 4096) {
						str_len = 4096;
					}
					printf("Enter your note: ");
					temp = (char *) malloc((128 - str_len % 128) % 128 + str_len);
					read_content(temp, str_len);
					base->notes256[i].flag = 1;
					base->notes256[i].length = str_len;
					base->notes256[i].content = temp;
					base->length++;
					puts("Done.");
					break;
				}
			}

		}
	}
}

void edit_note() {
	printf("Note number: ");
	int num;
	scanf("%d",&num);
	int length;
	scanf("%d",&length);
	if(length!=base->notes256[num].length){
		base->notes256[num].content=(char*)realloc(base->notes256[num].content,(128 - length % 128) % 128 + length);
		base->notes256[num].length=length;
	}
	printf("Enter your note: ");
	read_content(base->notes256[num].content,length);
	puts("Done.");
}

void delete_note() {
	int index;
	printf("Note number: ");
	scanf("%d", &index);
	base->length--;
	base->notes256[index].flag = 0;
	base->notes256[index].length = 0;

/*------------------------------------------------------------------*/
/*-------------------------- bug is here ---------------------------*/

	free(base->notes256[index].content);

/*-------------------------------------------------------------------*/
/*-------------------------------------------------------------------*/

	puts("Done.");
}

int main() {
	allocate_space();
	base->max = 256;
	while (1) {
		switch (read_choice()) {
			case 1:
				list();
				break;
			case 2:
				new_note();
				break;
			case 3:
				edit_note();
				break;
			case 4:
				delete_note();
				break;
			case 5:
				puts("Bye");
				return 0;
			default:
				puts("Invalid!");
				break;
		}
	}
}