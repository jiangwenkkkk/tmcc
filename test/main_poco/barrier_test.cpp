//
// Created by james on 2020-06-18.
//

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>

#define NTHR   8                /* number of threads */
#define NUMNUM 800L         /* number of numbers to sort */
#define TNUM   (NUMNUM/NTHR)    /* number to sort per thread */

long nums[NUMNUM];
long snums[NUMNUM];

pthread_barrier_t ba;

#define heapsort qsort

/*
 * Compare two long integers (helper function for heapsort)
 */
int complong(const void *arg1, const void *arg2)
{
	long l1 = *(long *)arg1;
	long l2 = *(long *)arg2;

	if (l1 == l2)
		return 0;
	else if (l1 < l2)
		return -1;
	else
		return 1;
}

/*
 * Worker thread to sort a portion of the set of numbers.
 */
void * thr_fn(void *arg)
{
	long    idx = (long)arg;

	heapsort(&nums[idx], TNUM, sizeof(long), complong);
	pthread_barrier_wait(&ba);

	/*
	 * Go off and perform more work ...
	 */
	return((void *)0);
}

/*
 * Merge the results of the individual sorted ranges.
 */
void merge()
{
	long    idx[NTHR];
	long    i, minidx, sidx, num;

	for (i = 0; i < NTHR; i++)
		idx[i] = i * TNUM;
	for (sidx = 0; sidx < NUMNUM; sidx++) {
		num = LONG_MAX;
		for (i = 0; i < NTHR; i++) {
			if ((idx[i] < (i+1)*TNUM) && (nums[idx[i]] < num)) {
				num = nums[idx[i]];
				minidx = i;
			}
		}
		snums[sidx] = nums[idx[minidx]];
		idx[minidx]++;
	}
}

int main()
{
	unsigned long   i;
	struct timeval  start, end;
	long long       startusec, endusec;
	double          elapsed;
	int             err;
	pthread_t       tid;

	/*
	 * Create the initial set of numbers to sort.
	 */
	srandom(1);
	for (i = 0; i < NUMNUM; i++)
		nums[i] = random();

	/*
	 * Create 8 threads to sort the numbers.
	 */
	gettimeofday(&start, NULL);
	pthread_barrier_init(&ba, NULL, NTHR+1);
	for (i = 0; i < NTHR; i++) {
		err = pthread_create(&tid, NULL, thr_fn, (void *)(i * TNUM));
		if (err != 0)
		{
			printf("can't create thread");
			return -1;
		}
	}
	pthread_barrier_wait(&ba);
	merge();
	gettimeofday(&end, NULL);

	/*
	 * Print the sorted list.
	 */
	startusec = start.tv_sec * 1000000 + start.tv_usec;
	endusec = end.tv_sec * 1000000 + end.tv_usec;
	elapsed = (double)(endusec - startusec) / 1000000.0;
	printf("sort took %.4f seconds\n", elapsed);
	for (i = 0; i < NUMNUM; i++)
	{
		if( (i < (NUMNUM - 1)) && (snums[i] > snums[i + 1]) )
			printf("sort failed!\n");
		printf("%ld,", snums[i]);
	}
	printf("\n");

	exit(0);
}