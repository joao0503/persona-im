#ifndef PERSONA_THEME_H
#define PERONSA_THEME_H

#include "clay.h"

#define FONT_ID_BODY_16 0

#define P5_COLOR_RED (Clay_Color) {213, 0, 28, 255}
#define P5_COLOR_BLACK (Clay_Color) {20, 20, 20, 255}
#define P5_COLOR_WHITE (Clay_Color) {255, 255, 255, 255}

extern Clay_LayoutConfig layout_centered;

void RenderBackground();
void RenderPhoneMenu(bool *isOpen);
void RenderChatMessage(Clay_String name, Clay_String message);


#endif // PERSONA_THEME_H