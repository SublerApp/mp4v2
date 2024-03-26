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

MP4ClapAtom::MP4ClapAtom(MP4File &file)
        : MP4Atom(file, "clap")
{

    AddProperty( /* 0 */
        new MP4Integer32Property(*this, "cleanApertureWidthN"));

    AddProperty( /* 1 */
        new MP4Integer32Property(*this, "cleanApertureWidthD"));

    AddProperty( /* 2 */
        new MP4Integer32Property(*this, "cleanApertureHeightN"));

    AddProperty( /* 3 */
        new MP4Integer32Property(*this, "cleanApertureHeightD"));

    AddProperty( /* 4 */
        new MP4Integer32Property(*this, "horizOffN"));

    AddProperty( /* 5 */
        new MP4Integer32Property(*this, "horizOffD"));

    AddProperty( /* 6 */
        new MP4Integer32Property(*this, "vertOffN"));

    AddProperty( /* 7 */
        new MP4Integer32Property(*this, "vertOffD"));
}

void MP4ClapAtom::Generate()
{

    MP4Atom::Generate();

    ((MP4Integer32Property*)m_pProperties[0])->SetValue(1);
    ((MP4Integer32Property*)m_pProperties[1])->SetValue(1);
    ((MP4Integer32Property*)m_pProperties[2])->SetValue(1);
    ((MP4Integer32Property*)m_pProperties[3])->SetValue(1);
    ((MP4Integer32Property*)m_pProperties[4])->SetValue(0);
    ((MP4Integer32Property*)m_pProperties[5])->SetValue(1);
    ((MP4Integer32Property*)m_pProperties[6])->SetValue(0);
    ((MP4Integer32Property*)m_pProperties[7])->SetValue(1);
}

///////////////////////////////////////////////////////////////////////////////

}
} // namespace mp4v2::impl
