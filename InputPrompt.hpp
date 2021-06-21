#pragma once

#include <GDMake.h>
#include <BrownAlertDelegate.hpp>
#include <InputNode.hpp>

class InputPrompt : public BrownAlertDelegate {
    public:
        using InputResult = std::function<void(const char*)>;
    protected:
        InputNode* m_pInput;
        InputResult m_pResultFunc;

        inline void setup() override {};
        void onApply(cocos2d::CCObject*);
        bool init(const char* title, const char* inputText, InputResult resFunc, const char* applyText);

    public:
        static InputPrompt* create(
            const char* title,
            const char* inputText,
            InputResult resFunc,
            const char* applyText = "Apply"
        );
        InputPrompt* setCallback(InputResult resFunc) { this->m_pResultFunc = resFunc; return this; }
        inline InputNode* getInputNode() { return m_pInput; }
};
