#ifndef _SINGLETONMANAGER_H_
#define _SINGLETONMANAGER_H_

template <typename T>
class SingletonManager{
public :
	static T& getInstance(){
		if( ! m_pInstance  ){
			m_pInstance = new T();
		}

		return *m_pInstance;
	}

	static void freeInstance(){
		if( m_pInstance ) {
			delete m_pInstance;
			m_pInstance = 0 ;
		}
	}

protected :
	SingletonManager(){}
		~SingletonManager(){
			freeInstance();
		}

private :
	static T* m_pInstance;
	SingletonManager(const SingletonManager<T>& rhs){ }
	SingletonManager<T>& operator=(const SingletonManager<T>& rhs){ return this; }
};


template <typename T>
T* SingletonManager<T>::m_pInstance = 0;

#endif
