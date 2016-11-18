/*
 * This file is a part of Tycau
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 */
#pragma once
/* 
 * it defines public module in this file
 * 
 * 
 * 
 * 
 * 
 */
namespace TkType{
    /* 
     * the scene protagonist in
     * 
     * 
     * 
     * 
     * 
     */
    enum Type{
        Null = 0,
        InHouse = 1,
    };
};
namespace TkStatusType{
    /* 
     * which state should be set after event came up
     * 
     * 
     * 
     * 
     * 
     */
    enum Status{
        Null = 0,
        ChangeScene = 1,
    };

};
