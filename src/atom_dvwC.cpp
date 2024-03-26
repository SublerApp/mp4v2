/*
 * The contents of this file are subject to the Mozilla Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 *
 * The Original Code is MPEG4IP.
 *
 * The Initial Developer of the Original Code is Cisco Systems Inc.
 * Portions created by Cisco Systems Inc. are
 * Copyright (C) Cisco Systems Inc. 2004.  All Rights Reserved.
 *
 * Contributor(s):
 *     Damiano Galassi
 */

#include "src/impl.h"

namespace mp4v2 {
namespace impl {

///////////////////////////////////////////////////////////////////////////////

MP4DvwCAtom::MP4DvwCAtom(MP4File &file)
        : MP4Atom(file, "dvwC")
{
    AddProperty( new MP4Integer8Property(*this,"dv_version_major")); /* 0 */
    AddProperty( new MP4Integer8Property(*this,"dv_version_minor")); /* 1 */
    AddProperty( new MP4BitfieldProperty(*this,"dv_profile", 7)); /* 2 */
    AddProperty( new MP4BitfieldProperty(*this,"dv_level", 6)); /* 3 */
    AddProperty( new MP4BitfieldProperty(*this,"rpu_present_flag", 1)); /* 4 */
    AddProperty( new MP4BitfieldProperty(*this,"el_present_flag", 1)); /* 5 */
    AddProperty( new MP4BitfieldProperty(*this,"bl_present_flag", 1)); /* 6 */
    AddProperty( new MP4BitfieldProperty(*this,"dv_bl_signal_compatibility_id", 4)); /* 7 */
    AddProperty( new MP4BitfieldProperty(*this,"reserved1", 28)); /* 8 */
    AddReserved(*this, "reserved2", 16); /* 9 */
}

void MP4DvwCAtom::Generate()
{
    MP4Atom::Generate();
}

///////////////////////////////////////////////////////////////////////////////

}
} // namespace mp4v2::impl
