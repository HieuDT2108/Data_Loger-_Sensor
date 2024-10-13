
#include "main.h"
#include "ds18b20.h"
#include "sdcard.h"
#include <stdio.h>

void SystemClock_Config(void);

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_SDMMC1_SD_Init();
    MX_FATFS_Init();

    float temperature;
    char data[50];

    while (1) {
        temperature = DS18B20_ReadTemp();
        sprintf(data, "Temperature: %.2f C\n", temperature);
        SD_WriteToFile("data_log.txt", data);
        HAL_Delay(1000); // Ghi dữ liệu mỗi giây
    }
}
