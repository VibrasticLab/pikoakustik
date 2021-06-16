#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int main(int argc, char *argv[])
{
    uint8_t arrAmpl = 9;
    uint8_t curr_goDown = 1;
    uint8_t prev_goDown = 1;
    uint8_t upAfterDown = 0;
    uint8_t maxCount = 0;

    while(1){
        printf("%1i\r\n",arrAmpl);

        if(arrAmpl > 4){ //batas pendengaran
            curr_goDown = 1;
            arrAmpl--;
        }
        else{
            curr_goDown = 0;
            arrAmpl++;
        }

        if((prev_goDown==1) && (curr_goDown==0)){
            upAfterDown++;
        }

        prev_goDown = curr_goDown;

        if(maxCount==25){
            printf("maxCount reached\r\n");
            break;
        }

        if(upAfterDown==5)break;
    }

    printf("last Ampl= %1i\r\n",arrAmpl);
    return 0;
}
