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

MP4MdcvAtom::MP4MdcvAtom(MP4File &file)
        : MP4Atom(file, "mdcv")
{

    AddProperty( /* 0 */
        new MP4Integer16Property(*this, "displayPrimariesGX"));

    AddProperty( /* 1 */
        new MP4Integer16Property(*this, "displayPrimariesGY"));

    AddProperty( /* 2 */
        new MP4Integer16Property(*this, "displayPrimariesBX"));

    AddProperty( /* 3 */
        new MP4Integer16Property(*this, "displayPrimariesBY"));

    AddProperty( /* 4 */
        new MP4Integer16Property(*this, "displayPrimariesRX"));

    AddProperty( /* 5 */
        new MP4Integer16Property(*this, "displayPrimariesRY"));

    AddProperty( /* 6 */
        new MP4Integer16Property(*this, "whitePointX"));

    AddProperty( /* 7 */
        new MP4Integer16Property(*this, "whitePointY"));

    AddProperty( /* 8 */
        new MP4Integer32Property(*this, "maxDisplayMasteringLuminance"));

    AddProperty( /* 9 */
        new MP4Integer32Property(*this, "minDisplayMasteringLuminance"));


}

void MP4MdcvAtom::Generate()
{

    MP4Atom::Generate();

    ((MP4Integer16Property*)m_pProperties[0])->SetValue(0);
    ((MP4Integer16Property*)m_pProperties[1])->SetValue(0);
    ((MP4Integer16Property*)m_pProperties[2])->SetValue(0);
    ((MP4Integer16Property*)m_pProperties[3])->SetValue(0);
    ((MP4Integer16Property*)m_pProperties[4])->SetValue(0);
    ((MP4Integer16Property*)m_pProperties[5])->SetValue(0);
    ((MP4Integer16Property*)m_pProperties[6])->SetValue(0);
    ((MP4Integer16Property*)m_pProperties[7])->SetValue(0);
    ((MP4Integer32Property*)m_pProperties[8])->SetValue(0);
    ((MP4Integer32Property*)m_pProperties[9])->SetValue(0);

}

///////////////////////////////////////////////////////////////////////////////

}
} // namespace mp4v2::impl
