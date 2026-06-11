#include "clay.h"
#include "headers/persona_theme.h"

void MessageBoxComponent (Clay_String messageText) {
    static CustomLayoutElement messageOuterBox = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_WHITE,
            .topLeft = {0, 0},
            .topRight = {0, 20},
            .bottomLeft = {20, 0},
            .bottomRight = {-20, -10}
        }
    };
    static CustomLayoutElement messageInnerBox = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_BLACK,
            .topLeft = {5, 5},
            .topRight = {-5, 15},
            .bottomLeft = {15, -5},
            .bottomRight = {-15, -5}
        }
    };

    CLAY_AUTO_ID({
        .custom = { .customData = &messageOuterBox},
        .layout = {
            .sizing = {CLAY_SIZING_FIXED(300), CLAY_SIZING_FIXED(100)},
            .padding = {5, 5, 5, 5},
        },

    }){
        CLAY_AUTO_ID({
            .custom = { .customData = &messageInnerBox},
            .layout = {
                .sizing = {CLAY_SIZING_FIXED(290), CLAY_SIZING_FIXED(90)},
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