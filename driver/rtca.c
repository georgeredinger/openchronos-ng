/*
    rtca.c: TI CC430 Hardware Realtime Clock (RTC_A)
 
    Copyright (C) 2011 Angelo Arrifano <miknix@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "rtca.h"

void rtca_init()
{
	// Enable calendar mode (date/time registers are automatically reset)
	RTCCTL01 |= RTCMODE;

	// Enable the RTC
	RTCCTL01 &= ~RTCHOLD;
}

void rtca_get_time(u8 *hour, u8 *min, u8 *sec)
{
	*sec = RTCSEC;
	*min = RTCMIN;
	*hour = RTCHOUR;
}

void rtca_set_time(u8 hour, u8 min, u8 sec)
{
	RTCSEC = sec;
	RTCMIN = min;
	RTCHOUR = hour;
}

void rtca_get_date(u16 *year, u8 *mon, u8 *day, u8 *dow)
{
	*dow = RTCDOW;
	*day = RTCDAY;
	*mon = RTCMON;
	*year = RTCYEARL | (RTCYEARH << 8);
}

void rtca_set_date(u16 year, u8 mon, u8 day, u8 dow)
{
	RTCDOW = dow;
	RTCDAY = day;
	RTCMON = mon;
	RTCYEARL = year & 0xff;
	RTCYEARH = year >> 8;
}

