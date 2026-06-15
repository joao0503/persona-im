#include "clay.h"
#include "headers/persona_theme.h"

void InstantMessageBoxComponent (Clay_String messageText) {
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

    static CustomLayoutElement messageStemWhiteLeft = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_WHITE,
            .topLeft = {0, 0},
            .topRight = {0, 0},
            .bottomLeft = {0, 0},
            .bottomRight = {0, 0}
        }
    };

    static CustomLayoutElement messageStemWhiteRight = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_WHITE,
            .topLeft = {0, 0},
            .topRight = {15, -12},
            .bottomLeft = {-20, 0},
            .bottomRight = {0, 10}
        }
    };

    CLAY_AUTO_ID({
        .layout = {
            .layoutDirection = CLAY_LEFT_TO_RIGHT,
        }   
    }){
        CLAY_AUTO_ID({
            //.border = {.width = {2, 2, 2, 2, 0}, .color = {0, 0, 255, 255},},
            .custom = { .customData = &messageStemWhiteLeft},
            .layout = {
                .sizing = {CLAY_SIZING_FIXED(20), CLAY_SIZING_FIXED(15),},
            }
        }) {

        } 
        CLAY_AUTO_ID({
            //.border = {.width = {2, 2, 2, 2, 0}, .color = {0, 0, 255, 255},},
            .custom = { .customData = &messageOuterBox},
            .layout = {
                .sizing = {CLAY_SIZING_FIXED(300), CLAY_SIZING_FIXED(80)},
                .padding = {4, 4, 4, 4},
            },
        }){
            CLAY_AUTO_ID({
                //.border = {.width = {2, 2, 2, 2, 0},.color = {0, 255, 0, 255},},
                .custom = { .customData = &messageInnerBox},
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

}