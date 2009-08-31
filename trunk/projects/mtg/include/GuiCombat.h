#ifndef _GUICOMBAT_H_
#define _GUICOMBAT_H_

#include <vector>
#include "WEvent.h"
#include "CardGui.h"
#include "MTGCardInstance.h"
#include "DamagerDamaged.h"

class GuiCombat : public GuiLayer
{
 protected:
  GameObserver* go;
  DamagerDamaged* active;
  AttackerDamaged* activeAtk;
  static JQuad* ok_quad;
  Pos ok;
  vector<AttackerDamaged*> attackers;
  DamagerDamaged* current;
  enum { BLK, ATK, OK, NONE } cursor_pos;
  CombatStep step;
  void addOne(DefenserDamaged* blocker, CombatStep);
  void removeOne(DefenserDamaged* blocker, CombatStep);
  void reaffectDamage(AttackerDamaged* attacker, CombatStep);
  void remaskBlkViews(AttackerDamaged* before, AttackerDamaged* after);

 public:
  GuiCombat(GameObserver* go);
  ~GuiCombat();
  virtual void Update(float dt);
  virtual void Render();
  virtual bool CheckUserInput(u32 key);
  virtual int receiveEventPlus(WEvent* e);
  virtual int receiveEventMinus(WEvent* e);

  typedef vector<AttackerDamaged*>::iterator inner_iterator;
};

#endif // _GUICOMBAT_H_
