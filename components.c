#include "clay.h"
#include "headers/persona_theme.h"

void MessageBoxComponent (Clay_String messageText) {
    static CustomLayoutElement messageOuterBox = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_WHITE,
            .topLeft = {0, 0},
            .topRight = {28, -12},
            .bottomLeft = {-25, 0},
            .bottomRight = {0, 10}
        }
    };
    static CustomLayoutElement messageInnerBox = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_BLACK,
            .topLeft = {0, 0},
            .topRight = {15, -12},
            .bottomLeft = {-20, 0},
            .bottomRight = {0, 10}
        }
    };

    CLAY_AUTO_ID({
        .custom = { .customData = &messageOuterBox},
        .backgroundColor = P5_COLOR_WHITE,
        .layout = {
            .sizing = {CLAY_SIZING_FIXED(300), CLAY_SIZING_FIXED(80)},
            .padding = {4, 4, 4, 4},
        },

    }){
        CLAY_AUTO_ID({
            .custom = { .customData = &messageInnerBox},
            .backgroundColor = P5_COLOR_BLACK,
            .layout = {
                .sizing = {CLAY_SIZING_FIXED(290), CLAY_SIZING_FIXED(70)},
                .padding = {16, 16, 16, 16},
            }
        }){
            CLAY_TEXT(messageText, {
                .fontSize = 16,
                .textColor = P5_COLOR_WHITE,
                .fontId = FONT_ID_BODY_MESSAGETEXT,
            });
        }
    }
}