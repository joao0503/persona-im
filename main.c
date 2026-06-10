#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "renderer/raylib/clay_renderer_raylib.c"
#include "headers/persona_theme.h"

void HandleClayErrors(Clay_ErrorData errorData) {
    printf("%s", errorData.errorText.chars);
}

int main() {
    InitWindow(800, 600, "Persona 5 Cellphone");

    uint64_t clayRequiredMemory = Clay_MinMemorySize();
    Clay_Arena clayMemory = Clay_CreateArenaWithCapacityAndMemory(clayRequiredMemory, malloc(clayRequiredMemory));

    Clay_Initialize(clayMemory, (Clay_Dimensions) {
        .width = GetScreenWidth(),
        .height = GetScreenHeight()
    },
    (Clay_ErrorHandler) {HandleClayErrors});

    Font fonts[10];
    fonts[FONT_ID_BODY_16] = LoadFontEx("fonts/optima_nova_black.ttf", 48, 0, 400);
    Clay_SetMeasureTextFunction(Raylib_MeasureText, fonts);

    while (!WindowShouldClose()) {

        Clay_SetLayoutDimensions((Clay_Dimensions) {GetScreenWidth(), GetScreenHeight()});
        Clay_SetPointerState((Clay_Vector2) {GetMousePosition().x, GetMousePosition().y}, IsMouseButtonDown(0));

        Clay_BeginLayout();
            CLAY(
                CLAY_ID("Main"), {
                    .backgroundColor = P5_COLOR_RED,
                    .layout = {
                        .padding = {16, 16, 16, 16}
                    }
                }) {
                    CLAY_TEXT(CLAY_STRING("HELLO WORLD!"), {
                        .fontSize = 24,
                        .textColor = {255, 255, 255, 255}
                    });
                }

        Clay_RenderCommandArray renderCommands = Clay_EndLayout(GetFrameTime());

        BeginDrawing();
        ClearBackground(BLACK);
        Clay_Raylib_Render(renderCommands, fonts);
        EndDrawing();
    }
}