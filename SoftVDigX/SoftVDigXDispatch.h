/*
	File:		SoftVDigXDispatch.h
	
	Description: QuickTime Compressed Source VDig for MacOS X
	
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
	   <1>		07/23/03	dts 	updated and initial release for X
*/

/*	A Quick Course in ComponentDispatchHelper.c

		ComponentRangeCount
		The number (0 based) of discrete, continuous ranges of selectors that are used in the macro.  The
		'range shift' & 'range mask' determine the size of the range.

		ComponentRangeShift
		ComponentRangeMask
		The mask == 2^shift -1.  This is used to define size of the range of selectors.

		For ImageCodecs as an example, the ranges are in size of 0x100:
		
		   Range 0 = -0xFF to -0x01 	Standard Component Calls
		   Range 1 = 0x000 to 0x0FF		Generic codecs 
		   Range 2 = 0x100 to 0x1FF		Specific to QT Photo JPEG codecs
		   Range 3 = 0x200 to 0x2FF		Base Decompressor Client codecs
		   Range 4 = 0x300 to 0x3FF		Effect codecs
			
		ComponentRangeBegin & ComponentRangeEnd
		Use these macros to bracket the start/stop of each range of selectors.  First range use (0), for the Nth
		range use (N-1).

		ComponentRangeUnused
		Used to skip a range of selectors.

		ComponentSelectorOffset
		Since the 'default' selectors are negative numbers, an offset must be specified.  For example, if the first
		default selector supported was kComponentUnregisterSelect (-7), then the offset would have to be 7.

		StdComponentCall
		Used to dispatch to one of the standard compoenent routines, such as Open(), Close(), Register(), etc. that
		are implemented in the component.

		ComponentError
		Returns an error without trying to do anything.  Use this for the selectors that will NEVER be implmented
		or delegated.  Additionally, it can be used to fill in a 'blank' in a range of selectors to get the range
		continuous. For example, if there were selectors that corresponded to 10,11,12, 14, but NO 13, merely put
		ComponentError (0) between the selectors for 12 & 14.
		
		ComponentNoError
		Returns 'noErr' without trying to do anything.

		ComponentDelegate
		Delagates the call to the specified delagate component.

		ComponentCall
		This dispatches to the appropriate routine in that is implemented in the component.

		ComponentComment
		Allows comments to be placed in the big macro.
*/

	ComponentComment ("SoftVDigXDispatch.h for SoftVDigX")

	ComponentSelectorOffset (4)

	ComponentRangeCount (1)
	ComponentRangeShift (8)
	ComponentRangeMask	(FF)

	ComponentStorageType (Ptr)

ComponentComment("Standard Component Range")

	ComponentRangeBegin (0)
		StdComponentCall	(Version)
		StdComponentCall	(CanDo)
		StdComponentCall	(Close)
		StdComponentCall	(Open)
	ComponentRangeEnd (0)
	
