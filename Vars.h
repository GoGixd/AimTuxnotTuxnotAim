#pragma once

struct Variables
{
	Variables()
	{ }
}

namespace Settings
{
	namespace Ragebot
	{
		bool Enabled;
		bool AutoFire;
		bool Hold;
		int HoldKey;
		int Filter; // will hold flags for team/enemy/etc.
		bool Silent;
		bool RCS;
		bool VisCheck;
		bool AutoWall;
		float AutoWallDmg;
		int TargetMethod;
		int Hitbox;
		float FOV;
		bool HitChance;
		float HitChanceAmt;
		bool AutoStop;
		bool AutoCrouch;
		bool FriendlyFire;
		bool Aimstep;
		float AimstepAmount;
		bool HitScanAll;
		bool HitScanHitbox;
		bool UntrustedCheck;

		namespace Antiaim
		{
			bool Enabled;
			int Pitch;
			int Yaw;
			bool AimAtPlayer;
			bool DetectEdge;
			bool PSilent;
		}
	}

	namespace Legitbot
	{
		namespace Aimbot
		{
			bool Enabled;
			int Key;
			bool OnKey;
			int Filter; // will hold flags for team/enemy/etc.
			bool RCS;
			float RCSAmount;
			float Speed;
			bool VisCheck;
			int Hitbox;
			float FOV;
			bool AlwaysOn;
			bool FriendlyFire;
		}

		namespace Triggerbot
		{
			bool Enabled;
			bool AutoFire;
			int Key;
			bool HitChance;
			float HitChanceAmt;
		}
		namespace Filters
		{
			bool Head;
			bool Chest;
			bool Stomach;
			bool Arms;
			bool Legs;
			bool Friendly;
		}
	}

	namespace Visuals
	{
		namespace ESP
		{
			bool Enabled;
			bool Box;
			int BoxType;
			bool Skeleton;
			bool Dlights;
			bool Glow;
			bool BulletTrace;
			float BulletTraceLength;
			bool CrosshairOn;
			int CrosshairType;
			int CrosshairStyle;
			float TeamColor[3];
			float TeamColorWall[3];
			float EnemyColor[3];
			float EnemyColorWall[3];

			namespace Filters
			{
				bool Enemies;
				bool Friendlies;
				bool Weapons;
				bool Decoy;
				bool C4;
			}

			namespace Information
			{
				bool Name;
				bool Health;
				bool Weapon;
				bool Flashed;
			}
		}

		namespace Chams
		{
			bool Enabled;
			int Mode;
			bool Wireframe;
			bool XQZ;
			float TeamColor[3];
			float TeamColorWall[3];
			float EnemyColor[3];
			float EnemyColorWall[3];
		}

		namespace Removals
		{
			bool Hands;
			bool Weapon;
			bool VisualRecoil;
			bool Flash;
			bool Smoke;
			bool Sky;
		}
	}

	namespace Misc
	{
		bool Bhop;
		bool AutoStrafe;
		bool ChatSpam;
		int ChatSpamMode;
		bool Watermark;
		bool Ranks;
		bool AirStuck;
		int AirStuckKey;
		bool AutoAccept;
	}

	namespace Menu
	{
		bool Opened = false;
		int Key;
		bool Ragebot = false;
		bool Legitbot = false;
		bool Visual = false;
		bool Misc = false;
	}
}

extern Variables Vars;
