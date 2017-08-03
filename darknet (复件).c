#include "src/darknet.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>





int main(int argc, char **argv)
{

    network net=run_detector();

    char *filename[200] ;
    char *outfile={"out"};

    float thresh = .30;
    float hier_thresh = .5;

    while(1) {
        printf("Enter Image Path: ");
        scanf("%s",filename);
        test_detector(net, filename, thresh, hier_thresh, outfile);
    }
    return 0;
}