ComponentComment("Video Digitizer Component Range")

	ComponentRangeBegin (1)
		ComponentError	(0)
		
			ComponentCall	(GetMaxSrcRect)
			ComponentCall	(GetActiveSrcRect)
			ComponentCall	(SetDigitizerRect)
			ComponentCall	(GetDigitizerRect)
			ComponentCall	(GetVBlankRect)
		
		ComponentError	(GetMaskPixMap)				// not used for Compressed Source ignore
		ComponentError	(0x0007)
		ComponentError	(GetPlayThruDestination)	// not used for Compressed Source ignore
		ComponentError	(UseThisCLUT)				// not used for Compressed Source ignore
		ComponentError	(SetInputGammaValue)		// not called directly by Sequence Grabber QT6.3
		ComponentError	(GetInputGammaValue)		// not called directly by Sequence Grabber QT6.3
		
			ComponentCall	(SetBrightness)
			ComponentCall	(GetBrightness)
			ComponentCall	(SetContrast)
			ComponentCall	(SetHue)
			ComponentCall	(SetSharpness)
			ComponentCall	(SetSaturation)
			ComponentCall	(GetContrast)
			ComponentCall	(GetHue)
			ComponentCall	(GetSharpness)
			ComponentCall	(GetSaturation)
		
		ComponentError	(GrabOneFrame)				// not used for Compressed Source ignore
		ComponentError	(GetMaxAuxBuffer)			// not used for Compressed Source ignore
		ComponentError	(0x0018)					// private
					
			ComponentCall	(GetDigitizerInfo)
			ComponentCall	(GetCurrentFlags)
		
		ComponentError	(SetKeyColor)				// not called directly by Sequence Grabber QT6.3
		ComponentError	(GetKeyColor)				// not called unless vdTypeKey
		ComponentError	(AddKeyColor)				// not called directly by Sequence Grabber QT6.3
		ComponentError	(GetNextKeyColor)			// not called directly by Sequence Grabber QT6.3
		ComponentError	(SetKeyColorRange)			// not called directly by Sequence Grabber QT6.3
		ComponentError	(GetKeyColorRange)			// not called directly by Sequence Grabber QT6.3
		ComponentError	(SetDigitizerUserInterrupt)	// not used
		ComponentError	(SetInputColorSpaceMode)	// not called directly by Sequence Grabber QT6.3
		ComponentError	(GetInputColorSpaceMode)	// not called directly by Sequence Grabber QT6.3
		ComponentError	(SetClipState)
		ComponentError	(GetClipState)
		ComponentError	(SetClipRgn)
		ComponentError	(ClearClipRgn)
		ComponentError	(GetCLUTInUse)				// not called directly by Sequence Grabber QT6.3
		
			ComponentCall	(SetPLLFilterType)		// called by Video Source Panel if implemented
			ComponentCall	(GetPLLFilterType)		// called by Video Source Panel if implemented
			
		ComponentError	(GetMaskandValue)			// not called unless vdTypeAlpha
		ComponentError	(SetMasterBlendLevel)		// not called directly by Sequence Grabber QT6.3
		ComponentError	(SetPlayThruDestination)	// not used for Compressed Source ignore
		ComponentError	(SetPlayThruOnOff)			// not used for Compressed Source ignore
		ComponentError	(SetFieldPreference)		// not called directly by Sequence Grabber QT6.3
		ComponentError	(GetFieldPreference)		// not called directly by Sequence Grabber QT6.3
		ComponentError	(0x0031)					// private
		ComponentError	(PreflightDestination)		// not used for Compressed Source ignore
		ComponentError	(PreflightGlobalRect)		// not used for Compressed Source ignore
		ComponentError	(SetPlayThruGlobalRect)		// not used for Compressed Source ignore
		ComponentError	(SetInputGammaRecord)		// not called directly by Sequence Grabber QT6.3
		ComponentError	(GetInputGammaRecord)		// not called directly by Sequence Grabber QT6.3
		
			ComponentCall	(SetBlackLevelValue)
			ComponentCall	(GetBlackLevelValue)
			ComponentCall	(SetWhiteLevelValue)
			ComponentCall	(GetWhiteLevelValue)
			ComponentCall	(GetVideoDefaults)
			ComponentCall	(GetNumberOfInputs)
			ComponentCall	(GetInputFormat)
			ComponentCall	(SetInput)
			ComponentCall	(GetInput)
			ComponentCall	(SetInputStandard)
		
		ComponentError	(SetupBuffers)				// not used for Compressed Source ignore
		ComponentError	(GrabOneFrameAsync)			// not used for Compressed Source ignore
		ComponentError	(Done)						// not used for Compressed Source ignore
		
			// these are required selectors for Compress Source
			// other Grab and PlayThru related selectors are no longer
			// applicable on MacOS X and should be ignored
			ComponentCall	(SetCompression)
			ComponentCall	(CompressOneFrameAsync)
			ComponentCall	(CompressDone)
			ComponentCall	(ReleaseCompressBuffer)
			ComponentCall	(GetImageDescription)
			ComponentCall	(ResetCompressSequence)
			ComponentCall	(SetCompressionOnOff)
			ComponentCall	(GetCompressionTypes)
			ComponentCall	(SetTimeBase)
			ComponentCall	(SetFrameRate)
			ComponentCall	(GetDataRate)
		
		ComponentError	(GetSoundInputDriver)
		ComponentError	(GetDMADepths)					// not used for Compressed Source ignore
				
			ComponentCall	(GetPreferredTimeScale)
		
		ComponentError	(ReleaseAsyncBuffers)			// not used for Compressed Source ignore
		ComponentError	(0x0053)
		
			ComponentCall	(SetDataRate)
			ComponentCall	(GetTimeCode)
			
		ComponentError	(UseSafeBuffers)				// not used for Compressed Source ignore
		ComponentError	(GetSoundInputSource)
		
			ComponentCall	(GetCompressionTime)
		
		ComponentError	(SetPreferredPacketSize)
		ComponentError	(SetPreferredImageDimensions)	// not called directly by Sequence Grabber QT6.3
		
			ComponentCall	(GetPreferredImageDimensions)
			ComponentCall	(GetInputName)
		
		ComponentError	(SetDestinationPort)			// not used for Compressed Source ignore
		
			ComponentCall	(GetDeviceNameAndFlags)
			ComponentCall	(CaptureStateChanging)
			ComponentCall	(GetUniqueIDs)
			ComponentCall	(SelectUniqueIDs)
	ComponentRangeEnd (1)