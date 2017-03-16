#include "Job.h"
#include "Constant.h"
#include "arduino.h"

Job::Job(){
	wait_frame = 0;
	wait_ms = 2000;
	frame = 0;
	finish_frame = 500;
}

Job::Job(int _finish_frame, int wait){
	wait_frame = 0;
	wait_ms = wait;
	frame = 0;
	finish_frame = _finish_frame;
}

bool Job::execute(){
	if(frame >= finish_frame){
		bool res = wait();
		if(res){
			finalize();
		}
		return res;
	}
	if(frame == 0){
		initialize();
	}
	interpolate();
	frame++;
	return false;
}

void Job::initialize(){
}

void Job::interpolate(){
}

void Job::finalize(){
}

bool Job::wait(){
	wait_frame++;
	return wait_frame >= (wait_ms / FRAME_INTERVAL);
}

