#include <stdlib.h>
#include "src/darknet.h"
#include <dlfcn.h>
 
int main()
{ 
	void *handle;
	network (*run)();
	void (*test)(network ,char *, float , float , char *);
	
	handle=dlopen("/media/x/d/darknet/darknet-yolo-so2/libdarknet-shared.so",RTLD_LAZY);
	dlerror();
	run=dlsym(handle,"run_detector");

	test=dlsym(handle,"test_detector");	

	char filename[200] ;
    	char *outfile={"out"};
	float thresh = .30;
    	float hier_thresh = .5;


	network net=run();
	while(1){
	printf("Enter Image Path: ");
        scanf("%s",filename);
	test(net, filename, thresh, hier_thresh, outfile);
	}	
	return 0;

}
