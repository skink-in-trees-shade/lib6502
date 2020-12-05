#include "cartridge/cartridge.h"
#include "cartridge/mapper/exrom/exrom.h"
#include "select_character_rom_bank.h"

void exrom_select_character_rom_bank(void *device, uint16_t address, uint8_t value) {
	struct cartridge *cartridge = device;
	struct exrom *exrom = cartridge->mapper_data;

	uint8_t bank = address & 0x07;
	switch (exrom->chr_mode) {
		case 0x00:
			if (bank == 0x07) {
				exrom->chr_rom_bank[bank] = value;
			}
		break;

		case 0x01:
			if (bank == 0x03 || bank == 0x07) {
				exrom->chr_rom_bank[bank] = value;
			}
		break;

		case 0x02:
			if (bank == 0x01 || bank == 0x03 || bank == 0x05 || bank == 0x07) {
				exrom->chr_rom_bank[bank] = value;
			}
		break;

		case 0x03:
			exrom->chr_rom_bank[bank] = value;
		break;
	}
}