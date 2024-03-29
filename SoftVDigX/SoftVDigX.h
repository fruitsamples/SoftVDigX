/*
	File:		SoftVDigX.h
	
	Description: QuickTime Compressed Source VDig for MacOS X.

	Author:		QuickTime Engineering, DTS

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

//-----------------------------------------------------------------------
// includes

#ifndef	_SOFTVDIGX_
	#define	_SOFTVDIGX_

#include <QuickTime/QuickTimeComponents.h>

#define		kMaxSoftVDigXCount  	1			// how many can be open at once
#define		kVideoTimeScale  		2997		// time scale
#define     kBestFramesPerSecond    30 << 16	// 30.00 fixed	

// globals
// we don't use all of these but generally a good place to start
typedef struct {
	ComponentInstance		self;				// this instance
	Rect					maxSrcRect;			// for VDGetMaxSrcRect
	Rect					digiRect;			// part of frame to use 
	MatrixRecord			matrix;				// display matrix
	char					deviceName[33];
	OSType					compressType;
	short					compressDepth;
	Rect					compressRect;
	CodecQ					spatialQuality;	
	CodecQ					temporalQuality;
	long					keyFrameRate;
	ImageDescriptionHandle	desc;
	Boolean					compressOn;
	TimeBase				timeBase;
	Fixed					framesPerSecond;
	TimeRecord				frameTime;
	Boolean					frameTimeValid;
	TimeValue				nextFrameTime;		// next time if doing frame rate limiting
	TimeValue				frameTimeStep;		// increment for stepping, non-zero means do limiting
	TimeRecord				atTime;
	TimeCodeDef				timeCodeFormat;
	TimeCodeTime			timeCodeTime;
	long					inputCurrentFlags;
	long					outputCurrentFlags;
	UInt32					captureState;
	unsigned short			blackLevel;
	unsigned short			whiteLevel;
	unsigned short			brightness;
	unsigned short			hue;
	unsigned short			saturation;
	unsigned short			contrast;
	unsigned short			sharpness;
        
	// kext things
	io_connect_t			userClient;	// the connection to our userclient
	vm_address_t			framePtr;	// pointer to frame memory buffer from IOConnectMapMemory
	vm_size_t				frameSize;	// frame memory size from IOConnectMapMemory
	
} SoftVDigXGlobalsRecord, *SoftVDigXGlobalsPtr, **SoftVDigXGlobals;

#endif _SOFTVDIGX_