#include "Includes.h"

cGlow *pGlow = new cGlow();

cGlow::cGlow()
{

}

cGlow::~cGlow()
{

}


void cGlow::GlowEsp()
{

	for (int i = 0; i < 64; i++)
	{
		bool glow_currentPlayerDormant = Mem->Read<bool>(pLocalPlayer->getGlowCurrentPlayer(i) + Dormant);
		int glow_currentPlayerGlowIndex = Mem->Read<int>(pLocalPlayer->getGlowCurrentPlayer(i) + GlowIndex);
		int EntityBaseTeamID = Mem->Read<int>(pLocalPlayer->getGlowCurrentPlayer(i) + teamOffset);

		if (glow_currentPlayerDormant == true || EntityBaseTeamID == false)
			continue;
		else
			if (pLocalPlayer->getLocalTeam() != EntityBaseTeamID || GlowTeamCheck == false)
				switch (EntityBaseTeamID)
				{
				case 2:
					//MEIA VIDA
					Mem->Write<float>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x4)), GlowTerroristRed);
					//Visivel
					Mem->Write<float>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x8)), GlowTerroristGreen);
					//Não visivel
					Mem->Write<float>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0xC)), GlowTerroristBlue);
					//Is alpha
					Mem->Write<float>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x10)), GlowTerroristAlpha);
					Mem->Write<BOOL>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x24)), true);
					Mem->Write<BOOL>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x25)), false);
					break;
				case 3:
					//Meia vida
					Mem->Write<float>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x4)), GlowCounterTerroristRed);
					//Visivel
					Mem->Write<float>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x8)), GlowCounterTerroristGreen);
					//Não visivel
					Mem->Write<float>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0xC)), GlowCounterTerroristBlue);
					//is alpha
					Mem->Write<float>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x10)), GlowCounterTerroristAlpha);
					Mem->Write<BOOL>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x24)), true);
					Mem->Write<BOOL>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x25)), false);
					break;
				}
	}

}


