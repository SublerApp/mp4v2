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
 *      Dave Mackie     dmackie@cisco.com
 */

#include "src/impl.h"

namespace mp4v2 {
namespace impl {

///////////////////////////////////////////////////////////////////////////////

MP4SbgpAtom::MP4SbgpAtom(MP4File &file)
        : MP4Atom(file, "sbgp")
{
    AddVersionAndFlags();
    AddProperty( /* 3 */ new MP4Integer32Property(*this,"groupingType"));
}

void MP4SbgpAtom::AddProperties(uint8_t version)
{	
    if (version == 1) {
    	AddProperty( /* 4 */ new MP4Integer32Property(*this,"groupingTypeParameter"));
    }

    MP4Integer32Property* pCount = new MP4Integer32Property(*this, "entryCount");
    AddProperty(pCount);

    MP4TableProperty* pTable = new MP4TableProperty(*this, "entries", pCount);
    AddProperty(pTable);

    pTable->AddProperty(new MP4Integer32Property(pTable->GetParentAtom(), "sampleCount"));
    pTable->AddProperty(new MP4Integer32Property(pTable->GetParentAtom(), "groupDescriptionIndex"));
}

void MP4SbgpAtom::Generate()
{
    SetVersion(0);
    AddProperties(GetVersion());

    MP4Atom::Generate();
}

void MP4SbgpAtom::Read()
{
    /* read atom version */
    ReadProperties(0, 1);

    /* need to create the properties based on the atom version */
    AddProperties(GetVersion());

    /* now we can read the remaining properties */
    ReadProperties(1);
}

///////////////////////////////////////////////////////////////////////////////

}
} // namespace mp4v2::impl
