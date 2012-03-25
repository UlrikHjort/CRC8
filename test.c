/*******************************************************************************
 *                                                                             *
 *                            8 bit CRC Calculation                            *
 *                                                                             *
 *                                   test.c                                    *
 *                                                                             *
 *                                   main test                                 *
 *                                                                             *
 *                    Copyright (C) 1997 Ulrik Hørlyk Hjort                    *
 *                                                                             *
 *   8 bit crc calculation is free software;  you can  redistribute it         *
 *   and/or modify it under terms of the  GNU General Public License           *
 *   as published  by the Free Software  Foundation;  either version 2,        *
 *   or (at your option) any later version.                                    *
 *   8 bit crc calculation is distributed in the hope that it will be          *
 *   useful, but WITHOUT ANY WARRANTY;  without even the  implied warranty     *
 *   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                   *
 *   See the GNU General Public License for  more details.                     *
 *   You should have  received  a copy of the GNU General                      *
 *   Public License  distributed with Yolk.  If not, write  to  the  Free      *
 *   Software Foundation,  51  Franklin  Street,  Fifth  Floor, Boston,        *
 *   MA 02110 - 1301, USA.                                                     *
 *                                                                             *
 ******************************************************************************/
#include <stdio.h>
#include "crc8.h"

int main() 
{
  unsigned char crc = 0;
  unsigned char c = 't';

  init_crc8();

  CRC8(crc,c);
  printf("CRC 't' = %X (expected 0x4b)\n", (unsigned int) crc);
  c = 'e';
  CRC8(crc,c);
  printf("CRC 'te' = %X (expected 0xca)\n", (unsigned int) crc);

  c = 's';
  CRC8(crc,c);
  printf("CRC 'tes' = %X (expected 0x26\n", (unsigned int) crc);

  c = 't';
  CRC8(crc,c);
  printf("CRC 'test' = %X (expected 0xb9)\n", (unsigned int) crc);
 
  return 0;
}
