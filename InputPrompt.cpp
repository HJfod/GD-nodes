#include "InputPrompt.hpp"

bool InputPrompt::init(const char* inputText, InputResult resFunc, const char* applyText) {
    if (!BrownAlertDelegate::init(220.0f, 140.0f, "GJ_square02.png"))
        return false;

    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    
    this->m_pInput = InputNode::create(160.0f, inputText, "bigFont.fnt");
    this->m_pInput->setPosition(winSize / 2);
    this->m_pLayer->addChild(this->m_pInput);
    this->m_pResultFunc = resFunc;

    auto button = gd::CCMenuItemSpriteExtra::create(
        gd::ButtonSprite::create(
            applyText, 0, 0, "goldFont.fnt", "GJ_button_01.png", 0, .8f
        ),
        this,
        (cocos2d::SEL_MenuHandler)&InputPrompt::onApply
    );
    button->setPosition(0.0f, - this->m_pLrSize.height / 2 + 25.0f);

    this->m_pButtonMenu->addChild(button);

    return true;
}

void InputPrompt::onApply(cocos2d::CCObject*) {
    this->m_pResultFunc(this->m_pInput->getString());

    this->onClose(nullptr);
}

InputPrompt* InputPrompt::create(const char* inputText, InputResult resFunc, const char* applyText) {
    auto pRet = new InputPrompt();

    if (pRet && pRet->init(inputText, resFunc, applyText)) {

    }
}
