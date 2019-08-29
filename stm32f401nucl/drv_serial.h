#ifndef DRV_SERIAL_H
#define DRV_SERIAL_H

#define USE_SHELL_TEST  FALSE

#define SHELL_WA_SIZE   THD_WORKING_AREA_SIZE(1024)

#if USE_SHELL_TEST
    #define TEST_WA_SIZE    THD_WORKING_AREA_SIZE(256)
#endif

void shell_start(void);
void shell_term(void);

#endif // DRV_SERIAL_H
