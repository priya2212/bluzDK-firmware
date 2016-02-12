/*
 * Copyright (c) Nordic Semiconductor ASA
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 *   3. Neither the name of Nordic Semiconductor ASA nor the names of other
 *   contributors to this software may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef NRF_DRV_CONFIG_H
#define NRF_DRV_CONFIG_H

/* CLOCK */
#define CLOCK_CONFIG_XTAL_FREQ          NRF_CLOCK_XTALFREQ_16MHz
#define CLOCK_CONFIG_LF_SRC             NRF_CLOCK_LF_SRC_Xtal
#define CLOCK_CONFIG_LF_RC_CAL_INTERVAL RC_2000MS_CALIBRATION_INTERVAL
#define CLOCK_CONFIG_IRQ_PRIORITY       APP_IRQ_PRIORITY_LOW

/* GPIOTE */
#define GPIOTE_ENABLED 1

#if (GPIOTE_ENABLED == 1)
#define GPIOTE_CONFIG_USE_SWI_EGU false
#define GPIOTE_CONFIG_IRQ_PRIORITY APP_IRQ_PRIORITY_HIGH
#define GPIOTE_CONFIG_NUM_OF_LOW_POWER_EVENTS 1
#endif

/* TIMER */
#define TIMER0_ENABLED 0

#if (TIMER0_ENABLED == 1)
#define TIMER0_CONFIG_FREQUENCY    NRF_TIMER_FREQ_16MHz
#define TIMER0_CONFIG_MODE         TIMER_MODE_MODE_Timer
#define TIMER0_CONFIG_BIT_WIDTH    TIMER_BITMODE_BITMODE_32Bit
#define TIMER0_CONFIG_IRQ_PRIORITY APP_IRQ_PRIORITY_LOW

#define TIMER0_INSTANCE_INDEX      0
#endif

#define TIMER1_ENABLED 1

#if (TIMER1_ENABLED == 1)
#define TIMER1_CONFIG_FREQUENCY    NRF_TIMER_FREQ_16MHz
#define TIMER1_CONFIG_MODE         TIMER_MODE_MODE_Timer
#define TIMER1_CONFIG_BIT_WIDTH    TIMER_BITMODE_BITMODE_16Bit
#define TIMER1_CONFIG_IRQ_PRIORITY APP_IRQ_PRIORITY_LOW
#define TIMER1_INSTANCE_INDEX      (TIMER0_ENABLED)
#endif
 
#define TIMER2_ENABLED 0

#if (TIMER2_ENABLED == 1)
#define TIMER2_CONFIG_FREQUENCY    NRF_TIMER_FREQ_16MHz
#define TIMER2_CONFIG_MODE         TIMER_MODE_MODE_Timer
#define TIMER2_CONFIG_BIT_WIDTH    TIMER_BITMODE_BITMODE_16Bit
#define TIMER2_CONFIG_IRQ_PRIORITY APP_IRQ_PRIORITY_LOW

#define TIMER2_INSTANCE_INDEX      (TIMER1_ENABLED+TIMER0_ENABLED)
#endif

#define TIMER_COUNT (TIMER0_ENABLED + TIMER1_ENABLED + TIMER2_ENABLED)

/* RTC */
#define RTC0_ENABLED 0

#if (RTC0_ENABLED == 1)
#define RTC0_CONFIG_FREQUENCY    32678
#define RTC0_CONFIG_IRQ_PRIORITY APP_IRQ_PRIORITY_LOW
#define RTC0_CONFIG_RELIABLE     false

#define RTC0_INSTANCE_INDEX      0
#endif

#define RTC1_ENABLED 0

#if (RTC1_ENABLED == 1)
#define RTC1_CONFIG_FREQUENCY    32768
#define RTC1_CONFIG_IRQ_PRIORITY APP_IRQ_PRIORITY_LOW
#define RTC1_CONFIG_RELIABLE     false

#define RTC1_INSTANCE_INDEX      (RTC0_ENABLED)
#endif

#define RTC_COUNT                (RTC0_ENABLED+RTC1_ENABLED)

#define NRF_MAXIMUM_LATENCY_US 2000

/* RNG */
#define RNG_ENABLED 0

#if (RNG_ENABLED == 1)
#define RNG_CONFIG_ERROR_CORRECTION true
#define RNG_CONFIG_POOL_SIZE        8
#define RNG_CONFIG_IRQ_PRIORITY     APP_IRQ_PRIORITY_LOW
#endif

/* TWI */
#define TWI0_ENABLED 1

#if (TWI0_ENABLED == 1)
#define TWI0_CONFIG_FREQUENCY    NRF_TWI_FREQ_100K
#define TWI0_CONFIG_SDA  21
#define TWI0_CONFIG_SCL  22
#define TWI0_CONFIG_IRQ_PRIORITY APP_IRQ_PRIORITY_LOW

#define TWI0_INSTANCE_INDEX      0
#endif

#define TWI1_ENABLED 0
#if (TWI1_ENABLED == 1)
#define TWI1_CONFIG_FREQUENCY NRF_TWI_FREQ_100K
#define TWI1_CONFIG_SDA  0
#define TWI1_CONFIG_SCL  1
#define TWI1_CONFIG_IRQ_PRIORITY APP_IRQ_PRIORITY_LOW

#define TWI1_INSTANCE_INDEX      (TWI0_ENABLED)
#endif

#define TWI_COUNT                (TWI0_ENABLED+TWI1_ENABLED)


/* QDEC */
#define QDEC_ENABLED 0

#if (QDEC_ENABLED == 1)
#define QDEC_CONFIG_REPORTPER    NRF_QDEC_REPORTPER_10
#define QDEC_CONFIG_SAMPLEPER    NRF_QDEC_SAMPLEPER_16384us
#define QDEC_CONFIG_PIO_A        1
#define QDEC_CONFIG_PIO_B        2
#define QDEC_CONFIG_PIO_LED      3
#define QDEC_CONFIG_LEDPRE       511
#define QDEC_CONFIG_LEDPOL       NRF_QDEC_LEPOL_ACTIVE_HIGH
#define QDEC_CONFIG_IRQ_PRIORITY APP_IRQ_PRIORITY_LOW
#define QDEC_CONFIG_DBFEN        false
#define QDEC_CONFIG_SAMPLE_INTEN false
#endif

/* LPCOMP */
#define LPCOMP_ENABLED 0

#if (LPCOMP_ENABLED == 1)
#define LPCOMP_CONFIG_REFERENCE    NRF_LPCOMP_REF_SUPPLY_FOUR_EIGHT
#define LPCOMP_CONFIG_DETECTION    NRF_LPCOMP_DETECT_DOWN
#define LPCOMP_CONFIG_IRQ_PRIORITY APP_IRQ_PRIORITY_LOW
#define LPCOMP_CONFIG_INPUT        NRF_LPCOMP_INPUT_0
#endif

/* WDT */
#define WDT_ENABLED 0

#if (WDT_ENABLED == 1)
#define WDT_CONFIG_BEHAVIOUR     NRF_WDT_BEHAVIOUR_RUN_SLEEP
#define WDT_CONFIG_RELOAD_VALUE  2000
#define WDT_CONFIG_IRQ_PRIORITY  APP_IRQ_PRIORITY_HIGH
#endif

#endif // NRF_DRV_CONFIG_H