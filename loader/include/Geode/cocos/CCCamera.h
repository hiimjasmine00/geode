/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2011      Zynga Inc.

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

#ifndef __CCCAMERA_H__
#define __CCCAMERA_H__

#include "cocoa/CCObject.h"
#include "include/ccMacros.h"
#include "kazmath/include/kazmath/mat4.h"
#include <string>

NS_CC_BEGIN

/**
 * @addtogroup base_nodes
 * @{
 */

/**
A CCCamera is used in every CCNode.
Useful to look at the object from different views.
The OpenGL gluLookAt() function is used to locate the
camera.

If the object is transformed by any of the scale, rotation or
position attributes, then they will override the camera.

IMPORTANT: Either your use the camera or the rotation/scale/position properties. You can't use both.
World coordinates won't work if you use the camera.

Limitations:

- Some nodes, like CCParallaxNode, CCParticle uses world node coordinates, and they won't work properly if you move them (or any of their ancestors)
using the camera.

- It doesn't work on batched nodes like CCSprite objects when they are parented to a CCSpriteBatchNode object.

- It is recommended to use it ONLY if you are going to create 3D effects. For 2D effects, use the action CCFollow or position/scale/rotate.

*/
class CC_DLL CCCamera : public CCObject
{
    GEODE_FRIEND_MODIFY
public:
    float m_fEyeX;
    float m_fEyeY;
    float m_fEyeZ;

    float m_fCenterX;
    float m_fCenterY;
    float m_fCenterZ;

    float m_fUpX;
    float m_fUpY;
    float m_fUpZ;

    bool m_bDirty;
    kmMat4    m_lookupMatrix;
public:
    GEODE_CUSTOM_CONSTRUCTOR_COCOS(CCCamera, CCObject)
    /**
     *  @js ctor
     */
    CCCamera(void);
    /**
     *  @js NA
     *  @lua NA
     */
    ~CCCamera(void);

    void init(void);
    /**
     *  @js NA
     */
    const char* description(void);

    /** sets the dirty value */
    inline void setDirty(bool bValue) { m_bDirty = bValue; }
    /** get the dirty value */
    inline bool isDirty(void) { return m_bDirty; }

    /** sets the camera in the default position */
    void restore(void);
    /** Sets the camera using gluLookAt using its eye, center and up_vector */
    void locate(void);
    /** sets the eye values in points
     *  @js setEye
     */
    void setEyeXYZ(float fEyeX, float fEyeY, float fEyeZ);
    /** sets the center values in points
     *  @js setCenter
     */
    void setCenterXYZ(float fCenterX, float fCenterY, float fCenterZ);
    /** sets the up values
     *  @js setUp
     */
    void setUpXYZ(float fUpX, float fUpY, float fUpZ);

    /** get the eye vector values in points
     *  @js NA
     */
    void getEyeXYZ(float *pEyeX, float *pEyeY, float *pEyeZ);
    /** get the center vector values int points
     *  @js NA
     */
    void getCenterXYZ(float *pCenterX, float *pCenterY, float *pCenterZ);
    /** get the up vector values
     *  @js NA
     */
    void getUpXYZ(float *pUpX, float *pUpY, float *pUpZ);
public:
    /** returns the Z eye */
    static float getZEye();

private:
    DISALLOW_COPY_AND_ASSIGN(CCCamera);
};

// end of base_node group
/// @}

NS_CC_END

#endif // __CCCAMERA_H__
