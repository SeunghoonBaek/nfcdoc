#ifndef _THREADMANAGER_H_
#define _THREADMANAGER_H_

#include <FBase.h>
#include <vector>

using std::vector;
using Tizen::Base::Runtime::Thread;

class ThreadManager{
public :
	ThreadManager(){}
	~ThreadManager(){}

	// register thread
	void RegisterThread( Thread* _pRegisterThread );

	// join -> delete
	void CloseAllThread();

private :
	vector<Thread *> mAssignThread;
};

#endif
