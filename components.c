#include "clay.h"
#include "headers/persona_theme.h"

void InstantMessageBoxComponent (Clay_String messageText, int index) {
    static CustomLayoutElement messageOuterBox = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_WHITE,
            .topLeft = {0, 0}, .topRight = {28, -12},
            .bottomLeft = {-25, 10}, .bottomRight = {0, 20}
        }
    };
    static CustomLayoutElement messageInnerBox = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_BLACK,
            .topLeft = {0, 0}, .topRight = {15, -12},
            .bottomLeft = {-20, 10}, .bottomRight = {0, 20}
        }
    };

    static CustomLayoutElement tailOuterBoxLeft = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_WHITE,
            .topLeft = {-26, 18}, .topRight = {-24, 6},
            .bottomLeft = {-56, 40}, .bottomRight = {-16, 32}
        }
    };

    static CustomLayoutElement tailOuterBoxRight = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_WHITE,
            .topLeft = {-40, 30}, .topRight = {-10, 16},
            .bottomLeft = {-36, 50}, .bottomRight = {-10, 46}
        }
    };

    static CustomLayoutElement tailInnerBoxLeft = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_BLACK,
            .topLeft = {-50, 8}, .topRight = {-44, -2},
            .bottomLeft = {-66, 20}, .bottomRight = {-38, 12}
        }
    };

    static CustomLayoutElement tailInnerBoxRight = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_BLACK,
            .topLeft = {-50, 12}, .topRight = {-16, 0},
            .bottomLeft = {-46, 28}, .bottomRight = {-12, 16}
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
                    .fontSize = FONT_SIZE,
                    .textColor = P5_COLOR_WHITE,
                    .fontId = FONT_ID_BODY_MESSAGETEXT,
                });
            }
        }
    }
}