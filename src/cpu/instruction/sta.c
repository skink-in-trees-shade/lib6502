#include "sta.h"

void sta(struct cpu *cpu) {
	cpu_poke(cpu, cpu->operand, cpu->accumulator);
}