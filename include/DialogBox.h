/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once

#include "GraphicsObject.h"
/* 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class TkDialogBox : public TkGraphicsObject{
public:
    TkDialogBox( );
    void clicked();// ����֮���ɿ�
    void pressed(); // ���²��ɿ�
    void keyPressed( ); // �����ť

protected:
    std::string m_Text;
};

