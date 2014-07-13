#ifndef _ITHREADCONTEXT_H_
#define _ITHREADCONTEXT_H_

class Client;
class IThreadContext{
public :
	IThreadContext(){}
	virtual ~IThreadContext() = 0;
	virtual void ContextLogic(Client& _client) = 0;
};

#endif