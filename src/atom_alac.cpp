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
 * Contributor(s):
 *      Edward Groenendaal      egroenen@cisco.com
 */

#include "src/impl.h"

namespace mp4v2 {
namespace impl {

///////////////////////////////////////////////////////////////////////////////


MP4ALACAtom::MP4ALACAtom(MP4File &file)
        : MP4Atom(file, "alac")
{
    AddProperty( /* 0 */
                new MP4Integer32Property(*this,"VersionFlags"));
}

void MP4ALACAtom::Generate()
{
    AddProperty( /* 1 */
                new MP4BytesProperty(*this,"AppleLosslessMagicCookie", 48));

    MP4Atom::Generate();
}

void MP4ALACAtom::Read()
{
    AddProperty( /* 1 */
                new MP4BytesProperty(*this,"AppleLosslessMagicCookie", m_size - 4));
    MP4Atom::Read();

}
///////////////////////////////////////////////////////////////////////////////

}
} // namespace mp4v2::impl
