/****************************************************************************
 Copyright (c) 2013 cocos2d-x.org

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

#ifndef __CCETCTEXTURE_H__
#define __CCETCTEXTURE_H__

#include "../cocoa/CCObject.h"
#include "../platform/CCPlatformMacros.h"
#include "../platform/CCGL.h"

NS_CC_BEGIN
/**
 *  @js NA
 *  @lua NA
 */
class CC_DLL CCTextureETC : public CCObject
{
    GEODE_FRIEND_MODIFY
public:
    GEODE_CUSTOM_CONSTRUCTOR_COCOS(CCTextureETC, CCObject)
    CCTextureETC();
    virtual ~CCTextureETC();

    bool initWithFile(const char* file);

    unsigned int getName() const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;

private:
    bool loadTexture(const char* file);

public:
    GLuint _name;
    unsigned int _width;
    unsigned int _height;
};

NS_CC_END

#endif /* defined(__CCETCTEXTURE_H__) */
