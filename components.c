#include "clay.h"
#include "headers/persona_theme.h"

void InstantMessageBoxComponent (Clay_String messageText, int index) {
    static CustomLayoutElement messageOuterBox = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_WHITE,
            .topLeft = {0, 0}, .topRight = {28, -12},
            .bottomLeft = {-25, 0}, .bottomRight = {0, 10}
        }
    };
    static CustomLayoutElement messageInnerBox = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_BLACK,
            .topLeft = {0, 0}, .topRight = {15, -12},
            .bottomLeft = {-20, 0}, .bottomRight = {0, 10}
        }
    };

    static CustomLayoutElement tailOuterBoxLeft = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_WHITE,
            .topLeft = {-22, 14}, .topRight = {-16, 6},
            .bottomLeft = {-52, 36}, .bottomRight = {-12, 28}
        }
    };

    static CustomLayoutElement tailOuterBoxRight = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_WHITE,
            .topLeft = {-38, 26}, .topRight = {2, 8},
            .bottomLeft = {-34, 48}, .bottomRight = {2, 40}
        }
    };


    static CustomLayoutElement tailInnerBoxLeft = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_BLACK,
            .topLeft = {-46, 4}, .topRight = {-36, -4},
            .bottomLeft = {-62, 16}, .bottomRight = {-32, 8}
        }
    };

    static CustomLayoutElement tailInnerBoxRight = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_BLACK,
            .topLeft = {-46, 9}, .topRight = {-16, 1},
            .bottomLeft = {-42, 24}, .bottomRight = {-16, 16}
        }
    };


    CLAY_AUTO_ID({
        .layout = {
            .layoutDirection = CLAY_LEFT_TO_RIGHT,
            .padding = {0, 0, 32, 0}
        }   
    }){
        CLAY(CLAY_IDI("OuterBubble", index), {
            .custom = { .customData = &messageOuterBox},
            .layout = {
                .sizing = {CLAY_SIZING_FIXED(280), CLAY_SIZING_FIT()},
                .padding = {4, 4, 4, 4},
            },
        }){
            CLAY_AUTO_ID({
                .custom = { .customData = &tailOuterBoxLeft },
                .layout = { .sizing = { CLAY_SIZING_FIXED(0), CLAY_SIZING_FIXED(0) } },
            }) {}
            CLAY_AUTO_ID({
                .custom = { .customData = &tailOuterBoxRight },
                .layout = { .sizing = { CLAY_SIZING_FIXED(0), CLAY_SIZING_FIXED(0) } },
            }) {}
            
            CLAY(CLAY_IDI("InnerBubble", index), {
                .custom = { .customData = &messageInnerBox },
                .layout = {
                    .sizing = {CLAY_SIZING_GROW(), CLAY_SIZING_FIT()},
                    .padding = {16, 16, 16, 16},
                }
            }){
                CLAY_AUTO_ID({
                    .custom = { .customData = &tailInnerBoxLeft },
                    .layout = { .sizing = { CLAY_SIZING_FIXED(0), CLAY_SIZING_FIXED(0) } },
                    
                }) {}
                CLAY_AUTO_ID({
                    .custom = { .customData = &tailInnerBoxRight },
                    .layout = { .sizing = { CLAY_SIZING_FIXED(0), CLAY_SIZING_FIXED(0) } },
                    
                }) {}

                CLAY_TEXT(messageText, {
                    .fontSize = 16,
                    .textColor = P5_COLOR_WHITE,
                    .fontId = FONT_ID_BODY_MESSAGETEXT,
                });
            }
        }
    }
}