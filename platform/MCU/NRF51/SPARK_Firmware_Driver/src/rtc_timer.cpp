/**
 Copyright (c) 2015 MidAir Technology, LLC.  All rights reserved.
 Copyright (c) 2016 Bryan J. Rentoul (aka Gruvin).  All rights reserved.
 
 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation, either
 version 3 of the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

/* Includes -----------------------------------------------------------------*/
#include "rtc_timer.h"

/* Private typedef ----------------------------------------------------------*/

/* Private define -----------------------------------------------------------*/
#define MAX_RTC_TIMERS (APP_TIMER_MAX_TIMERS-1)

/* Private macro ------------------------------------------------------------*/

/* Private variables --------------------------------------------------------*/

/* Extern variables ---------------------------------------------------------*/

/* Private function prototypes ----------------------------------------------*/

RTCTimer::RTCTimer(uint32_t interval, app_timer_timeout_handler_t callback )
{
  this->_init();
  this->callbackFunc = callback;
  this->timerInterval = interval;
  if (0 == app_timer_create( &this->timerID, APP_TIMER_MODE_REPEATED, this->callbackFunc) )
  {
    app_timer_start(this->timerID, this->timerInterval, this->callbackContextPointer);
  }
};

RTCTimer::RTCTimer(uint32_t interval, app_timer_timeout_handler_t callback, bool oneshot = true)
{
  this->_init();
  callbackFunc = callback;
  this->timerInterval = interval;
  if (0 == app_timer_create( &this->timerID, APP_TIMER_MODE_SINGLE_SHOT, this->callbackFunc) )
  {
    app_timer_start(this->timerID, this->timerInterval, this->callbackContextPointer);
  }
};

void RTCTimer::_init() 
{ 
  this->callbackFunc = (app_timer_timeout_handler_t)0x00; 
  this->callbackContextPointer = (void *)0x00;
};

void RTCTimer::start()
{
  if (callbackFunc) {
     app_timer_start(this->timerID, this->timerInterval, this->callbackContextPointer);
  }
};

void RTCTimer::stop()
{
  app_timer_stop(this->timerID);
};

void RTCTimer::changePeriod()
{
};

void RTCTimer::dispose()
{
};

bool RTCTimer::isActive()
{
  return false;
};

