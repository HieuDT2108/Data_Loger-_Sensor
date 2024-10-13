
#include "onewire.h"

void OneWire_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = ONEWIRE_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(ONEWIRE_PORT, &GPIO_InitStruct);
}

uint8_t OneWire_Reset(void) {
    HAL_GPIO_WritePin(ONEWIRE_PORT, ONEWIRE_PIN, GPIO_PIN_RESET);
    HAL_Delay(480);
    HAL_GPIO_WritePin(ONEWIRE_PORT, ONEWIRE_PIN, GPIO_PIN_SET);
    HAL_Delay(70);
    return HAL_GPIO_ReadPin(ONEWIRE_PORT, ONEWIRE_PIN);
}

void OneWire_WriteByte(uint8_t byte) {
    for (int i = 0; i < 8; i++) {
        HAL_GPIO_WritePin(ONEWIRE_PORT, ONEWIRE_PIN, (byte & (1 << i)) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_Delay(1);
    }
}

uint8_t OneWire_ReadByte(void) {
    uint8_t byte = 0;
    for (int i = 0; i < 8; i++) {
        HAL_GPIO_WritePin(ONEWIRE_PORT, ONEWIRE_PIN, GPIO_PIN_RESET);
        HAL_Delay(1);
        byte |= (HAL_GPIO_ReadPin(ONEWIRE_PORT, ONEWIRE_PIN) << i);
    }
    return byte;
}
