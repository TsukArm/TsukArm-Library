#include "JobQueue.h"
#include "stdio.h"
#include "arduino.h"

JobQueue::JobQueue(){
	queue_head = 0;
	queue_num = 0;
}

JobQueue::~JobQueue(){
	for(int i=0; i<QUEUE_SIZE; i++){
		delete jobs[i];
	    jobs[i] = NULL;
	}
}

int JobQueue::left(){
	return QUEUE_SIZE - queue_num;
}

bool JobQueue::isEmpty(){
	return queue_num == 0;
}

bool JobQueue::enqueue(Job *job){
	if(left() <= 0){
		return false;
	}
	int i = (queue_head + queue_num) % QUEUE_SIZE;
	jobs[i] = job;
	queue_num++;
	return true;
}

bool JobQueue::dequeue(){
	if(queue_num <= 0){
		return false;
	}
	delete jobs[queue_head];
	jobs[queue_head] = NULL;
	queue_head++;
	queue_head %= QUEUE_SIZE;
	queue_num--;
	return true;
}

Job* JobQueue::front(){
	return jobs[queue_head];
}

void JobQueue::execute(){
	if(!isEmpty() && front()->execute()){
		dequeue();
	}
}

void JobQueue::clear(){
	for(int i=0; i<QUEUE_SIZE; i++){
		delete jobs[i];
		jobs[i] = NULL;
	}
	queue_head = 0;
	queue_num = 0;
}

