#include "cpx.h"

void cpx(struct cpu *cpu) {
	uint8_t result = cpu->x - cpu_peek(cpu, cpu->operand);
	cpu->carry = cpu->x >= result;
	cpu_zero(cpu, result);
	cpu_negative(cpu, result);
}