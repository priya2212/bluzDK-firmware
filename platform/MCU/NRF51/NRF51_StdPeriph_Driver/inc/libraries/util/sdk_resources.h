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

/** @file
 * @brief Definition file for resource usage by SoftDevice, ESB and Gazell.
 */

#ifndef APP_RESOURCES_H__
#define APP_RESOURCES_H__

#ifdef SOFTDEVICE_PRESENT
	#include "nrf_sd_def.h"
#else
	#define SD_PPI_RESTRICTED	      0uL /**< 1 if PPI peripheral is restricted, 0 otherwise. */
	#define SD_PPI_CHANNELS_USED      0uL /**< PPI channels utilized by SotfDevice (not available to th spplication). */
	#define SD_PPI_GROUPS_USED        0uL /**< PPI groups utilized by SotfDevice (not available to th spplication). */
	#define SD_TIMERS_USED            0uL /**< Timers used by SoftDevice. */
	#define SD_SWI_USED               0uL /**< Software interrupts used by SoftDevice. */
#endif

#ifdef GAZELL_PRESENT
	#include "nrf_gzll_resources.h"
#else
	#define GZLL_PPI_CHANNELS_USED    0uL /**< PPI channels utilized by Gazell (not available to th spplication). */
	#define GZLL_TIMERS_USED          0uL /**< Timers used by Gazell. */
	#define GZLL_SWI_USED             0uL /**< Software interrupts used by Gazell */
#endif

#ifdef ESB_PRESENT
	#include "nrf_esb_resources.h"
#else
	#define ESB_PPI_CHANNELS_USED    0uL /**< PPI channels utilized by ESB (not available to th spplication). */
	#define ESB_TIMERS_USED          0uL /**< Timers used by ESB. */
	#define ESB_SWI_USED             0uL /**< Software interrupts used by ESB */
#endif


#define NRF_PPI_RESTRICTED	  (SD_PPI_RESTRICTED)
#define NRF_PPI_CHANNELS_USED (SD_PPI_CHANNELS_USED | GZLL_PPI_CHANNELS_USED | ESB_PPI_CHANNELS_USED)
#define NRF_PPI_GROUPS_USED   (SD_PPI_GROUPS_USED)
#define NRF_SWI_USED          (SD_SWI_USED | GZLL_SWI_USED | ESB_SWI_USED)
#define NRF_TIMERS_USED       (SD_TIMERS_USED | GZLL_TIMERS_USED | ESB_TIMERS_USED)

#endif // APP_RESOURCES_H__
