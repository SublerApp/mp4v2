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
 *      Damiano Galassi     damiog@gmail.com
 */

#include "src/impl.h"

namespace mp4v2 {
namespace impl {

///////////////////////////////////////////////////////////////////////////////

MP4TagcAtom::MP4TagcAtom(MP4File &file)
        : MP4Atom(file, "tagc")
{
       AddProperty( new MP4BytesProperty(*this,"tag", 0)); /* 0 */
}

void MP4TagcAtom::Read()
{
    // calculate size of the metadata from the atom size
    ((MP4BytesProperty*)m_pProperties[0])->SetValueSize(m_size);
    MP4Atom::Read();
}

/*void MP4TagcAtom::Dump(uint8_t indent, bool dumpImplicits)
{

}*/

///////////////////////////////////////////////////////////////////////////////

}
} // namespace mp4v2::impl
