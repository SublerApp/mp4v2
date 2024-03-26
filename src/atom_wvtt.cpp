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
 * Copyright (C) Cisco Systems Inc. 2001.  All Rights Reserved.
 */

#include "src/impl.h"

namespace mp4v2 {
namespace impl {

///////////////////////////////////////////////////////////////////////////////

MP4WvttAtom::MP4WvttAtom(MP4File &file)
        : MP4Atom(file, "wvtt")
{
    AddReserved(*this, "reserved1", 4); /* 0 */
    AddReserved(*this, "reserved2", 2); /* 1 */

    AddProperty(new MP4Integer16Property(*this, "dataReferenceIndex")); /* 2 */

    ExpectChildAtom("vttC", Required, OnlyOne);
}

void MP4WvttAtom::Generate()
{
    // generate children
    MP4Atom::Generate();

    ((MP4Integer16Property*)m_pProperties[2])->SetValue(1);
}

///////////////////////////////////////////////////////////////////////////////

}
} // namespace mp4v2::impl
