#ifndef EXROM_SELECT_CHARACTER_ROM_BANK_H
#define EXROM_SELECT_CHARACTER_ROM_BANK_H

#include <stdint.h>

void exrom_select_character_rom_bank(void *device, uint16_t address, uint8_t value);

#endif