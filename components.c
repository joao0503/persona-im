#include "clay.h"
#include "headers/persona_theme.h"

void InstantMessageBoxComponent (Clay_String messageText, int index) {
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

    static CustomLayoutElement tailOuterBoxLeft = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_WHITE,
            .topLeft = {30, 0}, .topRight = {0, -8},
            .bottomLeft = {4, 0}, .bottomRight = {4, -8}
        }
    };

    static CustomLayoutElement tailOuterBoxRight = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_WHITE,
            .topLeft = {0, 0}, .topRight = {0, -16},
            .bottomLeft = {6, 0}, .bottomRight = {0, -8}
        }
    };


    static CustomLayoutElement tailInnerBoxLeft = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_BLACK,
            .topLeft = {20, 0}, .topRight = {0, -8},
            .bottomLeft = {4, 0}, .bottomRight = {4, -8}
        }
    };

    static CustomLayoutElement tailInnerBoxRight = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_BLACK,
            .topLeft = {0, 0}, .topRight = {0, -8},
            .bottomLeft = {4, 0}, .bottomRight = {0, -8}
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
                .sizing = {CLAY_SIZING_FIXED(300), CLAY_SIZING_FIT()},
                .padding = {4, 4, 4, 4},
            },
            .floating = {
                .zIndex = 1,
            },
        }){
            CLAY_AUTO_ID({
                .custom = { .customData = &tailOuterBoxLeft },
                .floating = {
                    .zIndex = 0,
                    .attachTo = CLAY_ATTACH_TO_ELEMENT_WITH_ID,
                    .parentId = CLAY_IDI("OuterBubble", index).id,
                    .attachPoints = { .element = CLAY_ATTACH_POINT_RIGHT_TOP, .parent = CLAY_ATTACH_POINT_LEFT_TOP },
                    .offset = { -12, 18 } 
                },
                .layout = { .sizing = { CLAY_SIZING_FIXED(40), CLAY_SIZING_FIXED(22) } },

            }) {}
            CLAY_AUTO_ID({
                .custom = { .customData = &tailOuterBoxRight },
                .floating = {
                    .zIndex = 0,
                    .attachTo = CLAY_ATTACH_TO_ELEMENT_WITH_ID,
                    .parentId = CLAY_IDI("OuterBubble", index).id,
                    .attachPoints = { .element = CLAY_ATTACH_POINT_RIGHT_TOP, .parent = CLAY_ATTACH_POINT_LEFT_TOP },
                    .offset = { 6, 30 },
                },
                .layout = { .sizing = { CLAY_SIZING_FIXED(40), CLAY_SIZING_FIXED(22) } },
            }) {}
            
            CLAY(CLAY_IDI("InnerBubble", index), {
                .custom = { .customData = &messageInnerBox},
                .floating = {
                    .zIndex = 0,
                },
                .layout = {
                    .sizing = {CLAY_SIZING_GROW(), CLAY_SIZING_FIT()},
                    .padding = {16, 16, 16, 16},
                }
            }){
                CLAY_AUTO_ID({
                    .floating = {
                        .zIndex = 0,
                        .attachTo = CLAY_ATTACH_TO_ELEMENT_WITH_ID,
                        .parentId = CLAY_IDI("InnerBubble", index).id,
                        .attachPoints = { .element = CLAY_ATTACH_POINT_RIGHT_TOP, .parent = CLAY_ATTACH_POINT_LEFT_TOP },
                        .offset = { -20, 20 },
                    },
                    .layout = { .sizing = { CLAY_SIZING_FIXED(30), CLAY_SIZING_FIXED(12) } },
                    .custom = { .customData = &tailInnerBoxLeft }
                }) {}
                CLAY_AUTO_ID({
                    .floating = {
                        .zIndex = 0,
                        .attachTo = CLAY_ATTACH_TO_ELEMENT_WITH_ID,
                        .parentId = CLAY_IDI("InnerBubble", index).id,
                        .attachPoints = { .element = CLAY_ATTACH_POINT_RIGHT_TOP, .parent = CLAY_ATTACH_POINT_LEFT_TOP },
                        .offset = { 0, 25 },
                    },
                    .layout = { .sizing = { CLAY_SIZING_FIXED(30), CLAY_SIZING_FIXED(15) } },
                    .custom = { .customData = &tailInnerBoxRight }
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