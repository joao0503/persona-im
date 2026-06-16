#include "clay.h"
#include "headers/persona_theme.h"

void InstantMessageBoxComponent (Clay_String messageText, int index) {
    static CustomLayoutElement avatarOuterBox = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_BLACK,
            .topLeft = {-20, -10}, .topRight = {4, 0},
            .bottomLeft = {10, 20}, .bottomRight = {24, 6}
        }
    };

    static CustomLayoutElement avatarInnerBox = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_WHITE,
            .topLeft = {-6, -4}, .topRight = {0, 2},
            .bottomLeft = {20, 8}, .bottomRight = {14, 2}
        }
    };

    static CustomLayoutElement avatarInnerColor = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_AVATAR_RYUJI,
            .topLeft = {0, 4}, .topRight = {-4, 4},
            .bottomLeft = {24, 4}, .bottomRight = {12, -2}
        }
    };

    static CustomLayoutElement messageOuterBox = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_WHITE,
            .topLeft = {0, 0}, .topRight = {28, -10},
            .bottomLeft = {-25, 10}, .bottomRight = {0, 20}
        }
    };
    static CustomLayoutElement messageInnerBox = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_BLACK,
            .topLeft = {0, 0}, .topRight = {15, -10},
            .bottomLeft = {-20, 10}, .bottomRight = {0, 20}
        }
    };

    static CustomLayoutElement tailOuterBoxLeft = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_WHITE,
            .topLeft = {-26, 24}, .topRight = {-20, 16},
            .bottomLeft = {-46, 44}, .bottomRight = {-14, 36}
        }
    };

    static CustomLayoutElement tailOuterBoxRight = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_WHITE,
            .topLeft = {-38, 36}, .topRight = {-10, 20},
            .bottomLeft = {-34, 50}, .bottomRight = {-10, 46}
        }
    };

    static CustomLayoutElement tailInnerBoxLeft = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_BLACK,
            .topLeft = {-40, 12}, .topRight = {-38, 6},
            .bottomLeft = {-56, 24}, .bottomRight = {-32, 16}
        }
    };

    static CustomLayoutElement tailInnerBoxRight = {
        .type = CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
        .customData.polygon = {
            .color = P5_COLOR_BLACK,
            .topLeft = {-44, 16}, .topRight = {-16, 4},
            .bottomLeft = {-40, 28}, .bottomRight = {-12, 16}
        }
    };


    CLAY_AUTO_ID({
        //.border = { .width = {2, 2, 2, 2, 0}, .color = {0, 255, 0, 255},},
        .layout = {
            .layoutDirection = CLAY_LEFT_TO_RIGHT,
            .childAlignment = { .y = CLAY_ALIGN_Y_BOTTOM },
            .childGap = 40,
        }   
    }){
        CLAY(CLAY_IDI("AvatarGroup", index), {
            //.border = { .width = {1, 1, 1, 1, 0}, .color = {0, 255, 0, 255},},
            .layout = {
                .sizing = {CLAY_SIZING_FIXED(80), CLAY_SIZING_FIXED(50)},
            },
        }){
            CLAY_AUTO_ID({
                .custom = { .customData = &avatarOuterBox },
                .layout = {
                    .sizing = {CLAY_SIZING_GROW(), CLAY_SIZING_GROW()},
                },
            }) {
                    CLAY_AUTO_ID({
                    .custom = { .customData = &avatarInnerBox },
                    .layout = {
                        .sizing = {CLAY_SIZING_GROW(), CLAY_SIZING_GROW()},
                    },
                }) {
                        CLAY_AUTO_ID({
                        .custom = { .customData = &avatarInnerColor },
                        .layout = {
                            .sizing = {CLAY_SIZING_GROW(), CLAY_SIZING_GROW()},
                        },
                    }) {}
                }
            }
        }

        CLAY(CLAY_IDI("MessageGroup", index), {
            .layout = {
                .layoutDirection = CLAY_LEFT_TO_RIGHT,
            },
        }) {
            CLAY(CLAY_IDI("OuterBubble", index), {
                //.border = { .width = {2, 2, 2, 2, 0}, .color = {0, 255, 0, 255},},
                .custom = { .customData = &messageOuterBox},
                .layout = {
                    .sizing = {CLAY_SIZING_FIXED(280), CLAY_SIZING_FIT()},
                    .padding = {4, 4, 4, 4},
                },
            }) {
                CLAY_AUTO_ID({
                    .custom = { .customData = &tailOuterBoxLeft },
                    .layout = { .sizing = { CLAY_SIZING_FIXED(0), CLAY_SIZING_FIXED(0) } },
                }) {}
                CLAY_AUTO_ID({
                    .custom = { .customData = &tailOuterBoxRight },
                    .layout = { .sizing = { CLAY_SIZING_FIXED(0), CLAY_SIZING_FIXED(0) } },
                }) {}
                
                CLAY(CLAY_IDI("InnerBubble", index), {
                    //.border = { .width = {2, 2, 2, 2, 0}, .color = {0, 255, 0, 255},},
                    .custom = { .customData = &messageInnerBox },
                    .layout = {
                        .sizing = {CLAY_SIZING_GROW(), CLAY_SIZING_FIT()},
                        .padding = {16, 16, 16, 16},
                    }
                }) {
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
}