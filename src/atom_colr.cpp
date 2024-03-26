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
 * Contributer has declined to give copyright information, and gives
 * it freely to the world.
 *
 * Contributor(s):
 */

#include "src/impl.h"

namespace mp4v2 {
namespace impl {

///////////////////////////////////////////////////////////////////////////////

const string type_nclc = "nclc";
const string type_nclx = "nclx";
const string type_nICC = "rICC";
const string type_prof = "prof";

MP4ColrAtom::MP4ColrAtom(MP4File &file)
        : MP4Atom(file, "colr")
{
    MP4StringProperty* cpt = new MP4StringProperty(*this,"colorParameterType");
    cpt->SetFixedLength(4);
    AddProperty(cpt); /* 0 */
}

void MP4ColrAtom::AddProperties(const string type)
{
    if (type == type_nclc) {
        AddProperty( /* 1 */ new MP4Integer16Property(*this,"primariesIndex"));

        AddProperty( /* 2 */ new MP4Integer16Property(*this,"transferFunctionIndex"));

        AddProperty( /* 3 */ new MP4Integer16Property(*this,"matrixIndex"));
    }
    else if (type == type_nclx) {
        AddProperty( /* 1 */ new MP4Integer16Property(*this,"primariesIndex"));

        AddProperty( /* 2 */ new MP4Integer16Property(*this,"transferFunctionIndex"));

        AddProperty( /* 3 */ new MP4Integer16Property(*this,"matrixIndex"));

        AddProperty( /* 4 */ new MP4BitfieldProperty(*this,"full_range_flag", 1));

        AddProperty( /* 5 */ new MP4BitfieldProperty(*this,"reserved", 7));
    }
    else if (type == type_nICC || type == type_prof) {
        AddProperty( /* 1 */ new MP4BytesProperty(*this,"ICC_profile"));
    }
}

void MP4ColrAtom::Generate()
{
    // Is type set?
    const string type = type_nclx;
    AddProperties(type);

    MP4Atom::Generate();
    ((MP4StringProperty*)m_pProperties[0])->SetValue(type.c_str());

    if (type == type_nclc || type == type_nclx) {
        // default to ITU BT.709 values
        ((MP4Integer16Property*)m_pProperties[1])->SetValue(1);
        ((MP4Integer16Property*)m_pProperties[2])->SetValue(1);
        ((MP4Integer16Property*)m_pProperties[3])->SetValue(1);
        if (type == type_nclx) {
            ((MP4Integer16Property*)m_pProperties[4])->SetValue(0);
        }
    }
}

void MP4ColrAtom::Read()
{
    /* read colour type */
    ReadProperties(0);

    /* need to create the properties based on the colour type */
    const string type = ((MP4StringProperty*)m_pProperties[0])->GetValue();
    AddProperties(type);

    if (type == type_nclc) {
        ReadProperties(1, 3);
    }
    else if (type == type_nclx) {
        ReadProperties(1, 5);
    }
    else if (type == type_nICC || type == type_prof) {
        ReadProperties(1);
    }
}

///////////////////////////////////////////////////////////////////////////////

}
} // namespace mp4v2::impl
