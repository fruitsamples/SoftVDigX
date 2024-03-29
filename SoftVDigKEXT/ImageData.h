/*
	File:		ImageData.h
	
	Description: 2vuy compressed frame data for SoftVDigX.

	Author:		DTS

	Copyright: 	� Copyright 2003 Apple Computer, Inc. All rights reserved.
	
	Disclaimer:	IMPORTANT:  This Apple software is supplied to you by Apple Computer, Inc.
				("Apple") in consideration of your agreement to the following terms, and your
				use, installation, modification or redistribution of this Apple software
				constitutes acceptance of these terms.  If you do not agree with these terms,
				please do not use, install, modify or redistribute this Apple software.

				In consideration of your agreement to abide by the following terms, and subject
				to these terms, Apple grants you a personal, non-exclusive license, under Apple�s
				copyrights in this original Apple software (the "Apple Software"), to use,
				reproduce, modify and redistribute the Apple Software, with or without
				modifications, in source and/or binary forms; provided that if you redistribute
				the Apple Software in its entirety and without modifications, you must retain
				this notice and the following text and disclaimers in all such redistributions of
				the Apple Software.  Neither the name, trademarks, service marks or logos of
				Apple Computer, Inc. may be used to endorse or promote products derived from the
				Apple Software without specific prior written permission from Apple.  Except as
				expressly stated in this notice, no other rights or licenses, express or implied,
				are granted by Apple herein, including but not limited to any patent rights that
				may be infringed by your derivative works or by other works in which the Apple
				Software may be incorporated.

				The Apple Software is provided by Apple on an "AS IS" basis.  APPLE MAKES NO
				WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED
				WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
				PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND OPERATION ALONE OR IN
				COMBINATION WITH YOUR PRODUCTS.

				IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL OR
				CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
				GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
				ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, MODIFICATION AND/OR DISTRIBUTION
				OF THE APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER THEORY OF CONTRACT, TORT
				(INCLUDING NEGLIGENCE), STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN
				ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
				
	Change History (most recent first):
	   <1>		07/23/03	dts		updated and initial release for X
*/

#ifndef	__IMAGEDATA_H__
	#define __IMAGEDATA_H__

#include "Images/ImageData_00.h"
#include "Images/ImageData_01.h"
#include "Images/ImageData_02.h"
#include "Images/ImageData_03.h"
#include "Images/ImageData_04.h"
#include "Images/ImageData_05.h"
#include "Images/ImageData_06.h"
#include "Images/ImageData_07.h"
#include "Images/ImageData_08.h"
#include "Images/ImageData_09.h"
#include "Images/ImageData_10.h"
#include "Images/ImageData_11.h"
#include "Images/ImageData_12.h"
#include "Images/ImageData_13.h"
#include "Images/ImageData_14.h"
#include "Images/ImageData_15.h"
#include "Images/ImageData_16.h"
#include "Images/ImageData_17.h"
#include "Images/ImageData_18.h"
#include "Images/ImageData_19.h"
#include "Images/ImageData_20.h"
#include "Images/ImageData_21.h"
#include "Images/ImageData_22.h"
#include "Images/ImageData_23.h"
#include "Images/ImageData_24.h"
#include "Images/ImageData_25.h"
#include "Images/ImageData_26.h"
#include "Images/ImageData_27.h"
#include "Images/ImageData_28.h"
#include "Images/ImageData_29.h"

unsigned char* frame[] = {
        frame_00,
        frame_01,
        frame_02,
        frame_03,
        frame_04,
        frame_05,
        frame_06,
        frame_07,
        frame_08,
        frame_09,
        frame_10,
        frame_11,
        frame_12,
        frame_13,
        frame_14,
        frame_15,
        frame_16,
        frame_17,
        frame_18,
        frame_19,
        frame_20,
        frame_21,
        frame_22,
        frame_23,
        frame_24,
        frame_25,
        frame_26,
        frame_27,
        frame_28,
        frame_29
};

#define	NUM_FRAMES (sizeof(frame) / sizeof(char*))

#define IMAGE_HEIGHT 240
#define IMAGE_WIDTH	 320

#endif __IMAGEDATA_H__