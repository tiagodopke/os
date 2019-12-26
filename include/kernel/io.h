#ifndef _IO_H
#define _IO_H 1

static inline void outb(uint16_t port, uint8_t val) {
	asm volatile ("outb %0, %1" : : "a" (val), "Nd" (port));
}

static inline uint8_t inb(uint16_t port) {
	uint8_t ret;
	asm volatile ("inb %1, %0" : "=a" (ret) : "Nd" (port));
	return ret;
}

static inline uint16_t inw(uint16_t port) {
	uint16_t ret;
	asm volatile ("inw %1, %0" : "=a" (ret) : "Nd" (port));
	return ret;
}

static inline uint64_t read_cr3() {
	uint64_t ret;
	asm volatile ("movq %%cr3, %0" : "=r" (ret));
	return ret;
}

#endif