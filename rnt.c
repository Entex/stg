/*
 *
 *********************
 *
 * Authors: Robin Jakobsson <Rjak@kth.se>
 *
 *********************
 *
 * Copyright (c) 2015  Robin Jakobsson
 * All Rights Reserved.
 *
 *********************
 *
 * Version: 1.2
 *
 *********************
 *
 * Description: RNT or Random Node Tree is a program
 *              that generates a spanning tree with
 *              random lengths between nodes
 *              used for calculating a spanning tree
 *
 *********************
 *
 * Arguments:
 *              -s number (seed)
 *              -n number (nodes)
 *              -l number (maximum length between nodes)
 *              -o number (odds for paths to exist between nodes).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int checkParam(const char*);
void generateTree(int,int,int);

int main(int argc, char const *argv[])
{
	srand(time(0)); 	//seed
	int n = 4;			//nodes
	int l = 10;			//maximum length between nodes
	int o = 20;         //odds of being a path between nodes
	int i = 1, av = 0;

	//Check for help
	if(argc >= 2 && strcmp(argv[1],"-h") == 0){
		printf("rnt [-s] [-n] [-l] [-o]\r\nGenerates a spanning tree with random values\r\n\r\nOptions:\r\n -s number\t Set the seed for the random generator(default goes after time)\r\n -n number\t Set the number of nodes(default 4)\r\n -l number\t Set the maximum length between nodes(default 10)\r\n -o [1-100]\t Set the odds for paths to exist between nodes(default 20)\r\n");
		return 0;
	}

	//Init with arguments
	while (i+1 < argc)
	{
		av = checkParam(argv[i]);
		if (av == -1){
			printf("%s is an invalid command\n", argv[i]);
			return -1;
		} else if (argv[i+1] == NULL){
			printf("%s needs to be followed by an integer\n", argv[i]);
		}

		if (av == 1){
			srand(atoi(argv[i+1]));
		} else if (av == 2){
			n = atoi(argv[i+1]);
		} else if (av == 3){
			l = atoi(argv[i+1]);
		} else if (av == 4){
			o = atoi(argv[i+1]);
		}
		i = i + 2;
	}

	generateTree(n,l,o);
	return 0;
}

void generateTree(int n, int l, int o){
	int** tree;
	int i,j;
	int hasPath = 0;

	tree = calloc(n, sizeof(int*));
	for(i = 0;i<n;i++) {
		tree[i] = calloc(n, sizeof(int));
	}

	//clears the middle section(a node can't go to itself)
	for (i = 0; i < n; i++){
		tree[i][i] = 0;
	}

	//start filling the tree with random numbers
	for (i = 0; i < n - 1; i++){
		hasPath = 0;
		for (j = i + 1; j < n; j++){
			if(rand()%100 + 1 < o){  //check the odds if there is to be a path here
				tree[i][j] = rand() % l + 1;
				hasPath = 1;
			} else {
				tree[i][j] = 0;
			}
		}

		//check if tree has hanging nodes, if it does, add a random path
		if(hasPath == 0){
			tree[i][rand()%(n-(i+1)) + (i+1)] = rand() % l + 1;
		}
	}

	//mirror the tree
	for (i = 0; i < n; i++){
		for (j = 0; j < i; j++){
			tree[i][j] = tree[j][i];
		}
	}

	//print tree
	printf("tree = [");
	for (i = 0; i < n; i++){
		printf("[");
		for (j = 0; j < n; j++){
			printf("%d", tree[i][j]);
			if (j+1 < n){
				printf(" ");
			}
		}
		printf("]");
		if (i+1 < n){
			printf(";");
		}
	}
	printf("];\n");

	//free matrix
	free(*tree);
	free(tree);
}

int checkParam(const char *param){
	if(strcmp(param,"-s") == 0){
		return 1;
	} else if (strcmp(param,"-n") == 0){
		return 2;
	} else if (strcmp(param,"-l") == 0){
		return 3;
	} else if (strcmp(param,"-o") == 0){
		return 4;
	} else {
		return -1;
	}
}
