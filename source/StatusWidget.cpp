/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#include "StatusWidget.h"


TkStatusWidget::TkStatusWidget(void){
    m_Image = NULL;
}


TkStatusWidget::~TkStatusWidget(void){
    delete m_Image;
}
