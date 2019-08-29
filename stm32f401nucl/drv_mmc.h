#ifndef DRV_MMC_H
#define DRV_MMC_H

#define MMC_SPI_OK 0
#define MMC_SPI_FAIL 1
#define MMC_SPI_ERROR 2

#define USE_MMC_CHK 1

void mmc_test(void);
void mmc_start(void);

#endif // DRV_MMC_H
