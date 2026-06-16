#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "renderer/raylib/clay_renderer_raylib.c"
#include "headers/persona_theme.h"
#include "headers/components.h"

void HandleClayErrors(Clay_ErrorData errorData) {
    printf("%s", errorData.errorText.chars);
}

int main() {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
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
    fonts[FONT_ID_BODY_MESSAGETEXT] = LoadFontEx("fonts/optima_nova_black.ttf", FONT_SIZE, 0, 400);
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
                        .sizing = layoutExpand,
                        .padding = CLAY_PADDING_ALL(16),
                    },
                }
            ){
                CLAY(
                    CLAY_ID("Content"), {
                        .layout = {
                            .sizing = layoutExpand,
                        },
                        .border = {
                            .width = {1, 1, 1, 1, 0},
                            .color = P5_COLOR_BLACK,
                        }
                    },  
                ){
                    CLAY(
                        CLAY_ID("Instant Message"), {
                            .layout = {
                                .layoutDirection = CLAY_TOP_TO_BOTTOM,
                                .sizing = layoutExpand,
                                .childAlignment = {CLAY_ALIGN_X_LEFT, CLAY_ALIGN_Y_TOP},
                                .childGap = 52,
                            }
                        }
                    ){
                        InstantMessageBoxComponent(CLAY_STRING("Hello, you're back, and in one piece."), 1);
                        InstantMessageBoxComponent(CLAY_STRING("Hello, you're back, and in one piece."), 2);
                        InstantMessageBoxComponent(CLAY_STRING("Hello, you're back, and in one piece."), 3);
                        InstantMessageBoxComponent(CLAY_STRING("Hello, you're back, and in one piece."), 4);
                    }
                }
            }

        Clay_RenderCommandArray renderCommands = Clay_EndLayout(GetFrameTime());

        BeginDrawing();
        ClearBackground(BLACK);
        Clay_Raylib_Render(renderCommands, fonts);
        EndDrawing();
    }
}