#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "renderer/raylib/clay_renderer_raylib.c"
#include "headers/persona_theme.h"
#include "headers/components.h"

void HandleClayErrors(Clay_ErrorData errorData) {
    printf("%s", errorData.errorText.chars);
}

int main() {
    InitWindow(500, 800, "Persona 5 Instant Messaging");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    uint64_t clayRequiredMemory = Clay_MinMemorySize();
    Clay_Arena clayMemory = Clay_CreateArenaWithCapacityAndMemory(clayRequiredMemory, malloc(clayRequiredMemory));

    Clay_Initialize(clayMemory, (Clay_Dimensions) {
        .width = GetScreenWidth(),
        .height = GetScreenHeight()
    },
    (Clay_ErrorHandler) {HandleClayErrors});

    Font fonts[10];
    fonts[FONT_ID_BODY_MESSAGETEXT] = LoadFontEx("fonts/optima_nova_black.ttf", 16, 0, 400);
    Clay_SetMeasureTextFunction(Raylib_MeasureText, fonts);

    while (!WindowShouldClose()) {

        Clay_SetLayoutDimensions((Clay_Dimensions) {(float)GetScreenWidth(), (float)GetScreenHeight()});
        Clay_SetPointerState((Clay_Vector2) {GetMousePosition().x, GetMousePosition().y}, IsMouseButtonDown(0));

        Clay_Sizing layoutExpand = {
            .width = CLAY_SIZING_GROW(),
            .height = CLAY_SIZING_GROW()
        };

        Clay_BeginLayout();
            CLAY(
                CLAY_ID("Background"), {
                    .backgroundColor = P5_COLOR_RED,
                    .layout = {
                        .sizing = layoutExpand
                    }   
                }
            ){
                CLAY(
                    CLAY_ID("Content"), {
                        .layout = {
                            .sizing = layoutExpand,
                            .padding = {16, 16, 16, 16},
                            .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER}
                        }
                    }
                ){
                    MessageBoxComponent(CLAY_STRING("Hello, you're back, and in one piece."));
                }
            } 

        Clay_RenderCommandArray renderCommands = Clay_EndLayout(GetFrameTime());

        BeginDrawing();
        ClearBackground(BLACK);
        Clay_Raylib_Render(renderCommands, fonts);
        EndDrawing();
    }
}