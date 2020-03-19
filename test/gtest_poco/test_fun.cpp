//
// Created by james on 2019-02-10.
//

#include <gtest/gtest.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
TEST(fun, scan)
{
	struct dirent **namelist;
	int n;

	n = scandir(".", &namelist, NULL, alphasort);
	if (n < 0)
		perror("scandir");
	else {
		while (n--) {
			printf("%s\n", namelist[n]->d_name);
			free(namelist[n]);
		}
		free(namelist);
	}
}