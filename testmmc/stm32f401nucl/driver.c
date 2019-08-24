#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "ff.h"

#include "../../driver.h"

//================================================================================

static uint16_t led_delay=50;

static THD_WORKING_AREA(waLed1, 128);
static THD_FUNCTION(thdLed1, arg) {

  (void)arg;
  chRegSetThreadName("led1");
  while (true) {
    palTogglePad(GPIOA, 5);
    chThdSleepMilliseconds(led_delay);
  }
}

static void led_start(void){
    palSetPadMode(GPIOA,5,PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(GPIOA,5);

    chThdCreateStatic(waLed1, sizeof(waLed1),	NORMALPRIO, thdLed1, NULL);
}

//================================================================================

#define MMC_SPI_OK 0
#define MMC_SPI_FAIL 1
#define MMC_SPI_ERROR 2

#define USE_MMC_CHK 1

MMCDriver MMCD1;

static bool filesystem_ready=true;
static uint8_t mmc_spi_status_flag=MMC_SPI_OK;

static SPIConfig hs_spicfg = {NULL, GPIOA, 4, 0};
static SPIConfig ls_spicfg = {NULL, GPIOA, 4, SPI_CR1_BR_2 | SPI_CR1_BR_1};
static MMCConfig mmccfg = {&SPID3, &ls_spicfg, &hs_spicfg};

#if USE_MMC_CHK
static void mmc_check(void){
    FATFS FatFs;
    FRESULT err;
    uint32_t clusters;
    FATFS *fsp;

    mmc_spi_status_flag=MMC_SPI_OK;
    filesystem_ready=false;

    if(mmcConnect(&MMCD1)) { filesystem_ready = true; }

    err = f_mount(&FatFs, "", 0);
    if(err == FR_OK){ filesystem_ready = true; }

    if (!filesystem_ready) { mmc_spi_status_flag=MMC_SPI_FAIL;return; }

    mmc_spi_status_flag=MMC_SPI_ERROR;
    err = f_getfree("/", &clusters, &fsp);
    if(err == FR_OK){ mmc_spi_status_flag=MMC_SPI_OK; led_delay=500; }

    f_mount(0, "", 0);
}
#endif

static void mmc_test(void){
    char buffer[36];

    FATFS *FatFs;
    FIL Fil;
    UINT bw;

    FatFs = malloc(sizeof (FatFs));

#if USE_MMC_CHK
    mmc_check();
#endif

    if( (filesystem_ready==true) && (mmc_spi_status_flag==MMC_SPI_OK) ){
        chsnprintf(buffer,36,"Test\n");

        f_mount(FatFs, "", 0);

        f_open(&Fil, "tes.txt", FA_WRITE | FA_READ | FA_OPEN_ALWAYS);
        f_lseek(&Fil, f_size(&Fil));
        f_write(&Fil, buffer, strlen(buffer), &bw);
        f_close(&Fil);

        f_mount(0, "", 0);
        free(FatFs);
    }
}

static void mmc_start(void){
    // SPI1 and SPI2 use alternate function 5
    // SPI3 use alternate function 6
    // APB on SPI use 24MHz
    palSetPadMode(GPIOC, 12, PAL_MODE_ALTERNATE(6) | PAL_STM32_OSPEED_HIGHEST); //MOSI
    palSetPadMode(GPIOC, 11, PAL_MODE_ALTERNATE(6) | PAL_STM32_OSPEED_HIGHEST); //MISO
    palSetPadMode(GPIOC, 10, PAL_MODE_ALTERNATE(6) | PAL_STM32_OSPEED_HIGHEST); //SCK
    palSetPadMode(GPIOA, 4, PAL_MODE_OUTPUT_PUSHPULL); //NSS
    palSetPad(GPIOA, 4);

    mmcObjectInit(&MMCD1);
    mmcStart(&MMCD1, &mmccfg);
    chThdSleepMilliseconds(100);

    palSetPadMode(GPIOA,5,PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(GPIOA,5);
}

//================================================================================

// ============================= Platform Calling ===================

void system_init(void){
	halInit();
	chSysInit();

    mmc_start();
    mmc_test();

    led_start();
}

void driver_init(void){chThdSleepMilliseconds(100);}
void sample_prep(
    double FR, // Frequency (Hz)
    double DUR, //Duration (s)
    int AMP) //Amplitudo
{ (void) FR;(void) DUR;(void) AMP; chThdSleepMilliseconds(100); }
void play_wave(void){chThdSleepMilliseconds(100);}
void system_loop(void){chThdSleepMilliseconds(100);}
