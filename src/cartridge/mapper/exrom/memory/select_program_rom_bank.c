#include "cartridge/cartridge.h"
#include "cartridge/mapper/exrom/exrom.h"
#include "select_program_rom_bank.h"

void exrom_select_program_rom_bank(void *device, uint16_t address, uint8_t value) {
	struct cartridge *cartridge = device;
	struct exrom *exrom = cartridge->mapper_data;

	uint8_t bank = address & 0x03;
	exrom->prg_rom_writable[bank] = (value >> 7) == 0x00;

	switch (exrom->prg_mode) {
		case 0x00:
			if (bank == 0x03) {
				exrom->prg_rom_bank[bank] = (value & 0x7C) >> 2;
			}
		break;

		case 0x01:
			if (bank == 0x01 || bank == 0x03) {
				exrom->prg_rom_bank[bank] = (value & 0x7E) >> 1;
			}
		break;

		case 0x02:
			if (bank == 0x01) {
				exrom->prg_rom_bank[bank] = (value & 0x7E) >> 1;
			} else if (bank == 0x02 || bank == 0x03) {
				exrom->prg_rom_bank[bank] = value & 0x7F;
			}
		break;

		case 0x03:
			exrom->prg_rom_bank[bank] = (value & 0x7F) & (cartridge->prg_rom_count * 2 - 1);
		break;
	}
}