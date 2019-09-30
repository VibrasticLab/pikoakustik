#ifndef DRV_SERIAL_H
#define DRV_SERIAL_H

#define SHELL_WA_SIZE   THD_WORKING_AREA_SIZE(1024)

void shell_start(void);
void shell_term(void);

#endif // DRV_SERIAL_H
