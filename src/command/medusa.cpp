// Copyright (c) 2005-2010, Niels Martin Hansen
// Copyright (c) 2005-2010, Rodrigo Braz Monteiro
// Copyright (c) 2010, Amar Takhar
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//   * Neither the name of the Aegisub Group nor the names of its contributors
//     may be used to endorse or promote products derived from this software
//     without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Aegisub Project http://www.aegisub.org/
//
// $Id$

/// @file 
/// @brief 
/// @ingroup command
///

#include "config.h"

#ifndef AGI_PRE
#include <wx/window.h>
#endif

#include "aegisub/context.h"
#include "audio_timing.h"

namespace cmd {

void medusa_enter(agi::Context *c) {
	 /// @todo Figure out how to handle this in the audio controller
	//audioBox->audioDisplay->Prev(false);
}


void medusa_next(agi::Context *c) {
	/// @todo Figure out how to handle this in the audio controller
	//audioBox->audioDisplay->Next(false);
}


void medusa_play(agi::Context *c) {
	c->audioController->PlayPrimaryRange();
}


void medusa_play_after(agi::Context *c) {
	SampleRange sel(c->audioController->GetPrimaryPlaybackRange());
		c->audioController->PlayRange(SampleRange(
			sel.end(),
			sel.end() + c->audioController->SamplesFromMilliseconds(500)));;
}


void medusa_play_before(agi::Context *c) {
	SampleRange sel(c->audioController->GetPrimaryPlaybackRange());
		c->audioController->PlayRange(SampleRange(
			sel.begin() - c->audioController->SamplesFromMilliseconds(500),
			sel.begin()));;
}


void medusa_previous(agi::Context *c) {
	/// @todo Figure out how to handle this in the audio controller
	//audioBox->audioDisplay->Prev(false);
}


void medusa_shift_end_back(agi::Context *c) {
	SampleRange newsel(
		c->audioController->GetPrimaryPlaybackRange(),
		0,
		-c->audioController->SamplesFromMilliseconds(10));
	/// @todo Make this use the timing controller instead
	//audioController->SetSelection(newsel);
}


void medusa_shift_end_forward(agi::Context *c) {
	SampleRange newsel(
		c->audioController->GetPrimaryPlaybackRange(),
		0,
		c->audioController->SamplesFromMilliseconds(10));
	/// @todo Make this use the timing controller instead
	//audioController->SetSelection(newsel);
}


void medusa_shift_start_back(agi::Context *c) {
	SampleRange newsel(
		c->audioController->GetPrimaryPlaybackRange(),
		-c->audioController->SamplesFromMilliseconds(10),
		0);
	/// @todo Make this use the timing controller instead
	//audioController->SetSelection(newsel);
}


void medusa_shift_start_forward(agi::Context *c) {
	SampleRange newsel(
		c->audioController->GetPrimaryPlaybackRange(),
		c->audioController->SamplesFromMilliseconds(10),
		0);
	/// @todo Make this use the timing controller instead
	//audioController->SetSelection(newsel);
}


void medusa_stop(agi::Context *c) {
	// Playing, stop
	if (c->audioController->IsPlaying()) {
		c->audioController->Stop();
	} else {
		// Otherwise, play the last 500 ms
		SampleRange sel(c->audioController->GetPrimaryPlaybackRange());
			c->audioController->PlayRange(SampleRange(
				sel.end() - c->audioController->SamplesFromMilliseconds(500),
				sel.end()));;
	}
}


} // namespace cmd
