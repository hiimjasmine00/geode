/*
 * Copyright (c) 2012 cocos2d-x.org
 * http://www.cocos2d-x.org
 *
 * Copyright 2011 Yannick Loriot. All rights reserved.
 * http://yannickloriot.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * Converted to c++ / cocos2d-x by Angus C
 */


#ifndef __CCCONTROL_BUTTON_H__
#define __CCCONTROL_BUTTON_H__

#include "CCControl.h"
#include "CCInvocation.h"
#include "CCScale9Sprite.h"

NS_CC_EXT_BEGIN

/* Define the button margin for Left/Right edge */
#define CCControlButtonMarginLR 8 // px
/* Define the button margin for Top/Bottom edge */
#define CCControlButtonMarginTB 2 // px


/**
 * @addtogroup GUI
 * @{
 * @addtogroup control_extension
 * @{
 */

/** @class CCControlButton Button control for Cocos2D. */
class CC_DLL CCControlButton : public CCControl
{
public:
    GEODE_CUSTOM_CONSTRUCTOR_COCOS(CCControlButton, CCControl)
    CCControlButton();
    virtual ~CCControlButton();
    virtual void needsLayout(void);

    virtual void setEnabled(bool enabled);
    virtual void setSelected(bool enabled);
    virtual void setHighlighted(bool enabled);
protected:
    // CCRGBAProtocol
    //bool m_bIsOpacityModifyRGB;

    /** The current title that is displayed on the button. */
    CC_SYNTHESIZE_READONLY(CCString*, m_currentTitle, CurrentTitle);

    /** The current color used to display the title. */
    CC_SYNTHESIZE_READONLY_PASS_BY_REF(ccColor3B, m_currentTitleColor, CurrentTitleColor);

    /** Adjust the background image. YES by default. If the property is set to NO, the
    background will use the prefered size of the background image. */
    bool doesAdjustBackgroundImage();
    void setAdjustBackgroundImage(bool adjustBackgroundImage);
    bool m_doesAdjustBackgroundImage;

    /** The current title label. */
    CC_SYNTHESIZE_RETAIN(CCNode*, m_titleLabel, TitleLabel);

    /** The current background sprite. */
    CC_SYNTHESIZE_RETAIN(CCScale9Sprite*, m_backgroundSprite, BackgroundSprite);

    /** The prefered size of the button, if label is larger it will be expanded. */
    CC_PROPERTY(CCSize, m_preferredSize, PreferredSize);

    /** Adjust the button zooming on touchdown. Default value is YES. */
    CC_PROPERTY(bool, m_zoomOnTouchDown, ZoomOnTouchDown);

    CC_PROPERTY(CCPoint, m_labelAnchorPoint, LabelAnchorPoint);

    /* Override setter to affect a background sprite too */
    virtual GLubyte getOpacity(void);
    virtual void setOpacity(GLubyte var);
	virtual const ccColor3B& getColor(void);
	virtual void setColor(const ccColor3B&);

    /** Flag to know if the button is currently pushed.  */
public:
    bool m_isPushed;
    bool m_bParentInited;
public:
    bool isPushed() { return m_isPushed; }

    // <CCControlState, CCString*>
    CC_SYNTHESIZE_RETAIN(CCDictionary*, m_titleDispatchTable, TitleDispatchTable);
    // <CCControlState, CCColor3bObject*>
    CC_SYNTHESIZE_RETAIN(CCDictionary*, m_titleColorDispatchTable, TitleColorDispatchTable);
    // <CCControlState, CCNode*>
    CC_SYNTHESIZE_RETAIN(CCDictionary*, m_titleLabelDispatchTable, TitleLabelDispatchTable);
    // <CCControlState, CCScale9Sprite*>
    CC_SYNTHESIZE_RETAIN(CCDictionary*, m_backgroundSpriteDispatchTable, BackgroundSpriteDispatchTable);

