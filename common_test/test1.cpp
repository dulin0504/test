#include "stdio.h"
#include "iostream"

#define T1 "/test1"
#define T2 T1"/test2"

#define LOGD(p) printf("[%s:%s:%d]",__FILE__,__FUNCTION__,__LINE__);printf(p)

class A{

private:
	class B;
	B *pb;
};
class A::B{
public:
	B()
	{
		LOGD("test construct\n");
	}
};

template <typename T>
int testFunc1(int a)
{
	LOGD("test\n");
	A::B b;
	return 0;
}


class Util{
public:	
	std::string getStr(int i)
	{

		char str[1024]={0};
		sprintf(str,"str-i=%d\n",i);
		return std::string(str);
	}
};
Util u;


int main(int argc,char *argv[])
{
	LOGD("test\n");
	testFunc1<A>(1);
	//LOGD("T2={%s}\n",T2);
	
	
	std::cout << "[" << u.getStr(1) << "]" << std::endl;
	
	std::cout << "[" << T2 << "]" << std::endl;
	
	
	return 0;
}

