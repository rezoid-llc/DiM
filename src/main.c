/*
//  "Digital Implmentation Machine" Emulation System
//  Written by Daniel Perez.
*/

#include <stdio.h>
#include <stdint.h>
#define DIM_MEMORY_MAXIMUM (1 << 24)
#define DIM_MEMORY_INSTALL (1 << 8)
#define DIM_MEMORY_INBOUND(increment) (increment < DIM_MEMORY_INSTALL && increment < DIM_MEMORY_MAXIMUM)

uint16_t register_a;
uint16_t register_b;
uint16_t register_c;
uint16_t register_d;
uint32_t register_e;
uint8_t  register_f;

uint8_t  memory[DIM_MEMORY_INSTALL];

void DIM_reset (void) {
  
  uint16_t register_a = 0x0000;
  uint16_t register_b = 0x0000;
  uint16_t register_c = 0x0000;
  uint16_t register_d = 0x0000;
  uint32_t register_e = 0x00000000;
  uint8_t  register_f = 0x00;

  uint32_t increment  = 0x00000000;
  while (DIM_MEMORY_INBOUND(increment)) {
      memory[increment] = 0x00;
      increment += 0x01;
  }
}

void DIM_memory_dump (void) {

  uint32_t increment = 0x00000000;
  while (DIM_MEMORY_INBOUND(increment)) {
      printf("0x%06X  >>  0x%02X \n", increment, memory[increment]);
      increment += 0x01;
  }
  
}


int main (void) {

  DIM_reset();
  DIM_memory_dump();

  return 0x00;
  
}
