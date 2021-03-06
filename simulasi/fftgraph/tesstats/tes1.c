#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define MAX_COUNT 24

#define FALSE_COUNT 5

int main(int argc, char *argv[])
{
    uint8_t arrAmpl = 9;
    uint8_t curr_goDown = 1;
    uint8_t prev_goDown = 1;
    uint8_t upAfterDown = 0;
    uint8_t itrCount = 0;

    uint8_t x[MAX_COUNT];
    uint8_t y[MAX_COUNT];
    uint8_t i;

    uint8_t rnd_ask,rnd_resp;

    for(i=0;i<MAX_COUNT;i++){
        x[i] = i;
        y[i] = 0;
    }

    y[0] = 9;
    itrCount++;
    srand(time(NULL));

    while(1){
        rnd_ask = rand() % 3;

        printf("%1i\r\n",arrAmpl);

        if(arrAmpl > 4){ //true sampe batas pendengaran
            curr_goDown = 1;
            arrAmpl--;
        }
        else{
            rnd_resp = rand() % 3;

            if(rnd_resp==rnd_ask){
                curr_goDown = 1;
                arrAmpl--;
            }
            else{
                curr_goDown = 0;
                arrAmpl++;
            }
        }

        if((prev_goDown==1) && (curr_goDown==0)){
            upAfterDown++;
        }
        else if((prev_goDown==1) && (curr_goDown==1)){
            if(upAfterDown>3)upAfterDown--;
        }

        prev_goDown = curr_goDown;
        y[itrCount] = arrAmpl;
        itrCount++;

        if(itrCount==MAX_COUNT){
            printf("maxCount reached\r\n");
            break;
        }

        if(upAfterDown==5)break;
    }

    for(i=itrCount;i<MAX_COUNT;i++){
        y[i] = arrAmpl;
    }

    printf("\r\n");
    printf("last Ampl= %1i\r\n",arrAmpl);

    FILE *gnuplot = popen("gnuplot", "w");
    if (!gnuplot) {
        perror("popen");
        exit(EXIT_FAILURE);
    }

    fprintf(gnuplot, "plot '-' u 1:2 t 'AmplScale' w lp\n");
    for (i=0;i < MAX_COUNT;i++) {
        fprintf(gnuplot,"%d %d\n", x[i], y[i]);
    }

    fprintf(gnuplot, "e\n");
    fflush(gnuplot);

    fprintf(stdout, "Click Ctrl+d to quit...\n");
    getchar();

    pclose(gnuplot);
    exit(EXIT_SUCCESS);
}