    /* Define the button margin for Top/Bottom edge */
    CC_SYNTHESIZE_READONLY(int, m_marginV, VerticalMargin);
    /* Define the button margin for Left/Right edge */
    CC_SYNTHESIZE_READONLY(int, m_marginH, HorizontalOrigin);
    //set the margins at once (so we only have to do one call of needsLayout)
    virtual void setMargins(int marginH, int marginV);


public:
    virtual bool init();
    virtual bool initWithLabelAndBackgroundSprite(CCNode* label, CCScale9Sprite* backgroundSprite);

    static CCControlButton* create(CCNode* label, CCScale9Sprite* backgroundSprite);

    virtual bool initWithTitleAndFontNameAndFontSize(gd::string title, const char * fontName, float fontSize);

    static CCControlButton* create(gd::string title, const char * fontName, float fontSize);

    virtual bool initWithBackgroundSprite(CCScale9Sprite* sprite);

    static CCControlButton* create(CCScale9Sprite* sprite);

    //events
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

    /**
    * Returns the title used for a state.
    *
    * @param state The state that uses the title. Possible values are described in
    * "CCControlState".
    *
    * @return The title for the specified state.
    */
    virtual CCString* getTitleForState(CCControlState state);

    /**
    * Sets the title string to use for the specified state.
    * If a property is not specified for a state, the default is to use
    * the CCButtonStateNormal value.
    *
    * @param title The title string to use for the specified state.
    * @param state The state that uses the specified title. The values are described
    * in "CCControlState".
    */
    virtual void setTitleForState(CCString* title, CCControlState state);

    /**
    * Returns the title color used for a state.
    *
    * @param state The state that uses the specified color. The values are described
    * in "CCControlState".
    *
    * @return The color of the title for the specified state.
    */

    virtual const ccColor3B getTitleColorForState(CCControlState state);

    /**
    * Sets the color of the title to use for the specified state.
    *
    * @param color The color of the title to use for the specified state.
    * @param state The state that uses the specified color. The values are described
    * in "CCControlState".
    */
    virtual void setTitleColorForState(ccColor3B color, CCControlState state);

    /**
    * Returns the title label used for a state.
    *
    * @param state The state that uses the title label. Possible values are described
    * in "CCControlState".
    */
    virtual CCNode* getTitleLabelForState(CCControlState state);

    /**
    * Sets the title label to use for the specified state.
    * If a property is not specified for a state, the default is to use
    * the CCButtonStateNormal value.
    *
    * @param title The title label to use for the specified state.
    * @param state The state that uses the specified title. The values are described
    * in "CCControlState".
    */
    virtual void setTitleLabelForState(CCNode* label, CCControlState state);

    virtual void setTitleTTFForState(const char * fntFile, CCControlState state);
    virtual const char * getTitleTTFForState(CCControlState state);

    virtual void setTitleTTFSizeForState(float size, CCControlState state);
    virtual float getTitleTTFSizeForState(CCControlState state);

    /**
     * Sets the font of the label, changes the label to a CCLabelBMFont if neccessary.
     * @param fntFile The name of the font to change to
     * @param state The state that uses the specified fntFile. The values are described
     * in "CCControlState".
     */
    virtual void setTitleBMFontForState(const char * fntFile, CCControlState state);
    virtual const char * getTitleBMFontForState(CCControlState state);

    /**
    * Returns the background sprite used for a state.
    *
    * @param state The state that uses the background sprite. Possible values are
    * described in "CCControlState".
    */
    virtual CCScale9Sprite* getBackgroundSpriteForState(CCControlState state);

    /**
    * Sets the background sprite to use for the specified button state.
    *
    * @param sprite The background sprite to use for the specified state.
    * @param state The state that uses the specified image. The values are described
    * in "CCControlState".
    */
    virtual void setBackgroundSpriteForState(CCScale9Sprite* sprite, CCControlState state);

    /**
     * Sets the background spriteFrame to use for the specified button state.
     *
     * @param spriteFrame The background spriteFrame to use for the specified state.
     * @param state The state that uses the specified image. The values are described
     * in "CCControlState".
     */
    virtual void setBackgroundSpriteFrameForState(CCSpriteFrame * spriteFrame, CCControlState state);

    static CCControlButton* create();
};

// end of GUI group
/// @}
/// @}

NS_CC_EXT_END

#endif
