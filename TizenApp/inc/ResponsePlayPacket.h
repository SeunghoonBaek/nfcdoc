#ifndef _RESPONSEPLAYPACKET_H_
#define _RESPONSEPLAYPACKET_H_

#include <sstream>
#include <string.h>
#include <functional>
using std::stringstream;

#include "IPacketBase.h"
#include "SingletonManager.h"
#include "ServerResource.h"
#include "ClientThreadWork.h"

class ResponsePlayPacket : public IPacketBase{
public :
	ResponsePlayPacket();
	~ResponsePlayPacket();

	string getPacket(Client& _client);
	double getNPTTimeAtClientPacket(char* _packet, int _length);

	ClientThreadWork cWorker;
};

#endif
