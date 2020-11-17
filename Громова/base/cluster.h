#ifndef __ClUSTER_H__
#define __ClUSTER_H__
#include <vector>
#include <time.h>
#include "Queue.h"
using namespace std;

struct Task
{
	int processors;
	int tacts;
};

class Cluster
{
	int all_tacts;
	int size_queue;
	int all_proc;
	int free_proc;
	int *load_proc;
	int all_task;
	int err_tasks;
	int ct;
	Task CreateTask();
public:
	Cluster();
	~Cluster();
	void Start(int tacts, int proc, int sizequeue);
	void Run();
	void Get_Status();
};

#endif