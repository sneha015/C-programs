/*
 * sudoku_validator.c
 *
 *  Created on: Sep 29, 2015
 *      Author: lokisneha
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<errno.h>
#include<stdarg.h>
#include<pthread.h>

#define NUM_THREADS 27
#define LENGTH 9
#define ONE_THIRD_LENGTH 3
#define FALSE 0
#define TRUE 1
#define MIN_ARGC 2
#define FILE_PATH_ARG 1
#define TEST_TYPE 0
#define START_VAL 1

/* Data Structure to contain the Puzzle Board */
static int *puz[LENGTH];

/* Declare a variable for the last region which was tested */
static int lastRegion = 0;

static int duplicate = FALSE;
pthread_mutex_t lock;

/* segment_t is used to differentiate between row, column, and region. */
typedef enum {
	ROW,
	COLUMN,
	REGION
} segment_t;

/* Function used to test on each Thread */
void *runner(void *param); /* the thread */

void read_file_and_set_puz(const char *path) {
	int i;

	/* Hold a pointer to the input file */
	FILE *f;

	/* Try to open the file to read */
	if ((f = fopen(path, "r")))
	{
		/* read 9 lines of input */
		for (i = 0; i < LENGTH; i++) {
			/* Parse normal sudoku layout */
			int *ptr = puz[i];
			fscanf(f, "%d %d %d %d %d %d %d %d %d", ptr, ptr+1, ptr+2, ptr+3, ptr+4, ptr+5, ptr+6, ptr+7, ptr+8);
		}
		printf("File Parsed.\n");

		/* Close the file */
		fclose(f);
	}
	else
	{
		/* otherwise, print an error message */
		printf("Oops! There is no file with that path.\nPlease try a path relative to the executable or an absolute path.\n");
	}
}

int main(int argc, const char *argv[]) {

	/* Array of threads */
	pthread_t workers[NUM_THREADS];

	/* Integer used for iterating over threads */
	int i;

	/* if there aren't enough arguments for there to be an input file,
	 * display an error message and return with error */
	if (argc < MIN_ARGC) {
		printf("An input file must be provided.\n\nSyntax:   sudoku [FILE]\n");
		// return with error status code
		return 1;
	}

	/* Allocate memory for the columns in each row */
	for (i = 0; i < LENGTH; i++)
		puz[i] = (int *)malloc(sizeof(int) * LENGTH);

	/* read in the file and store the input */
	read_file_and_set_puz(argv[FILE_PATH_ARG]);

	pthread_mutex_init(&lock, NULL);

	/* Creating NUM_THREADS Threads
     *
     *  Use: pthread_create(...)
     *  more info: man pthread_create
     */
    for (i = 0; i < NUM_THREADS; i++)
	{
		/* declare arguments to pass to the function that the thread executes */
		int thread_args[2];
		int start;
		segment_t seg;

		/* If it is one of the first 9 threads, assign it to work on testing rows */
		if (i < 9) {
			/* set the test type and start value to 0 since it will be incrementing across */
			seg = ROW;
			start = i;
		}
		/* Assign the next 9 threadsto work on testing columns */
		else if (i < 18) {
			seg = COLUMN;
			start = 0;
		}
		else {
			seg = REGION;
			/* start at the last region */
			start = lastRegion;
			lastRegion++;
		}

		/* set the variables in an array to be passed in pthread_create */
		thread_args[TEST_TYPE] = seg;
		thread_args[START_VAL] = start;

		/* create the new thread */
        pthread_create(&workers[i], NULL, runner, (void *)thread_args);
	}

    /* Join each thread
     *
     * Use: pthread_join
     */
    for (i = 0; i < NUM_THREADS; i++)
         pthread_join(workers[i], NULL);

	pthread_mutex_destroy(&lock);

	if (duplicate == TRUE)
	{
		printf("Invalid Solution. A duplicate was found.\n");
	}
	else
	{
		printf("The solution appears to be valid =)\n");
	}

 	/* Free memory for the columns in each row */
 	for (i = 0; i < LENGTH; i++)
 		free(puz[i]);

	// return with success status
	return 0;
}

/* Scans each item in a Designated area. Expects a void pointer with the row,
 * column or segment to test. Sets the pthread_value pointer to be 0 (FALSE)
 * if no duplicates are found.  Otherwise, it sets it to 1 (TRUE). */
void *runner(void *param) {
	/* declare the variables needed to test the puzzle */
    int *thread_params = (int *)param;
	segment_t type = thread_params[TEST_TYPE];
	int initial = thread_params[START_VAL];
	int i, j, val1, val2;
	if (type == ROW) {

		for (i = 0; i < LENGTH; i++) {
			val1 = puz[initial][i];
			for (j = 0; j < LENGTH; j++) {
				val2 = puz[initial][j];
				printf("(%d, %d) -> ", val1, val2);
				if (val1 == val2) {
					/* if they do, set dupl to TRUE and break out of both loops */
					if (!(i == j))
					{
						printf("!(%d, %d) at (%d, %d) \n", val1, val2, i, j);fflush(stdout);
						pthread_mutex_lock(&lock);
						duplicate = TRUE;
						pthread_mutex_unlock(&lock);
						break; break;
					}
				}

			}
		}
	}
	else if (type == COLUMN) {

		for (i = 0; i < LENGTH; i++) {
			val1 = puz[i][initial];
			for (j = 0; j < LENGTH; j++) {
				val2 = puz[j][initial];

				if (val1 == val2) {
					/* if they do, set dupl to TRUE and break out of both loops */
					if (!(i == j))
					{
						printf("!(%d, %d) at (%d, %d) \n", val1, val2, i, j);fflush(stdout);
						pthread_mutex_lock(&lock);
						duplicate = TRUE;
						pthread_mutex_unlock(&lock);
						break; break;
					}
				}

			}
		}
	}
	else /* assume REGION */ {
		int k;
		for (k = 0; k < ONE_THIRD_LENGTH; k++)
		{
			for (i = 0; i < ONE_THIRD_LENGTH; i++) {
				val1 = puz[initial][i];
				for (j = 0; j < ONE_THIRD_LENGTH; j++) {
					val2 = puz[initial][j];

					if (val1 == val2) {
						/* if they do, set dupl to TRUE and break out of both loops */
						if (!(i == j))
						{
							printf("!(%d, %d) at (%d, %d) \n", val1, val2, i, j);fflush(stdout);
							pthread_mutex_lock(&lock);
							duplicate = TRUE;
							pthread_mutex_unlock(&lock);
							break; break;
						}
					}

				}

				for (i = 0; i < ONE_THIRD_LENGTH; i++) {
					val1 = puz[i][initial];
					for (j = 0; j < ONE_THIRD_LENGTH; j++) {
						val2 = puz[j][initial];

						if (val1 == val2) {
							/* if they do, set dupl to TRUE and break out of both loops */
							if (!(i == j))
							{
								printf("!(%d, %d) at (%d, %d) \n", val1, val2, i, j);fflush(stdout);
								pthread_mutex_lock(&lock);
								duplicate = TRUE;
								pthread_mutex_unlock(&lock);
								break; break;
							}
						}

					}
				}
			}


		}
	}

	pthread_exit(FALSE);
}





