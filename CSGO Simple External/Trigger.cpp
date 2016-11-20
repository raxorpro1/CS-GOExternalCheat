#include "Includes.h"

cTrigger *pTrigger = new cTrigger();

cTrigger::cTrigger()
{

}

cTrigger::~cTrigger()
{

}

DWORD cTrigger::getTriggerKey()
{
	return triggerKey;
}

void cTrigger::Trigger()
{	//Trigger com 1ms de delay
	if (pLocalPlayer->getLocalTeam() != pLocalPlayer->getEnemyTeam() && pLocalPlayer->getCrossHairID() > 0 && pLocalPlayer->getEnemyHealth() > 0)
	{
		pAutoPistol->Shoot();
	}
}
