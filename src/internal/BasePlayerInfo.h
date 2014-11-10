#ifndef __TANKGAME_BASEPLAYERINFO__
#define __TANKGAME_BASEPLAYERINFO__

#include "../IPlayerInfo.h"
#include "BaseTank.h"
#include "BaseHeadquarter.h"
#include <vector>

class BasePlayerInfo : public IPlayerInfo {
public:
  #pragma region IPlayerInfoImplementation
  char getPlayerMapID() const;

  std::list<ITank*> getAliveTanks() const;
  std::list<ITank*> getDeadTanks() const;
  std::pair<int, int> getHeadquarterPosition() const;
  IHeadquarter* getHeadquarter() const;

  CommandInfo getLastMove() const;

  bool isPlayable() const;
  #pragma endregion

  #pragma region ModelPreservedInterface
  bool isOwnerOf(const BaseTank* tank) const;

  bool removeTank(BaseTank* tank);

  bool getHit(BaseTank* tank);
  bool getHit(const std::pair<int,int>& pos, BaseTank*& tank);

  void updateLastMove(const CommandInfo& cmd);

  void addHeadquarter(BaseHeadquarter* head);
  void addTank(int hp, int ammo, int range, std::pair<int,int> pos);

  BasePlayerInfo(char id);
  ~BasePlayerInfo();
  #pragma endregion

private:
  char _mapID;
  CommandInfo _lastMove;
  std::list<ITank*> _aliveTanks;
  std::list<ITank*> _deadTanks;
  std::vector<BaseTank*> _baseTanks;
  BaseHeadquarter* _headquarter;
};

#endif