/**
 * \file hal.c
 *
 * \brief ATmega256rfr2 HAL implementation
 *
 * Copyright (C) 2012-2014, Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 * Modification and other use of this code is subject to Atmel's Limited
 * License Agreement (license.txt).
 *
 * $Id: hal.c 9267 2014-03-18 21:46:19Z ataradov $
 *
 */

/*- Includes ---------------------------------------------------------------*/
#include "sysTypes.h"
#include "hal.h"
#include "halTimer.h"

/*- Implementations --------------------------------------------------------*/

/*************************************************************************//**
*****************************************************************************/
void HAL_Init(void)
{
  MCUSR = 0;//PUM is 0, pull up can be enabled
  wdt_disable();

  CLKPR = 1 << CLKPCE;
  CLKPR = 0;

  SYS_EnableInterrupts();

  HAL_TimerInit();
  PORTA=0xFF;//enable all pull-up resisters at input mode
  PORTB=0xFF;
  PORTC=0xFF;
  PORTD=0xFF;
  PORTE=0xFF;
  PORTF=0xFF;
  PORTG=0xFF;

  HAL_GPIO_LED_out(); //Configure PB4 as a digital output pin
  HAL_GPIO_LED_set(); //Set PB4 to '1' (LED off)
  
  

}



/*************************************************************************//**
*****************************************************************************/
void HAL_Delay(uint8_t us)
{
  HAL_TimerDelay(us);
}
