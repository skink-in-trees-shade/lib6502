#include "cartridge/cartridge.h"
#include "cartridge/mapper/exrom/exrom.h"
#include "write_program_rom.h"

void exrom_write_program_rom(void *device, uint16_t address, uint8_t value) {
	struct cartridge *cartridge = device;
	struct exrom *exrom = cartridge->mapper_data;

	switch (exrom->prg_mode) {
		case 0x01:
			if (address <= 0xBFFF && exrom->prg_rom_writable[1]) {
				cartridge->prg_rom[(exrom->prg_rom_bank[1] << 14) | (address & 0x3FFF)] = value;
			}
		break;

		case 0x02:
			if (address <= 0xBFFF && exrom->prg_rom_writable[1]) {
				cartridge->prg_rom[(exrom->prg_rom_bank[1] << 14) | (address & 0x3FFF)] = value;
			} else if (address >= 0xC000 && address <= 0xDFFF && exrom->prg_rom_writable[2]) {
				cartridge->prg_rom[(exrom->prg_rom_bank[2] << 13) | (address & 0x1FFF)] = value;
			}
		break;

		case 0x03:
			if (address <= 0x9FFF && exrom->prg_rom_writable[0]) {
				cartridge->prg_rom[(exrom->prg_rom_bank[0] << 13) | (address & 0x1FFF)] = value;
			} else if (address >= 0xA000 && address <= 0xBFFF && exrom->prg_rom_writable[1]) {
				cartridge->prg_rom[(exrom->prg_rom_bank[1] << 13) | (address & 0x1FFF)] = value;
			} else if (address >= 0xC000 && address <= 0xDFFF && exrom->prg_rom_writable[2]) {
				cartridge->prg_rom[(exrom->prg_rom_bank[2] << 13) | (address & 0x1FFF)] = value;
			}
		break;
	}
}