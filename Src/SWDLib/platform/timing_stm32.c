/*
 * This file is part of the Black Magic Debug project.
 *
 * Copyright (C) 2015 Gareth McMullin <gareth@blacksphere.co.nz>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "general.h"
#include "morse.h"
#include "stm32f4xx_hal.h"

//typedef platform_timeout uint32_t;

extern __IO uint32_t uwTick;

uint8_t running_status;
static volatile uint32_t time_ms;

void platform_timing_init(void)
{
	//Already Done with STM32CubeMX System Init Sequence.
	/*
	// Setup heartbeat timer
	systick_set_clocksource(STK_CSR_CLKSOURCE_AHB_DIV8);
	systick_set_reload(900000);	// Interrupt us at 10 Hz
	SCB_SHPR(11) &= ~((15 << 4) & 0xff);
	SCB_SHPR(11) |= ((14 << 4) & 0xff);
	systick_interrupt_enable();
	systick_counter_enable();
	*/
}

void platform_delay(uint32_t ms)
{
	platform_timeout timeout;
	platform_timeout_set(&timeout, ms);
	while (!platform_timeout_is_expired(&timeout));
}

void platform_delay_swd(uint32_t us)
{
	for(uint32_t i=0; i < us; i++)
	{
		__nop();
		__nop();
		__nop();
		__nop();
	}
}

void sys_tick_handler(void)
{
	/*
	if(running_status)
		gpio_toggle(LED_PORT, LED_IDLE_RUN);

	time_ms += 100;

	SET_ERROR_STATE(morse_update());
	*/
	//Should In SysTick_Handler at stm32f4xx_it.c
}

uint32_t platform_time_ms(void)
{
	return uwTick;
}
