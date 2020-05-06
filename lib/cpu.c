#include <stdlib.h>
#include <string.h>
#include "addressing_table.h"
#include "instruction_table.h"
#include "cpu.h"

struct cpu *cpu_new(void) {
	struct cpu *cpu = calloc(1, sizeof(struct cpu));
	cpu->memory = calloc(0x10000, sizeof(uint8_t));
	return cpu;
}

void cpu_load(struct cpu *cpu, uint8_t *rom, size_t size) {
	cpu->stack_pointer = 0xFF;
	cpu->program_counter = 0x8000;
	cpu->program_end = cpu->program_counter + size - 1;
	memcpy(&cpu->memory[cpu->program_counter], rom, size);
}

void cpu_carry(struct cpu *cpu, uint8_t value) {
	cpu->carry = (int8_t)value >= 0x00;
}

void cpu_zero(struct cpu *cpu, uint8_t value) {
	cpu->zero = value == 0x00;
}

void cpu_negative(struct cpu *cpu, uint8_t value) {
	cpu->negative = value & 0x80;
}

void cpu_push(struct cpu *cpu, uint8_t value) {
	cpu->memory[0x0100 + cpu->stack_pointer--] = value;
}

uint8_t cpu_pull(struct cpu *cpu) {
	return cpu->memory[0x0100 + ++cpu->stack_pointer];
}

bool cpu_running(struct cpu *cpu) {
	return cpu->program_counter < cpu->program_end + 1;
}

void cpu_fetch(struct cpu *cpu) {
	cpu->instruction = cpu->memory[cpu->program_counter++];
}

void cpu_decode(struct cpu *cpu) {
	addressing_table[cpu->instruction](cpu);
}

void cpu_execute(struct cpu *cpu) {
	instruction_table[cpu->instruction](cpu);
}

void cpu_destroy(struct cpu *cpu) {
	free(cpu->memory);
	free(cpu);
}