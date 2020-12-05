#ifndef EXROM_H
#define EXROM_H

#include <stdint.h>
#include <stdbool.h>
#include "cartridge/cartridge.h"

struct exrom {
	uint8_t *name_table;

	uint8_t prg_mode;
	uint8_t chr_mode;

	uint8_t *prg_ram;
	uint8_t prg_ram_bank;
	uint8_t prg_rom_bank[4];
	bool prg_rom_writable[4];
	uint8_t chr_rom_bank[8];
};

void exrom_load(struct cartridge *cartridge);

#endif