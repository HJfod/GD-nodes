#pragma once

#include <GDMake.h>

class MonoSpaceLabel : public cocos2d::CCLabelBMFont {
    protected:
        float m_fCharWidth;
        static inline cocos2d::CCTextAlignment kMonoSpaceLabelDefaultTextAlignment = cocos2d::kCCTextAlignmentLeft;

        bool init(
            const char* text,
            const char* bmFile,
            float charWidth,
            cocos2d::CCTextAlignment alignment,
            float labelWidth
        );

        void updateLabel() override;

    public:
        static MonoSpaceLabel* create(
            const char* text,
            const char* bmFile,
            float charWidth
        );
        static MonoSpaceLabel* create(
            const char* text,
            const char* bmFile,
            float charWidth,
            float labelWidth
        );
        static MonoSpaceLabel* create(
            const char* text,
            const char* bmFile,
            float charWidth,
            cocos2d::CCTextAlignment alignment
        );
        static MonoSpaceLabel* create(
            const char* text,
            const char* bmFile,
            float charWidth,
            cocos2d::CCTextAlignment alignment,
            float labelWidth
        );

        void setCharWidth(float);
        float getCharWidth();
};
