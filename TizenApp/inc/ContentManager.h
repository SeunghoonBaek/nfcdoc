#ifndef _CONTENTMANAGER_H_
#define _CONTENTMANAGER_H_

#include <vector>
#include <string>
using std::vector;
using std::string;

class ContentManager{
public :
	ContentManager(){}
	~ContentManager(){}

	void RegisterContentPath( string _contentPath );
	void RemoveContent( string _contentName );
	void removeContent ( int _index );
	string operator[](int _index );

private :
	vector<string> mContent;
};

#endif