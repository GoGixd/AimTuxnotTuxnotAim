#include "Cheat.h"
#include "Menu.h"

void GUI_Init(IDirect3DDevice9* pDevice);

EndSceneFn oEndScene;

ImColor mainColor = ImColor(54, 54, 54, 255);

void CenterForTab()
{
	int curX;
	int curY;
	int screenWidth;
	int screenHeight;
	I::Engine->GetScreenSize(screenWidth, screenHeight);
	curX = (screenWidth / 2) - (600 / 2);
	curY = (screenHeight / 2) - (55 / 2) - screenHeight / 5.4;
	ImGui::SetNextWindowPos(ImVec2(curX, curY));
}

void RageBotTab()
{
	CenterForTab();
	ImGui::Begin(charenc("Ragebot Settings"), &Vars.Menu.Ragebot, ImVec2(600, 400), 1.0f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
	{
		ImGui::Separator();
		ImGui::Text(charenc("Aimbot"));
		ImGui::Separator();
		ImGui::Checkbox(charenc("Enabled"), &Vars.Ragebot.Enabled);
		ImGui::Combo(charenc("Hold Key"), &Vars.Ragebot.HoldKey, keyNames, ARRAYSIZE(keyNames));
		ImGui::Checkbox(charenc("Hold"), &Vars.Ragebot.Hold);
		ImGui::Checkbox(charenc("Auto Fire"), &Vars.Ragebot.AutoFire);
		ImGui::SliderFloat(charenc("FOV"), &Vars.Ragebot.FOV, 1.f, 180.f, "%.0f");
		ImGui::Checkbox(charenc("Silent Aim"), &Vars.Ragebot.Silent);
		ImGui::Checkbox(charenc("Aim Step"), &Vars.Ragebot.Aimstep);
		ImGui::SliderFloat(charenc("Angle Per Tick"), &Vars.Ragebot.AimstepAmount, 1.f, 180.f, "%.0f");
		ImGui::Separator();

		ImGui::Text(charenc("Target"));
		ImGui::Separator();
		ImGui::Combo(charenc("Mode"), &Vars.Ragebot.TargetMethod, targetMode, ARRAYSIZE(targetMode));
		ImGui::Combo(charenc("Hitbox"), &Vars.Ragebot.Hitbox, aimBones, ARRAYSIZE(aimBones));
		ImGui::Checkbox(charenc("Friendly Fire"), &Vars.Ragebot.FriendlyFire);
		ImGui::Checkbox(charenc("Auto Wall"), &Vars.Ragebot.AutoWall);
		ImGui::SliderFloat(charenc("Min Damage"), &Vars.Ragebot.AutoWallDmg, 0.1f, 120.f, "%.1f");
		ImGui::Checkbox(charenc("Hit Scan Hitbox"), &Vars.Ragebot.HitScanHitbox);
		ImGui::Checkbox(charenc("Hit Scan All"), &Vars.Ragebot.HitScanAll);
		ImGui::Separator();

		ImGui::Text(charenc("Accuracy"));
		ImGui::Separator();
		ImGui::Checkbox(charenc("Auto Stop"), &Vars.Ragebot.AutoStop);
		ImGui::Checkbox(charenc("Auto Crouch"), &Vars.Ragebot.AutoCrouch);
		ImGui::Checkbox(charenc("Hit Chance"), &Vars.Ragebot.HitChance);
		ImGui::SliderFloat(charenc("Amount"), &Vars.Ragebot.HitChanceAmt, 1.f, 100.f, "%.1f");
		ImGui::Separator();

		ImGui::Text(charenc("Anti-Aim"));
		ImGui::Separator();
		ImGui::Checkbox(charenc("Anti-Aim Enabled"), &Vars.Ragebot.Antiaim.Enabled);
		ImGui::Combo(charenc("Pitch"), &Vars.Ragebot.Antiaim.Pitch, antiaimpitch, ARRAYSIZE(antiaimpitch));
		ImGui::Combo(charenc("Yaw"), &Vars.Ragebot.Antiaim.Yaw, antiaimyaw, ARRAYSIZE(antiaimyaw));
		ImGui::Checkbox(charenc("At Players"), &Vars.Ragebot.Antiaim.AimAtPlayer);
		ImGui::Checkbox(charenc("PSilent AA"), &Vars.Ragebot.Antiaim.PSilent);
		ImGui::Separator();

		ImGui::Text(charenc("Anti-Untrust"));
		ImGui::Separator();
		ImGui::Checkbox(charenc("Uncheck if not on Valve server"), &Vars.Ragebot.UntrustedCheck);
	}
	ImGui::End(); //End Ragebot window
}

void LegitBotTab()
{
	CenterForTab();
	ImGui::Begin(charenc("Legitbot Settings"), &Vars.Menu.Legitbot, ImVec2(600, 400), 1.0f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
	{
		ImGui::Separator();
		ImGui::Text(charenc("Aimbot"));
		ImGui::Separator();
		ImGui::Checkbox(charenc("Enable Aimbot"), &Vars.Legitbot.Aimbot.Enabled);
		ImGui::Checkbox(charenc("Always On"), &Vars.Legitbot.Aimbot.AlwaysOn);
		ImGui::Combo(charenc("Aimbot Key"), &Vars.Legitbot.Aimbot.Key, keyNames, ARRAYSIZE(keyNames));
		ImGui::Checkbox(charenc("Aim on Key"), &Vars.Legitbot.Aimbot.OnKey);
		ImGui::Checkbox(charenc("Friendly Fire"), &Vars.Legitbot.Aimbot.FriendlyFire);
		ImGui::Separator();
		ImGui::Combo(charenc("Hitbox"), &Vars.Legitbot.Aimbot.Hitbox, aimBones, ARRAYSIZE(aimBones));
		ImGui::SliderFloat(charenc("FOV"), &Vars.Legitbot.Aimbot.FOV, 0.1f, 45.f, "%.2f");
		ImGui::SliderFloat(charenc("Aim Speed"), &Vars.Legitbot.Aimbot.Speed, 0.1f, 50.f, "%.2f");
		ImGui::SliderFloat(charenc("RCS Amount"), &Vars.Legitbot.Aimbot.RCSAmount, 1.f, 100.f, "%.0f");
		ImGui::Checkbox(charenc("Always on RCS"), &Vars.Legitbot.Aimbot.RCS);
		ImGui::Separator();

		ImGui::Text(charenc("Triggerbot"));
		ImGui::Separator();
		ImGui::Checkbox(charenc("Enable Triggerbot"), &Vars.Legitbot.Triggerbot.Enabled);
		ImGui::Checkbox(charenc("Auto Fire"), &Vars.Legitbot.Triggerbot.AutoFire);
		ImGui::Combo(charenc("Triggerbot Key"), &Vars.Legitbot.Triggerbot.Key, keyNames, ARRAYSIZE(keyNames));
		ImGui::Checkbox(charenc("Hit Chance"), &Vars.Legitbot.Triggerbot.HitChance);
		ImGui::SliderFloat(charenc("Amount"), &Vars.Legitbot.Triggerbot.HitChanceAmt, 1.f, 100.f, "%.0f");
		ImGui::Separator();

		ImGui::Text(charenc("Filter"));
		ImGui::Separator();
		ImGui::BeginChild(charenc("Filter"), ImVec2(ImGui::GetWindowContentRegionWidth() * 0.5f, 19 * 6));
		{
			ImGui::Selectable(charenc(" Head"), &Vars.Legitbot.Triggerbot.Filter.Head);
			ImGui::Selectable(charenc(" Chest"), &Vars.Legitbot.Triggerbot.Filter.Chest);
			ImGui::Selectable(charenc(" Stomach"), &Vars.Legitbot.Triggerbot.Filter.Stomach);
			ImGui::Selectable(charenc(" Arms"), &Vars.Legitbot.Triggerbot.Filter.Arms);
			ImGui::Selectable(charenc(" Legs"), &Vars.Legitbot.Triggerbot.Filter.Legs);
			ImGui::Selectable(charenc(" Friendlies"), &Vars.Legitbot.Triggerbot.Filter.Friendly);
		}
		ImGui::EndChild();
	}
	ImGui::End(); //End Legitbot window
}

void VisualTab()
{
	CenterForTab();
	ImGui::Begin(charenc("Visual Settings"), &Vars.Menu.Visual, ImVec2(600, 400), 1.0f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
	{
		ImGui::Separator();
		ImGui::Text(charenc("Visuals"));
		ImGui::Separator();
		ImGui::Columns(2, charenc("##c1"), false);
		ImGui::Checkbox(charenc("Enable Visuals"), &Vars.Visuals.Enabled);
		ImGui::Checkbox(charenc("Box"), &Vars.Visuals.Box);
		ImGui::Checkbox(charenc("Skeleton"), &Vars.Visuals.Skeleton);
		ImGui::NextColumn();
		ImGui::Checkbox(charenc("Glow"), &Vars.Visuals.Glow);
		ImGui::Checkbox(charenc("Bullet Trace"), &Vars.Visuals.BulletTrace);
		ImGui::Checkbox(charenc("Dlights"), &Vars.Visuals.Dlights);
		ImGui::Columns(1);
		ImGui::SliderFloat(charenc("Trace Length"), &Vars.Visuals.BulletTraceLength, 1.f, 3000.f, "%.0f");

		ImGui::Separator();
		ImGui::Text(charenc("Info"));
		ImGui::Separator();
		ImGui::BeginChild(charenc("info"), ImVec2(ImGui::GetWindowContentRegionWidth() * 0.5f, 19 * 4));
		{
			ImGui::Selectable(charenc(" Name"), &Vars.Visuals.Info.Name);
			ImGui::Selectable(charenc(" Health"), &Vars.Visuals.Info.Health);
			ImGui::Selectable(charenc(" Weapon"), &Vars.Visuals.Info.Weapon);
			ImGui::Selectable(charenc(" Flashed"), &Vars.Visuals.Info.Flashed);
		}
		ImGui::EndChild();
		ImGui::Separator();

		ImGui::Text(charenc("Filter"));
		ImGui::Separator();
		ImGui::BeginChild(charenc("filter"), ImVec2(ImGui::GetWindowContentRegionWidth() * 0.5f, 19 * 5));
		{
			ImGui::Selectable(charenc(" Enemies"), &Vars.Visuals.Filter.Enemies);
			ImGui::Selectable(charenc(" Friendlies"), &Vars.Visuals.Filter.Friendlies);
			ImGui::Selectable(charenc(" Weapons"), &Vars.Visuals.Filter.Weapons);
			ImGui::Selectable(charenc(" Decoy"), &Vars.Visuals.Filter.Decoy);
			ImGui::Selectable(charenc(" C4"), &Vars.Visuals.Filter.C4);
		}
		ImGui::EndChild();
		ImGui::Separator();

		ImGui::Text(charenc("Chams"));
		ImGui::Separator();
		ImGui::Checkbox(charenc("Enable Chams"), &Vars.Visuals.Chams.Enabled);
		ImGui::Combo(charenc("Mode"), &Vars.Visuals.Chams.Mode, chamsMode, ARRAYSIZE(chamsMode));
		ImGui::Checkbox(charenc("XQZ"), &Vars.Visuals.Chams.XQZ);
		ImGui::Checkbox(charenc("Wireframe"), &Vars.Visuals.Chams.Wireframe);
		ImGui::Separator();

		ImGui::Text(charenc("Removals"));
		ImGui::Separator();
		ImGui::Columns(2, charenc("##c2"), false);
		ImGui::Checkbox(charenc("No Hands"), &Vars.Visuals.Removals.Hands);
		ImGui::Checkbox(charenc("No Weapon"), &Vars.Visuals.Removals.Weapon);
		ImGui::NextColumn();
		ImGui::Checkbox(charenc("No Recoil"), &Vars.Visuals.Removals.VisualRecoil);
		ImGui::Checkbox(charenc("No Flash"), &Vars.Visuals.Removals.Flash);
		ImGui::Columns(1);

		ImGui::Text(charenc("Crosshair"));
		ImGui::Separator();
		ImGui::Checkbox(charenc("Crosshair Enabled"), &Vars.Visuals.CrosshairOn);
		ImGui::Combo(charenc("Type"), &Vars.Visuals.CrosshairType, crosshairType, ARRAYSIZE(crosshairType));
		ImGui::Combo(charenc("Style"), &Vars.Visuals.CrosshairStyle, crosshairStyle, ARRAYSIZE(crosshairStyle));
	}
	ImGui::End(); //End Visuals window
}

void MiscTab()
{
	CenterForTab();
	ImGui::Begin(charenc("Misc Settings"), &Vars.Menu.Misc, ImVec2(600, 400), 1.0f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
	{
		ImGui::Separator();
		ImGui::Text(charenc("Movement"));
		ImGui::Separator();
		ImGui::Checkbox(charenc("Bunny Hop"), &Vars.Misc.Bhop);
		ImGui::Checkbox(charenc("Autostrafe"), &Vars.Misc.AutoStrafe);
		ImGui::Separator();

		ImGui::Text(charenc("Custom Name"));
		ImGui::Separator();
		ImGui::PushItemWidth(180);
		static char buf1[128] = "";
		ImGui::InputText(charenc("##Name"), buf1, 128);
		ImGui::SameLine();
		ImGui::PushItemWidth(50);
		if (ImGui::Button(charenc("Change Name")))
			E::Misc->ChangeName(buf1);
		ImGui::Separator();

		ImGui::Text(charenc("Chat Spam"));
		ImGui::Separator();
		ImGui::PushItemWidth(180);
		static char buf2[128] = "";
		ImGui::InputText(charenc("##File"), buf2, 128);
		ImGui::SameLine();
		ImGui::PushItemWidth(50);
		if (ImGui::Button(charenc("Load File")))
			E::Misc->ReadChatspam(buf2);
		ImGui::PushItemWidth(180);
		ImGui::Combo(charenc("Mode"), &Vars.Misc.ChatSpamMode, chatspamMode, ARRAYSIZE(chatspamMode));
		ImGui::Checkbox(charenc("ChatSpam"), &Vars.Misc.ChatSpam);
		ImGui::Separator();
		ImGui::Text(charenc("Random Shit"));
		ImGui::Separator();
		ImGui::Checkbox(charenc("Ranks"), &Vars.Misc.Ranks);
		ImGui::Checkbox(charenc("Auto Accept"), &Vars.Misc.AutoAccept);
		ImGui::Checkbox(charenc("Watermark"), &Vars.Misc.Watermark);
		ImGui::Checkbox(charenc("AirStuck"), &Vars.Misc.AirStuck);
		ImGui::Combo(charenc("AirStuck Key"), &Vars.Misc.AirStuckKey, keyNames, ARRAYSIZE(keyNames));

		ImGui::Separator();
		ImGui::Text(charenc("Netvar Dump"));
		ImGui::Separator();
		if (ImGui::Button(charenc("Save Dump")))
			NetVarManager->DumpNetvars();
	}
	ImGui::End(); //End Misc window
}

long __stdcall Hooks::EndScene(IDirect3DDevice9* pDevice)
{
	if (!G::d3dinit)
		GUI_Init(pDevice);

	H::D3D9->ReHook();

	ImGui::GetIO().MouseDrawCursor = Vars.Menu.Opened;

	ImGui_ImplDX9_NewFrame();

	if (Vars.Menu.Opened)
	{
		int curX;
		int curY;
		int screenWidth;
		int screenHeight;
		I::Engine->GetScreenSize(screenWidth, screenHeight);
		curX = (screenWidth / 2) - (600 / 2);
		curY = (screenHeight / 2) - (55 / 2) - screenHeight / 4;
		ImGui::SetNextWindowPos(ImVec2(curX, curY));
	}

	if (Vars.Menu.Opened)
	{
		int pX, pY;
		I::InputSystem->GetCursorPosition(&pX, &pY);
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos.x = (float)(pX);
		io.MousePos.y = (float)(pY);
		int w, h;

		static int iPage = 0;

		ImGui::Begin(charenc("Team Gamerfood"), &Vars.Menu.Opened, ImVec2(600, 55), 1.0f, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
		{
			const char* tabs[] = {
				"LegitBot",
				"RageBot",
				"Radar",
				"Visuals",
				"Changer",
				"Misc",
			};

			for (int i = 0; i < ARRAYSIZE(tabs); i++)
			{
				ImGui::GetStyle().Colors[ImGuiCol_Button] = ImVec4(
					mainColor.Value.x,
					mainColor.Value.y,
					mainColor.Value.z,
					mainColor.Value.w
				);

				if (ImGui::Button(tabs[i], ImVec2(ImGui::GetWindowSize().x / ARRAYSIZE(tabs) - 9, 38)))
					iPage = i;

				ImGui::GetStyle().Colors[ImGuiCol_Button] = mainColor;

				if (i < ARRAYSIZE(tabs) - 1)
					//windowDrawList->AddLine(ImVec2(ImGui::GetWindowSize().x / ARRAYSIZE(tabs) - 9, 38), ImVec2(ImGui::GetWindowSize().x / ARRAYSIZE(tabs) - 9, 27), ImGuiCol_ButtonActiveLine, 1.0f);
					ImGui::SameLine();
			}

			switch (iPage)
			{
			case 0:
				LegitBotTab();
				break;
			case 1:
				RageBotTab();
				break;
			case 2:
				//TODO: RADAR TAB
				break;
			case 3:
				VisualTab();
				break;
			case 4:
				//TODO: CHANGER TAB
				break;
			case 5:
				MiscTab();
				break;
			}
		}
		ImGui::End(); //End main window
	}

	ImGui::Render();

	return oEndScene(pDevice);
}

ResetFn oReset;

long __stdcall Hooks::Reset(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	if (!G::d3dinit)
		return oReset(pDevice, pPresentationParameters);

	ImGui_ImplDX9_InvalidateDeviceObjects();

	auto hr = oReset(pDevice, pPresentationParameters);
	ImGui_ImplDX9_CreateDeviceObjects();

	return hr;
}

void GUI_Init(IDirect3DDevice9* pDevice)
{
	ImGui_ImplDX9_Init(G::Window, pDevice);

	ImGuiStyle& style = ImGui::GetStyle();
	style.Colors[ImGuiCol_Text] = ImVec4(0.78f, 0.78f, 0.78f, 1.00f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.59f, 0.59f, 0.59f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.13f, 0.13f, 1.00f);
	style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.09f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.04f, 0.04f, 0.04f, 0.88f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.20f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.13f, 0.13f, 0.13f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.24f, 0.40f, 0.95f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.24f, 0.40f, 0.95f, 0.59f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 1.00f, 1.00f, 0.59f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.24f, 0.40f, 0.95f, 1.00f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.24f, 0.40f, 0.95f, 1.00f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.40f, 0.95f, 0.59f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	style.Colors[ImGuiCol_ButtonActiveLine] = ImVec4(0.30f, 0.10f, 0.55f, 1.00f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.24f, 0.40f, 0.95f, 1.00f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.24f, 0.40f, 0.95f, 0.59f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.70f, 0.02f, 0.60f, 0.22f);
	style.Colors[ImGuiCol_CloseButton] = ImVec4(0.24f, 0.40f, 0.95f, 1.00f);
	style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.24f, 0.40f, 0.95f, 0.59f);

	style.WindowRounding = 0.f;
	style.FramePadding = ImVec2(4, 1);
	style.ScrollbarSize = 10.f;
	style.ScrollbarRounding = 0.f;
	style.GrabMinSize = 5.f;

	G::d3dinit = true;
}
