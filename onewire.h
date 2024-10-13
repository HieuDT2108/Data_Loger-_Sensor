
#ifndef ONEWIRE_H
#define ONEWIRE_H

#include "stm32h7xx_hal.h"

#define ONEWIRE_PORT GPIOA
#define ONEWIRE_PIN GPIO_PIN_0

void OneWire_Init(void);
uint8_t OneWire_Reset(void);
void OneWire_WriteByte(uint8_t byte);
uint8_t OneWire_ReadByte(void);

#endif
