/*
//  "Digital Implmentation Machine" Emulation System
//  Written by Daniel Perez.
*/


#include <stdio.h>
#include <stdint.h>
#define DIM_MEMORY_MAXIMUM (1 << 24)
#define DIM_MEMORY_INSTALL (1 << 2)
#define DIM_MEMORY_INBOUND(increment) (increment < DIM_MEMORY_INSTALL && increment < DIM_MEMORY_MAXIMUM)
#define DIM_MEMORY_WORD(byte_01, byte_02) ((uint16_t)byte_01 << 8) | byte_02

uint16_t register_a;
uint16_t register_b;
uint16_t register_c;
uint16_t register_d;
uint32_t register_e;
uint8_t  register_f;

uint8_t  memory[DIM_MEMORY_INSTALL];


void DIM_fullReset (void) {
  
  register_a = 0x0000;
  register_b = 0x0000;
  register_c = 0x0000;
  register_d = 0x0000;
  register_e = 0x00000000;
  register_f = 0x00;

  uint32_t increment  = 0x00000000;
  while (DIM_MEMORY_INBOUND(increment)) {
      memory[increment] = 0x00;
      increment += 0x01;
  }
}

void DIM_memoryDump (void) {

  uint32_t increment = 0x00000000;
  printf("MEMORY DUMP\n");
  while (DIM_MEMORY_INBOUND(increment)) {

    if ((increment % 16) == 0x00 && increment > 0x00) {
      printf("\n0x%06X  >>  ", increment);
    } else if ((increment % 16) == 0x00) {
      printf("0x%06X  >>  ", increment);      
    }

    printf("%02X ", memory[increment]);
    increment += 0x01;
      
  }

  printf("\n");
  
}

void DIM_registerDump (void) {
  printf("REGISTER DUMP\n");
  printf("RA: 0x%04X\n", register_a);
  printf("RB: 0x%04X\n", register_b);
  printf("RC: 0x%04X\n", register_c);
  printf("RD: 0x%04X\n", register_d);
  printf("RE: 0x%06X\n", register_e);
  printf("RF: 0b%08B\n", register_f);
}

void DIM_tick (void) {

    uint8_t opcode = (memory[register_e] & 0xFC) >> 0x02;
    uint8_t select = (memory[register_e] & 0x03);

    printf("OP: 0x%02X  RE: 0x%02X  SB: 0b%08B  IO: 0x%08X  IS: 0x%08X\n", memory[register_e], register_e, register_f, opcode, select);

    switch (opcode) {

      case (0x00):;
        //  "NLL":
        register_e += 0x01;
        break;

      case (0x01):;
        //  "TRM":
        register_f |= 0x01;
        break;

      case (0x08):;
        //  "LWI"
        uint16_t immediate = DIM_MEMORY_WORD(memory[register_e + 0x01], memory[register_e + 0x02]);
        if (select == 0x00) { register_a = immediate;
        } else if (select == 0x01) { register_b = immediate;
        } else if (select == 0x02) { register_c = immediate;
        } else if (select == 0x03) { register_d = immediate;
        } register_e += 0x03;
        break;

      default:;
      //  "NLL":
        register_e += 0x01;
        break;
      
    }
  
}


int main (void) {

  DIM_fullReset();

  //  Higher six bits are the instruction.
  //  Lower two bits is the register selection.
  memory[0x00] = 0b00100000;
  memory[0x01] = 0xFF;
  memory[0x02] = 0xFF;
  memory[0x03] = 0b00000100;

  DIM_memoryDump();

  printf("EXECUTION STARTED:\n");
  while (DIM_MEMORY_INBOUND(register_e) && (!(register_f & 0x01))) {
    DIM_tick();
  }

  DIM_registerDump();
  
  return 0x00;
  
}
