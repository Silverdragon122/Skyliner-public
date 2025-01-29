#include "lib.hpp"
#include "imgui_backend/imgui_impl_nvn.hpp"
#include "patches.hpp"
#include "helpers/PlayerHelper.h"
#include "imgui_nvn.h"

#include <basis/seadRawPrint.h>

#include <game/StageScene/StageScene.h>
#include <game/System/GameSystem.h>
#include <game/System/Application.h>
#include <game/HakoniwaSequence/HakoniwaSequence.h>
#include <exception/ExceptionHandler.h>
#include <game/GameData/GameDataFunction.h>
#include <helpers/InputHelper.h>
#include <stage_warp.hpp>
#include <game/Player/Actions/PlayerActionGroundMoveControl.h>
#include <al/Library/LiveActor/ActorMovementFunction.h>

#include "rs/util.hpp"
#include "file_redirection.h"
#include "logger/Logger.hpp"


#define IMGUI_ENABLED true
bool isPlayerModificationsOpen = false;
void drawSkylinerMain() {
    HakoniwaSequence *gameSeq = (HakoniwaSequence *) GameSystemFunction::getGameSystem()->mCurSequence;
    static bool is_open = true;
    static bool playerWindowOpen = false;
    static bool warpWindowOpen = false;
    static bool isPlayerModWindow = false;
    static float marSpeed = 1.0;
    sead::Vector3f velocity(marSpeed, 0.0 , 0.0 );

    ImGui::Begin("Skyliner V1.0", &is_open, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
    ImGui::SetWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
    ImGui::SetWindowSize(ImVec2(450, 600), ImGuiCond_FirstUseEver);
    auto curScene = gameSeq->mStageScene;

    bool isInGame = curScene && curScene->mIsAlive;

    if (isInGame && !isWarpInProgrees) {
        StageScene *stageScene = gameSeq->mStageScene;
        PlayerActorBase *playerBase = rs::getPlayerActor(stageScene);
        

        if (ImGui::Button("Player Stats")) {
            playerWindowOpen = true;
        }
        if (playerWindowOpen) {
            ImGui::Begin("Player Stats", &playerWindowOpen, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse );
            ImGui::Text("In game, Skyliner active.");
            ImGui::Text("Current Speed: %f", marSpeed);
            ImGui::Text("Coin Count: %d", GameDataFunction::getCoinNum(GameDataHolderAccessor(stageScene)));
            ImGui::Text("Purple Coin Count: %d", GameDataFunction::getCoinCollectNum(GameDataHolderAccessor(stageScene)));
            ImGui::Text("Current Stage: %s", getEnglishName(GameDataFunction::getCurrentStageName(GameDataHolderAccessor(stageScene), 0)));

            ImGui::Text("Press the L stick down to exit.");

            ImGui::End();
        }
        if (ImGui::Button("Stage Warp")) {
            warpWindowOpen = true;
        }


        if (ImGui::Button("Player Modifications")) {
            isPlayerModificationsOpen = true;

        }


        if (isPlayerModificationsOpen) {
            ImGui::Begin("Player mods", &isPlayerModificationsOpen, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
            ImGui::SetWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
            if (ImGui::Button("Damage Player (1 heart)")) {
                PlayerHelper::damagePlayerHelper(playerBase);
            };

            if (ImGui::Button("Kill player")) {
                PlayerHelper::killPlayer(playerBase);
            };

            ImGui::SliderFloat("Mario's acell rate", &marSpeed, 1.0, 10.0);

            velocity = sead::Vector3f(marSpeed, 0.0, 0.0);

            al::addVelocityToFront(playerBase, marSpeed);

            ImGui::End();
        }
        if (warpWindowOpen) {
            drawStageWarpWindow();
        }
        if (InputHelper::isButtonPress(nn::hid::NpadButton::StickL)) {
                Logger::log("Submenu(s) closed.");
                playerWindowOpen = false;
                warpWindowOpen = false;
                isPlayerModificationsOpen = false;
        }

    } else if (isWarpInProgrees) {
        ImGui::Text("Warp in progress!");
        ImGui::Text("Skyliner inactive.");
        if (isInGame) {
            Logger::log("Warp complete - returning to normal operation");
            isWarpInProgrees = false;
        }
    } else {
        ImGui::Text("Not in game");
        ImGui::Text("Skyliner inactive.");
    }

    ImGui::End();
}

HOOK_DEFINE_REPLACE(ReplaceSeadPrint) {
    static void Callback(const char *format, ...) {
        va_list args;
        va_start(args, format);
        Logger::log(format, args);
        va_end(args);
    }
};


extern "C" void exl_main(void *x0, void *x1) {
    /* Setup hooking environment. */
    exl::hook::Initialize();

    handler::installExceptionHandler([](handler::ExceptionInfo &info) {
        handler::printCrashReport(info);
        return false;
    });
    runCodePatches();

    FileRedirection::InstallHooks();
    Logger::instance().init(LOGGER_IP, 3080);

    PlayerHelper::installHooks();

    // ImGui Hooks
#if IMGUI_ENABLED

    nvnImGui::InstallHooks();
    ReplaceSeadPrint::InstallAtOffset(0xB59E28);
    

    // Register draw functions
    nvnImGui::addDrawFunc(drawSkylinerMain);
#endif
}
extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}