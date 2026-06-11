#ifndef CLAY_RENDERER_RAYLIB_H
#define CLAY_RENDERER_RAYLIB_H

#include "raylib.h"
#include "clay.h"

typedef enum
{
    CUSTOM_LAYOUT_ELEMENT_TYPE_3D_MODEL,
    CUSTOM_LAYOUT_ELEMENT_TYPE_POLYGON,
} CustomLayoutElementType;

typedef struct
{
    Model model;
    float scale;
    Vector3 position;
    Matrix rotation;
} CustomLayoutElement_3DModel;

typedef struct
{
    Clay_Color color;
    Vector2 topLeft;
    Vector2 topRight;
    Vector2 bottomLeft;
    Vector2 bottomRight;
} CustomLayoutElement_Polygon;

typedef struct
{
    CustomLayoutElementType type;
    union {
        CustomLayoutElement_3DModel model;
        CustomLayoutElement_Polygon polygon;
    } customData;
} CustomLayoutElement;

// Funções públicas do renderer
void Clay_Raylib_Render(Clay_RenderCommandArray renderCommands, Font* fonts);
void Clay_Raylib_Initialize(int width, int height, const char *title, unsigned int flags);
void Clay_Raylib_Close();
static inline Clay_Dimensions Raylib_MeasureText(Clay_StringSlice text, Clay_TextElementConfig *config, void *userData);

#endif
