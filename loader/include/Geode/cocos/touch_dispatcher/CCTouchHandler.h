/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2009      Valentin Milea

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

#ifndef __TOUCH_DISPATCHER_CCTOUCH_HANDLER_H__
#define __TOUCH_DISPATCHER_CCTOUCH_HANDLER_H__

#include "CCTouchDelegateProtocol.h"
#include "CCTouchDispatcher.h"
#include "../cocoa/CCObject.h"
#include "../cocoa/CCSet.h"

NS_CC_BEGIN

/**
 * @addtogroup input
 * @{
 */

/**
 CCTouchHandler
 Object than contains the delegate and priority of the event handler.
 @js NA
 @lua NA
*/
class CC_DLL  CCTouchHandler : public CCObject
{
    GEODE_FRIEND_MODIFY
public:
	GEODE_CUSTOM_CONSTRUCTOR_COCOS(CCTouchHandler, CCObject)
	inline CCTouchHandler() = default;
    virtual ~CCTouchHandler(void);

    /** delegate */
    CCTouchDelegate* getDelegate();
    void setDelegate(CCTouchDelegate *pDelegate);

    /** priority */
    int getPriority(void);
    void setPriority(int nPriority);

    /** enabled selectors */
    int getEnabledSelectors(void);
    void setEnalbedSelectors(int nValue);

    /** initializes a TouchHandler with a delegate and a priority */
    virtual bool initWithDelegate(CCTouchDelegate *pDelegate, int nPriority);

public:
    /** allocates a TouchHandler with a delegate and a priority */
    static CCTouchHandler* handlerWithDelegate(CCTouchDelegate *pDelegate, int nPriority);

public:
    CCTouchDelegate *m_pDelegate;
    int m_nPriority;
    int m_nEnabledSelectors;
};

/** CCStandardTouchHandler
 It forwards each event to the delegate.
 @js NA
 @lua NA
 */
class CC_DLL  CCStandardTouchHandler : public CCTouchHandler
{
    GEODE_FRIEND_MODIFY
public:
	GEODE_CUSTOM_CONSTRUCTOR_COCOS(CCStandardTouchHandler, CCTouchHandler)
	inline CCStandardTouchHandler() = default;

    ~CCStandardTouchHandler(void);

    /** initializes a TouchHandler with a delegate and a priority */
    virtual bool initWithDelegate(CCTouchDelegate *pDelegate, int nPriority);

public:
    /** allocates a TouchHandler with a delegate and a priority */
    static CCStandardTouchHandler* handlerWithDelegate(CCTouchDelegate *pDelegate, int nPriority);
};

/**
 CCTargetedTouchHandler
 Object than contains the claimed touches and if it swallows touches.
 Used internally by TouchDispatcher
 @js NA
 @lua NA
 */
class CC_DLL  CCTargetedTouchHandler : public CCTouchHandler
{
    GEODE_FRIEND_MODIFY
public:
	GEODE_CUSTOM_CONSTRUCTOR_COCOS(CCTargetedTouchHandler, CCTouchHandler)
	inline CCTargetedTouchHandler() = default;

    ~CCTargetedTouchHandler(void);

    /** whether or not the touches are swallowed */
    bool isSwallowsTouches(void);
    void setSwallowsTouches(bool bSwallowsTouches);

    /** MutableSet that contains the claimed touches */
    CCSet* getClaimedTouches(void);

    /** initializes a TargetedTouchHandler with a delegate, a priority and whether or not it swallows touches or not */
    bool initWithDelegate(CCTouchDelegate *pDelegate, int nPriority, bool bSwallow);

public:
    /** allocates a TargetedTouchHandler with a delegate, a priority and whether or not it swallows touches or not */
    static CCTargetedTouchHandler* handlerWithDelegate(CCTouchDelegate *pDelegate, int nPriority, bool bSwallow);

public:
    bool m_bSwallowsTouches;
    CCSet *m_pClaimedTouches;
};

// end of input group
/// @}

NS_CC_END

#endif // __TOUCH_DISPATCHER_CCTOUCH_HANDLER_H__
