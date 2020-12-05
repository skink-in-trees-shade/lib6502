#include "cartridge/cartridge.h"
#include "cartridge/mapper/exrom/exrom.h"
#include "write_character_rom.h"

void exrom_write_character_rom(void *device, uint16_t address, uint8_t value) {
	struct cartridge *cartridge = device;
	struct exrom *exrom = cartridge->mapper_data;

	switch (exrom->chr_mode) {
		case 0x00:
			cartridge->chr_rom[(exrom->chr_rom_bank[7] << 13) | (address & 0x1FFF)] = value;
		break;

		case 0x01:
			if (address <= 0x0FFF) {
				cartridge->chr_rom[(exrom->chr_rom_bank[3] << 12) | (address & 0x0FFF)] = value;
			} else if (address >= 0x1000) {
				cartridge->chr_rom[(exrom->chr_rom_bank[7] << 12) | (address & 0x0FFF)] = value;
			}
		break;

		case 0x02:
			if (address <= 0x07FF) {
				cartridge->chr_rom[(exrom->chr_rom_bank[1] << 11) | (address & 0x07FF)] = value;
			} else if (address >= 0x0800 && address <= 0x0FFF) {
				cartridge->chr_rom[(exrom->chr_rom_bank[3] << 11) | (address & 0x07FF)] = value;
			} else if (address >= 0x1000 && address <= 0x17FF) {
				cartridge->chr_rom[(exrom->chr_rom_bank[5] << 11) | (address & 0x07FF)] = value;
			} else if (address >= 0x1800) {
				cartridge->chr_rom[(exrom->chr_rom_bank[7] << 11) | (address & 0x07FF)] = value;
			}
		break;

		case 0x03:
			if (address <= 0x03FF) {
				cartridge->chr_rom[(exrom->chr_rom_bank[0] << 10) | (address & 0x03FF)] = value;
			} else if (address >= 0x0400 && address <= 0x07FF) {
				cartridge->chr_rom[(exrom->chr_rom_bank[1] << 10) | (address & 0x03FF)] = value;
			} else if (address >= 0x0800 && address <= 0x0BFF) {
				cartridge->chr_rom[(exrom->chr_rom_bank[2] << 10) | (address & 0x03FF)] = value;
			} else if (address >= 0x0C00 && address <= 0x0FFF) {
				cartridge->chr_rom[(exrom->chr_rom_bank[3] << 10) | (address & 0x03FF)] = value;
			} else if (address >= 0x1000 && address <= 0x13FF) {
				cartridge->chr_rom[(exrom->chr_rom_bank[4] << 10) | (address & 0x03FF)] = value;
			} else if (address >= 0x1400 && address <= 0x17FF) {
				cartridge->chr_rom[(exrom->chr_rom_bank[5] << 10) | (address & 0x03FF)] = value;
			} else if (address >= 0x1800 && address <= 0x1BFF) {
				cartridge->chr_rom[(exrom->chr_rom_bank[6] << 10) | (address & 0x03FF)] = value;
			} else if (address >= 0x1C00) {
				cartridge->chr_rom[(exrom->chr_rom_bank[7] << 10) | (address & 0x03FF)] = value;
			}
		break;
	}
}