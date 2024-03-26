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

/*
 * SizeTableProperty is a special version of the MP4TableProperty -
 * the BytesProperty will need to set the value before it can read
 * from the file
 */
class SizeTableProperty : public MP4TableProperty
{
public:
    SizeTableProperty(MP4Atom& parentAtom, const char *name, MP4IntegerProperty *pCountProperty) :
            MP4TableProperty(parentAtom, name, pCountProperty) {};
protected:
    void ReadEntry(MP4File& file, uint32_t index) {
        // Each table has a size, followed by the length field
        // first, read the length
        m_pProperties[0]->Read(file, index);
        MP4IntegerProperty *pIntProp = (MP4IntegerProperty *)m_pProperties[0];
        // set the size in the bytes property
        MP4BytesProperty *pBytesProp = (MP4BytesProperty *)m_pProperties[1];
        pBytesProp->SetValueSize(pIntProp->GetValue(index), index);
        // And read the bytes
        m_pProperties[1]->Read(file, index);
    };
private:
    SizeTableProperty();
    SizeTableProperty ( const SizeTableProperty &src );
    SizeTableProperty &operator= ( const SizeTableProperty &src );
};

MP4SgpdAtom::MP4SgpdAtom(MP4File &file)
        : MP4Atom(file, "sgpd")
{
    AddVersionAndFlags();
    AddProperty( /* 3 */ new MP4Integer32Property(*this,"groupingType"));
}

void MP4SgpdAtom::AddProperties(uint8_t version)
{	
    if (version == 1) {
    	AddProperty(new MP4Integer32Property(*this,"defaultLength"));
    }
    if (version >= 2) {
        AddProperty(new MP4Integer32Property(*this,"defaultSampleDescriptionIndex"));
    }
}

void MP4SgpdAtom::AddTableProperties(uint8_t version, uint32_t defaultLength)
{
    MP4Integer32Property* pCount = new MP4Integer32Property(*this, "entryCount");
    AddProperty(pCount);

    MP4TableProperty* pTable;

    if (version == 1 && defaultLength == 0) {
    	pTable = new SizeTableProperty(*this, "entries", pCount);
	}
	else {
		pTable = new MP4TableProperty(*this, "entries", pCount);
	}

    AddProperty(pTable);

    if (version == 1 && defaultLength == 0) {
        pTable->AddProperty(new MP4Integer32Property(pTable->GetParentAtom(), "descriptionLength"));
        pTable->AddProperty(new MP4BytesProperty(pTable->GetParentAtom(), "groupingType"));
    }
    else if (defaultLength == 1) {
	    pTable->AddProperty(new MP4Integer8Property(pTable->GetParentAtom(), "groupingType"));
	}
	else if (defaultLength == 2) {
		pTable->AddProperty(new MP4Integer16Property(pTable->GetParentAtom(), "groupingType"));
	}
	else {
		pTable->AddProperty(new MP4BytesProperty(pTable->GetParentAtom(), "groupingType", defaultLength));
	}
}

void MP4SgpdAtom::Generate()
{
	uint32_t defaultLength = 2;
    SetVersion(1);
    AddProperties(GetVersion());

    ((MP4Integer32Property *)m_pProperties[3])->SetValue(defaultLength);

    AddTableProperties(GetVersion(), defaultLength);

    MP4Atom::Generate();
}

void MP4SgpdAtom::Read()
{
    /* read atom version */
    ReadProperties(0, 2);

    uint8_t version = GetVersion();

    /* need to create the properties based on the atom version */
    AddProperties(version);

    if (version >= 1) {
        ReadProperties(2, 2);
    }

    uint32_t defaultLength = 0;
    if (version == 1) {
        defaultLength = ((MP4Integer32Property *)m_pProperties[3])->GetValue();
    }

    /* need to create the properties based on the atom version and default Length*/
    AddTableProperties(version, defaultLength);

    if (version >= 1) {
        ReadProperties(4, 2);
    }
    else {
        ReadProperties(3, 2);
    }

    Skip(); // to end of atom
}

///////////////////////////////////////////////////////////////////////////////

}
} // namespace mp4v2::impl
