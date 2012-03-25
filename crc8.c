/*******************************************************************************
 *                                                                             *
 *                            8 bit CRC Calculation                            *
 *                                                                             *
 *                                   crc8.c                                    *
 *                                                                             *
 *                                   Module                                    *
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


unsigned char crc8_table[256]; /* 8-bit crc table */


/******************************************************************************
*
* Create an 8-bit crc table from the polynomial x^8 + x^2 + x + 1  ~ 0x07
*
******************************************************************************/
void init_crc8()
{
	int i;
	int j;
	unsigned char crc;

	for (i=0; i<256; i++) {
		crc = i;
		for (j=0; j<8; j++) {
			crc = (crc << 1) ^ ((crc & 0x80) ? 0x07 : 0);
		}
		crc8_table[i] = crc & 0xFF;
     	}
}
