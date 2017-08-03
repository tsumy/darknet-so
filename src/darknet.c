#include "darknet.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

extern void predict_classifier(char *datacfg, char *cfgfile, char *weightfile, char *filename, int top);
extern void test_detector(network net,char *filename, float thresh, float hier_thresh, char *outfile);
extern void run_voxel(int argc, char **argv);
extern void run_yolo(int argc, char **argv);
extern network run_detector();
extern void run_coco(int argc, char **argv);
extern void run_writing(int argc, char **argv);
extern void run_captcha(int argc, char **argv);
extern void run_nightmare(int argc, char **argv);
extern void run_dice(int argc, char **argv);
extern void run_compare(int argc, char **argv);
extern void run_classifier(int argc, char **argv);
extern void run_regressor(int argc, char **argv);
extern void run_segmenter(int argc, char **argv);
extern void run_char_rnn(int argc, char **argv);
extern void run_vid_rnn(int argc, char **argv);
extern void run_tag(int argc, char **argv);
extern void run_cifar(int argc, char **argv);
extern void run_go(int argc, char **argv);
extern void run_art(int argc, char **argv);
extern void run_super(int argc, char **argv);
extern void run_lsd(int argc, char **argv);



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

