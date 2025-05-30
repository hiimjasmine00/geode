/****************************************************************************
 Copyright (c) 2010 cocos2d-x.org

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#ifndef __CC_FILEUTILS_IOS_H__
#define __CC_FILEUTILS_IOS_H__

#include "../CCFileUtils.h"
#include <string>
#include <vector>
#include "../CCPlatformMacros.h"
#include "../../include/ccTypes.h"
#include "../../include/ccTypeInfo.h"

NS_CC_BEGIN

/**
 * @addtogroup platform
 * @{
 */

//! @brief  Helper class to handle file operations
class CC_DLL CCFileUtilsIOS : public CCFileUtils
{
    GEODE_FRIEND_MODIFY
public:
    /* override funtions */
    virtual gd::string getWritablePath();
    virtual bool isFileExist(const gd::string& strFilePath);
    virtual bool isAbsolutePath(const gd::string& strPath);
    virtual gd::string getFullPathForDirectoryAndFilename(const gd::string& strDirectory, const gd::string& strFilename);

    virtual CCDictionary* createCCDictionaryWithContentsOfFile(const gd::string& filename);
    virtual bool writeToFile(CCDictionary *dict, const gd::string& fullPath);

    virtual CCArray* createCCArrayWithContentsOfFile(const gd::string& filename);
};

// end of platform group
/// @}

NS_CC_END

#endif    // __CC_FILEUTILS_IOS_H__

