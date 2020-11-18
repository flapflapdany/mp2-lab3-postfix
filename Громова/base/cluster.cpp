#include "Cluster.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

Cluster::Cluster() :all_task(0), err_tasks(0), ct(0)
{
	all_tacts = 0;
	all_proc = 0;
	free_proc = 0;
	size_queue = 0;
	load_proc = nullptr;
}

Cluster:: ~Cluster()
{
	if (load_proc != nullptr)
		delete[] load_proc;
}

Task Cluster::CreateTask()
{
	srand((unsigned int)time(NULL));
	Task task;
	task.processors = rand() % all_proc + 1;
	task.tacts = rand() % all_tacts + 1;
	return task;
}

void Cluster::Start(int tacts, int proc, int size_queue)
{
	all_tacts = tacts;
	all_proc = proc;
	free_proc = proc;
	this->size_queue = size_queue;
	load_proc = new int[proc];
	for (int i = 0; i < proc; i++)
	{
		load_proc[i] = 0;
	}
	Run();
}

void Cluster::Run()
{
	TQueue <Task> queue(size_queue);
	for (int i = 0; i < all_tacts; i++)
	{
		Task tmp = CreateTask();
		if (tmp.processors != 0)
		{
			all_task++;
			if (free_proc < tmp.processors || queue.IsFull())
				err_tasks++;
			else
				queue.PushBack(tmp);
		}
		if (queue.IsEmpty() == false)
		{
			int count_tacts = tmp.tacts;
			int count_of_proc = tmp.processors;
			int proc_busy = tmp.processors;
			if (free_proc >= tmp.processors)
			{
				for (int i = 0; i < all_proc; i++)
				{
					if ((proc_busy > 0) && (load_proc[i] == 0))
					{
						load_proc[i] = count_tacts + 1;
						proc_busy--;
					}
					if (proc_busy == 0)
					{
						break;
					}
				}
				int k = tmp.processors;
				free_proc = free_proc - k;
				queue.PopFront();
			}
		}
		for (int i = 0; i < all_proc; i++)
		{
			if (load_proc[i] > 0)
			{
				load_proc[i]--;
				if (load_proc[i] == 0)
				{
					free_proc++;
				}
			}
		}
		ct = ct + (all_proc - free_proc);
	}
	Get_Status();
}
void Cluster::Get_Status()
{
	cout << "Общее количество задач : " << all_task << endl;
	cout << "Число задач, которые невозможно выполнить: " << err_tasks << endl;
	cout << "Средняя загрузка процессора:" << (ct / all_tacts + 1) << endl;
}