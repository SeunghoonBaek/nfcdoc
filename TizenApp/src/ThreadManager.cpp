#include "ThreadManager.h"

void ThreadManager::CloseAllThread(){
	if( mAssignThread.size() == 0 ) return;

	auto itr = mAssignThread.begin();
	while( itr != mAssignThread.end() ){
		itr = mAssignThread.erase( itr );
	}
}

void ThreadManager::RegisterThread( Thread* _pRegisterThread ){
	if( !_pRegisterThread ){
		return;
	}

	mAssignThread.push_back( _pRegisterThread );
}
