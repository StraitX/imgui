#include "imgui/widgets.hpp"
#include "core/string.hpp"

namespace ImGui {

void DockspaceWindow(const char *name, Vector2s window_size) {
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

    ImGui::SetNextWindowSize(ImVec2(window_size.x, window_size.y));
    ImGui::SetNextWindowPos({0, 0});
    ImGuiWindowFlags flags = 0;
    flags |= ImGuiWindowFlags_NoTitleBar;
    flags |= ImGuiWindowFlags_NoResize;
    flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
    flags |= ImGuiWindowFlags_NoMove;

    String dockspace_name = "##__" + String(name) + "__Dockspace";

    ImGui::Begin(name, nullptr, flags);
    {
        ImGui::DockSpace(ImGui::GetID(dockspace_name.Data()));
    }
    ImGui::End();

    ImGui::PopStyleVar(2);
}

}//namepsace ImGui::
