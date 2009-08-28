#ifndef _MTG_CARD_INSTANCE_H_
#define _MTG_CARD_INSTANCE_H_

#include "MTGCard.h"
#include "MTGGameZones.h"
#include "MTGAbility.h"
#include "TexturesCache.h"
#include "ManaCost.h"
#include "Blocker.h"
#include "Damage.h"
#include "Targetable.h"


class MTGCardInstance;
class MTGPlayerCards;
class MTGAbility;
class MTGCard;
class TexturesCache;
class ManaCost;
class UntapBlockers;
class CardDescriptor;
class Counters;
struct Pos;

#include <list>
using namespace std;

class MTGCardInstance: public MTGCard, public Damageable {
 protected:
  int untapping;
  int nb_damages;
  string sample;
  int tapped;

  int lifeOrig;
  UntapBlockers * untapBlockers;
  MTGPlayerCards * belongs_to;
  MTGAbility * untapBlockerAbilities[10];
  void unband();
  MTGCardInstance * getNextPartner();
  void initMTGCI();
  int setDefenser(MTGCardInstance * c);
  int setAttacker(int value);
 public:
  Pos* view;
  int regenerateTokens;
  bool isToken;
  int stillInUse();
  Player * lastController;
  MTGGameZone * getCurrentZone();
  MTGGameZone * previousZone;
  MTGCardInstance * previous;
  MTGCardInstance * next;
  int doDamageTest;
  int summoningSickness;
  // The recommended method to test for summoning Sickness !
  int hasSummoningSickness();
  MTGCardInstance * changeController(Player * newcontroller);
  float changedZoneRecently;
  Player * owner;
  Counters * counters;
  int typeAsTarget(){return TARGET_CARD;}
  const string getDisplayName();
  MTGCardInstance * target;
  void addType(int type);

  //Combat
  MTGCardInstance * defenser;
  list<MTGCardInstance *>blockers;
  int attacker;
  int toggleDefenser(MTGCardInstance * opponent);
  int raiseBlockerRankOrder(MTGCardInstance * blocker);
  int bringBlockerToFrontOfOrder(MTGCardInstance * blocker);
  int toggleAttacker();
  MTGCardInstance * banding; // If belongs to a band when attacking
  int canBlock();
  int canBlock(MTGCardInstance * opponent);
  int canAttack();
  int isAttacker();
  MTGCardInstance * isDefenser();
  int initAttackersDefensers();
  MTGCardInstance * getNextOpponent(MTGCardInstance * previous=NULL);
  MTGCardInstance * getNextDefenser(MTGCardInstance * previous=NULL);
  int nbOpponents();

  int afterDamage();

  int has(int ability);
  int cleanup();
  int reset();


  MTGCard * model;
  MTGCardInstance();
  MTGCardInstance(MTGCard * card, MTGPlayerCards * _belongs_to);
  UntapBlockers * getUntapBlockers();
  int regenerate();
  int triggerRegenerate();
  Player * controller();

  ~MTGCardInstance();
  int bury();
  int destroy();


  int addToToughness(int value);
  int setToughness(int value);

  CardDescriptor * protections[10];
  int nbprotections;
  int addProtection(CardDescriptor * cd);
  int removeProtection(CardDescriptor *cd, int erase = 0);
  int protectedAgainst(MTGCardInstance * card);
  void copy(MTGCardInstance * card);
  // in game

  void setUntapping();
  int isUntapping();
  int isTapped();
  void untap();
  void tap();
  void attemptUntap();

  int isInPlay();
  void resetAllDamage();
  JSample * getSample();
};




#endif
