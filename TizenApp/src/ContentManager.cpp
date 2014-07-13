#include "ContentManager.h"

void ContentManager::RegisterContentPath( string _contentPath ){
	mContent.push_back( _contentPath );
	return;
}
void ContentManager::RemoveContent( string _contentName ){
	vector<string>::iterator itr = mContent.begin();

	while( itr != mContent.end() ){
		if( (*itr) == _contentName){
			mContent.erase( itr );
			break;
		}

		++itr;
	}
}

void ContentManager::removeContent ( int _index ){
	if( _index < 0 || _index >= mContent.size() )
		return;

	vector<string>::iterator itr = mContent.begin();

	int loopCount = 0;
	while( itr != mContent.end() ){
		if( loopCount == _index ){
			mContent.erase( itr );

		}

		++loopCount;
		++itr;
	}
}

string ContentManager::operator[](int _index ){
	if( _index < 0 || _index >= mContent.size() )
		return "";

	return mContent[_index];
}