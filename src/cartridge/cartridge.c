#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "mapper.h"
#include "format/ines.h"
#include "error.h"
#include "cartridge.h"

static uint8_t _cartridge_cpu_read(struct device *device, uint16_t address) {
	struct cartridge *cartridge = (struct cartridge *)((char *)device - offsetof(struct cartridge, cpu_device));
	return mappers[cartridge->mapper].cpu_read(cartridge, address);
}

static void _cartridge_cpu_write(struct device *device, uint16_t address, uint8_t value) {
	struct cartridge *cartridge = (struct cartridge *)((char *)device - offsetof(struct cartridge, cpu_device));
	mappers[cartridge->mapper].cpu_write(cartridge, address, value);
}

static uint8_t _cartridge_ppu_read(struct device *device, uint16_t address) {
	struct cartridge *cartridge = (struct cartridge *)((char *)device - offsetof(struct cartridge, ppu_device));
	return mappers[cartridge->mapper].ppu_read(cartridge, address);
}

static void _cartridge_ppu_write(struct device *device, uint16_t address, uint8_t value) {
	struct cartridge *cartridge = (struct cartridge *)((char *)device - offsetof(struct cartridge, ppu_device));
	mappers[cartridge->mapper].ppu_write(cartridge, address, value);
}

struct cartridge *cartridge_new(void) {
	struct cartridge *cartridge = calloc(1, sizeof(struct cartridge));

	cartridge->cpu_device.address_from = 0x8000;
	cartridge->cpu_device.address_to = 0xFFFF;
	cartridge->cpu_device.read = &_cartridge_cpu_read;
	cartridge->cpu_device.write = &_cartridge_cpu_write;

	cartridge->ppu_device.address_from = 0x0000;
	cartridge->ppu_device.address_to = 0x1FFF;
	cartridge->ppu_device.read = &_cartridge_ppu_read;
	cartridge->ppu_device.write = &_cartridge_ppu_write;

	return cartridge;
}

void cartridge_load(struct cartridge *cartridge, const char *filename) {
	if (!ines_load(cartridge, filename)) {
		error("Unknown cartridge format.");
	}

	if (mappers[cartridge->mapper].cpu_read == NULL) {
		error("Unknown mapper %02X.", cartridge->mapper);
	}
}

void cartridge_tick(struct cartridge *cartridge) {
	(void)cartridge;
}

void cartridge_destroy(struct cartridge *cartridge) {
	free(cartridge->chr_rom);
	free(cartridge->prg_rom);
	free(cartridge);
}