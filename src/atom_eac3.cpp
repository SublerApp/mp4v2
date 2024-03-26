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
 *
 * See ETSI TS 102 366 V1.2.1 Annex F for how to put E-Ac3 in MP4.
 * 
 * Contributor(s):
 *      Damiano Galassi			damiog@gmail.com
 */

#include "src/impl.h"

namespace mp4v2 {
namespace impl {

///////////////////////////////////////////////////////////////////////////////

MP4EAc3Atom::MP4EAc3Atom(MP4File &file)
        : MP4Atom(file, "ec-3")
{
    AddReserved(*this, "reserved1", 6); /* 0 */

    AddProperty( /* 1 */
        new MP4Integer16Property(*this,"dataReferenceIndex"));

    AddReserved(*this,"reserved2", 8); /* 2 */

    AddProperty( /* 3 */
        new MP4Integer16Property(*this,"channelCount"));

    AddProperty( /* 4 */
        new MP4Integer16Property(*this,"sampleSize"));

    AddReserved(*this,"reserved3", 4); /* 5 */

    AddProperty( /* 6 */
        new MP4Integer16Property(*this,"samplingRate"));

    AddReserved(*this,"reserved4", 2); /* 7 */

    ExpectChildAtom("dec3", Required, OnlyOne);
}

void MP4EAc3Atom::Generate()
{
    MP4Atom::Generate();

    ((MP4Integer16Property*)m_pProperties[1])->SetValue(1); // data-reference-index
    ((MP4Integer16Property*)m_pProperties[3])->SetValue(2); // channelCount - ignored
    ((MP4Integer16Property*)m_pProperties[4])->SetValue(0x0010); // sampleSize - ignored

    // The user should set the samplingRate as appropriate - and create the dec3 atom
}

///////////////////////////////////////////////////////////////////////////////

}
} // namespace mp4v2::impl
