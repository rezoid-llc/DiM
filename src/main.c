/*
//  "Digital Implmentation Machine" Emulation System
//  Written by Daniel Perez.
*/


#include <stdio.h>
#include <stdint.h>
#define DIM_MEMORY_MAXIMUM (1 << 24)
#define DIM_MEMORY_INSTALL (1 << 2)
#define DIM_MEMORY_INBOUND(increment) (increment < DIM_MEMORY_INSTALL && increment < DIM_MEMORY_MAXIMUM)

uint16_t register_a;
uint16_t register_b;
uint16_t register_c;
uint16_t register_d;
uint32_t register_e;
uint8_t  register_f;

uint8_t  memory[DIM_MEMORY_INSTALL];


void DIM_fullReset (void) {
  
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

void DIM_memoryDump (void) {

  uint32_t increment = 0x00000000;
  while (DIM_MEMORY_INBOUND(increment)) {

    if ((increment % 16) == 0x00 && increment > 0x00) {
      printf("\n0x%06X  >>  ", increment);
    } else if ((increment % 16) == 0x00) {
      printf("0x%06X  >>  ", increment);      
    }

    printf("%02X ", increment[memory]);
    increment += 0x01;
      
  }

  printf("\n");
  
}

void DIM_tick (void) {

    uint8_t extracted_opcode = (memory[register_e] & 0xFC) >> 0x02;
    uint8_t extracted_select = (memory[register_e] & 0x03);

    printf("OP: 0x%02X  II: 0x%02X  FR: 0b%08B  EO: 0x%08X  ES: 0x%08X\n", memory[register_e], register_e, register_f, extracted_opcode, extracted_select);

    switch (extracted_opcode) {

      case (0x00):
        //  "NLL":
        register_e += 0x01;
        break;

      case (0x01):
        //  "TRM":
        register_f |= 0x01;
        break;

      default:
      //  "NLL":
        register_e += 0x01;
        break;
      
    }
  
}


int main (void) {

  DIM_fullReset();

  //  Higher six bits are the instruction.
  //  Lower two bits is the register selection.
  memory[0x00] = 0b00000100;

  DIM_memoryDump();

  while (DIM_MEMORY_INBOUND(register_e) && (!(register_f & 0x01))) {
    DIM_tick();
  }
  
  return 0x00;
  
}
