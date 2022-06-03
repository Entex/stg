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
 * Description: STG or Spanning Tree generator is a program
 *              that generates a spanning tree with
 *              random lengths between nodes
 *              used for calculating a spanning tree
 *
 *********************
 *
 * Arguments:
 *              -n number (nodes)
 *              -l number (maximum length between nodes)
 *              -o number (odds for paths to exist between nodes).
 *              -p (pretty format)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <argp.h>
#include <stdbool.h>

const char *argp_program_version = "Spanning Tree Generator 1.2";
const char *argp_program_bug_address = "rjak@kth.se"; //discontinued
static char doc[] = "STG or Spanning Tree Generator is a program that generates a spanning tree with random lengths between nodes used for calculating a spanning tree";
static struct argp_option options[] = { 
    { "nodes", 'n', "integer", 0, "Number of nodes"},
    { "length", 'l', "integer", 0, "Maximum length between nodes"},
    { "odds", 'o', "integer", 0, "Odds of path between nodes (0-100)"},
    { "pretty", 'p', 0, 0, "print pretty format"},
    { 0 } 
};

struct arguments{
    int nodes;
    int length;
    int odds;
    bool pretty;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input;
    switch (key) {
        case 'n': arguments->nodes = atoi(arg); break;
        case 'l': arguments->length = atoi(arg); break;
        case 'o': arguments->odds = atoi(arg); break;
        case 'p': arguments->pretty = true; break;
        case ARGP_KEY_ARG: return 0;
        default: return ARGP_ERR_UNKNOWN;
    }   
    return 0;
}

static struct argp argp = { options, parse_opt, doc };

void generateTree(int,int,int,bool);

int main(int argc, char *argv[])
{
    srand(time(0));
	
    struct arguments args;
    args.nodes = 4;
    args.length = 10;
    args.odds = 20;
    args.pretty = false;

    argp_parse(&argp, argc, argv, 0, 0, &args);

	generateTree(args.nodes, args.length, args.odds, args.pretty);
	return 0;
}

void generateTree(int nodes, int length, int odds, bool pretty){
	int** tree;
	int i,j;
	int hasPath = 0;

	tree = calloc(nodes, sizeof(int*));
	for(i = 0; i < nodes; i++) {
		tree[i] = calloc(nodes, sizeof(int));
	}

	//clears the middle section(a node can't go to itself)
	for (i = 0; i < nodes; i++){
		tree[i][i] = 0;
	}

	//start filling the tree with random numbers
	for (i = 0; i < nodes - 1; i++){
		hasPath = 0;
		for (j = i + 1; j < nodes; j++){
			if(rand()%100 + 1 < odds){  //check the odds if there is to be a path here
				tree[i][j] = rand() % length + 1;
				hasPath = 1;
			} else {
				tree[i][j] = 0;
			}
		}

		//check if tree has hanging nodes, if it does, add a random path
		if(hasPath == 0){
			tree[i][rand()%(nodes-(i+1)) + (i+1)] = rand() % length + 1;
		}
	}

	//mirror the tree
	for (i = 0; i < nodes; i++){
		for (j = 0; j < i; j++){
			tree[i][j] = tree[j][i];
		}
	}

    char length_str[20];
    sprintf(length_str, "%d", length); 
    int size_separator = strlen(length_str);


    if (pretty){
        for (i = 0; i < nodes; i++){
            for (j = 0; j < nodes; j++){
                printf("%*d ", size_separator, tree[i][j]);
            }
            printf("\n");
        }
    } else {
        //print tree
        printf("[");
        for (i = 0; i < nodes; i++){
            printf("[");
            for (j = 0; j < nodes; j++){
                printf("%d", tree[i][j]);
                if (j+1 < nodes){
                    printf(", ");
                }
            }
            printf("]");
            if (i+1 < nodes){
                printf(", ");
            }
        }
        printf("]\n");
    }

	//free matrix
	free(*tree);
	free(tree);
}

