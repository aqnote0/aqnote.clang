#include <iostream>
#include <cstdlib>
#include <dlfcn.h>
 
using namespace std;
 
int main(int argc, char **argv) {
	if(argc != 2) {
		cout << "argument error!" << endl;
		exit(1);
	}
 
	//pointer to function
	typedef void (*pf_t)();
	
	char *err = NULL;
	//open the lib
	void *handle = dlopen(argv[1], RTLD_NOW);
	
	if(!handle) {
		cout << "load " << argv[1] << " failed! " << dlerror() << endl;
		exit(1);
	}
 
	//clear error info
	dlerror();
 
	pf_t pf  = (pf_t)dlsym(handle, "fcn");
	err = dlerror();
	if(err) {
		cout << "can't find symbol fcn! " << err << endl;
		exit(1);
	}
 
	//call function by pointer
	pf();
 
	dlclose(handle);
 
	return 0;
}