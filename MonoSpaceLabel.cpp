#include "MonoSpaceLabel.hpp"

using namespace cocos2d;

bool MonoSpaceLabel::init(
    const char* text,
    const char* bmFile,
    float charWidth,
    CCTextAlignment alignment,
    float labelWidth
) {
    this->m_fCharWidth = charWidth;

    if (!CCLabelBMFont::initWithString(text, bmFile, labelWidth, alignment, CCPointZero))
        return false;

    return true;
}

void MonoSpaceLabel::updateLabel() {
    CCLabelBMFont::updateLabel();

    CCObject* child;
    auto index = 0;
    auto posX = 0.0f;
    CCARRAY_FOREACH(m_pChildren, child) {
        auto pNode = reinterpret_cast<CCNode*>(child);

        if (pNode) {
            auto c = m_sString[index];

            if (c == '\n')
                posX = 0.0f;
            
            pNode->setPositionX(posX);

            posX += this->m_fCharWidth;
        }

        index++;
    }
}

void MonoSpaceLabel::setCharWidth(float value) {
    this->m_fCharWidth = value;
}

float MonoSpaceLabel::getCharWidth() {
    return this->m_fCharWidth;
}

MonoSpaceLabel* MonoSpaceLabel::create(
    const char* text,
    const char* bmFile,
    float charWidth,
    cocos2d::CCTextAlignment alignment,
    float labelWidth
) {
    auto pRet = new MonoSpaceLabel;

    if (pRet && pRet->init(text, bmFile, charWidth, alignment, labelWidth)) {
        pRet->autorelease();
        return pRet;
    }

    CC_SAFE_DELETE(pRet);
    return nullptr;
}

// overloads

MonoSpaceLabel* MonoSpaceLabel::create(
    const char* text,
    const char* bmFile,
    float charWidth,
    cocos2d::CCTextAlignment alignment
) {
    return create(text, bmFile, charWidth, alignment, kCCLabelAutomaticWidth);
}

MonoSpaceLabel* MonoSpaceLabel::create(
    const char* text,
    const char* bmFile,
    float charWidth,
    float labelWidth
) {
    return create(text, bmFile, charWidth, kMonoSpaceLabelDefaultTextAlignment, labelWidth);
}

MonoSpaceLabel* MonoSpaceLabel::create(
    const char* text,
    const char* bmFile,
    float charWidth
) {
    return create(text, bmFile, charWidth, kMonoSpaceLabelDefaultTextAlignment, kCCLabelAutomaticWidth);
}
