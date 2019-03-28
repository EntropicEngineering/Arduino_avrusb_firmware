/*
             LUFA Library
     Copyright (C) Dean Camera, 2015.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2015  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  Header file for Arduino-usbserial.c.
 */

#ifndef _USB_SERIAL_H_
#define _USB_SERIAL_H_

/* Includes: */
#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <avr/power.h>

#include "Descriptors.h"

#include <LUFA/Drivers/Board/LEDs.h>
#include <LUFA/Drivers/Peripheral/Serial.h>
#include <LUFA/Drivers/Misc/RingBuffer.h>
#include <LUFA/Drivers/USB/USB.h>
#include <LUFA/Platform/Platform.h>

/* Macros: */
/** LED mask for the library LED driver, to indicate TX activity. */
#define LEDMASK_TX               LEDS_LED1

/** LED mask for the library LED driver, to indicate RX activity. */
#define LEDMASK_RX               LEDS_LED2

/** LED mask for the library LED driver, to indicate that an error has occurred in the USB interface. */
#define LEDMASK_ERROR            (LEDS_LED1 | LEDS_LED2)

/** LED mask for the library LED driver, to indicate that the USB interface is busy. */
#define LEDMASK_BUSY             (LEDS_LED1 | LEDS_LED2)

/* Type Defines: */
/** Type define for the Microsoft OS 2.0 Descriptor for the device. This must be defined in the
 *  application code as the descriptor may contain sub-descriptors which can vary between devices,
 *  and which identify which USB drivers Windows should use.
 */
typedef struct
{
    MS_OS_20_Descriptor_Set_Header_t        Header;
    MS_OS_20_CCGP_Device_Descriptor         CCGP_Device;
    MS_OS_20_Configuration_Subset_Header    Configuration1;
    MS_OS_20_Function_Subset_Header         WebUSB_Function;
    MS_OS_20_CompatibleID_Descriptor        CompatibleID;
} MS_OS_20_Descriptor_t;

/* Function Prototypes: */
void SetupHardware(void);

void EVENT_USB_Device_Connect(void);

void EVENT_USB_Device_Disconnect(void);

void EVENT_USB_Device_ConfigurationChanged(void);

void EVENT_USB_Device_ControlRequest(void);

void EVENT_CDC_Device_LineEncodingChanged(USB_ClassInfo_CDC_Device_t *const CDCInterfaceInfo);

void EVENT_CDC_Device_ControLineStateChanged(USB_ClassInfo_CDC_Device_t *const CDCInterfaceInfo);

#endif

