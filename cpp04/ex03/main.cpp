#include "Character.hpp"
#include "Monster.hpp"
#include "Ice.hpp"
#include "Shield.hpp"
#include "Cure.hpp"
#include "Boost.hpp"
#include "Bite.hpp"
#include "MateriaSource.hpp"

int main()
{
	//creating a monster, a party to fight it, and their grimoire
	std::cout << "--------------Creation break ----------------" << std::endl << std::endl;
	ICharacter *monster = new Monster("Monster", 60, 0, 50);
	ICharacter *Cleric = new Character("Cleric", 2, 3, 0);
	ICharacter *Wizard = new Character("Wizard", 4, 1, 0);
	ICharacter *Warlock = new Character("Warlock", 3, 0, 2);
	ICharacter *Fighter = new Character("Fighter", 5, 0, 0);
	IMateriaSource *Grimoire = new MateriaSource();
	std::cout << std::endl << "---------------------------------------------"<< std::endl << std::endl;
	
	//filling the grimoire with all available types of spell
	std::cout << "--------------learning break (grimoire)------" << std::endl << std::endl;
	AMateria *tmp = new Ice();
	Grimoire->learnMateria(tmp);
	tmp = new Cure();
	Grimoire->learnMateria(tmp);
	tmp = new Shield();
	Grimoire->learnMateria(tmp);
	tmp = new Boost();
	Grimoire->learnMateria(tmp);
	std::cout << std::endl << "------------plus full inventory test---------"<< std::endl << std::endl;
	
	//one too many
	tmp = new Boost();
	Grimoire->learnMateria(tmp);
	delete tmp;
	
	std::cout << std::endl << "---------------------------------------------"<< std::endl << std::endl;
	
	//characters learn their spells
	std::cout << "-------spell learning break (characters)-----"<< std::endl << std::endl;
	Fighter->equip(Grimoire->createMateria("ice"));
	Cleric->equip(Grimoire->createMateria("cure"));
	Cleric->equip(Grimoire->createMateria("ice"));
	Warlock->equip(Grimoire->createMateria("shield"));
	Warlock->equip(Grimoire->createMateria("ice"));
	Wizard->equip(Grimoire->createMateria("ice"));
	Wizard->equip(Grimoire->createMateria("cure"));
	Wizard->equip(Grimoire->createMateria("boost"));
	std::cout << std::endl << "-----------------(+monster)------------------"<< std::endl << std::endl;
	
	//monster learns his own attack
	tmp = new Bite();
	monster->equip(tmp);
	std::cout << std::endl << "---------------------------------------------"<< std::endl << std::endl;
	
	//now the fighting starts !!
	std::cout << "-------------fighting begins !!!!------------"<< std::endl << std::endl;
	std::cout << "Our party has been tasked with chasing the monster haunting the forest of the east.\nThey approach with caution, taking a careful detour along the river...\nBut their caution betrays them, as from the unassuming, clear waters emerges a massive, eel-like creature. Its body is three times as thick as a tree trunk, and covered in glistening scales beside - the sunlight reflects off it like glitter as it slithers forth, blinding the party before they can react.\nSpeechless, the Wizard raises their hands to cast, but before they can call upon their magic a huge, soulless eye catches the movement and hones in on them.\nWith its target acquired, the ";
	monster->use(0, *Wizard);
	
	std::cout << std::endl << "Devastated, the fighter rushes to their side, though too late to help in any way. Already the blood is pouring from their wounds, the light leaving their eyes. They slur their words as they say their goodbyes.\n \"I knew the risks,\" he reminds them. \"I'm glad to die surrounded by you all.\"\nAnd, unwilling to let his knowledge die with him, the wizard uses their dying breath to share with the fighter an ancient spell taught through generations of wizardry scholars, known to pack enough endurance to survive the end-of-the-year exam rush -- at a cost.\n";
	Wizard->gift(2, *Fighter);
	
	std::cout << std::endl << "The Warlock, sensing the beast might be tempted to attack where it's already struck, rushes to plant themselves in the creature's field of sight, and casts a defensive spell loud and bright to attract its attention to their position.\n";
	Warlock->use(0, *Warlock);
	
	std::cout << std::endl << "The distraction buys the Cleric just enough time to signal the Fighter to a joint attack on the beast's eyes, two strikes delivered back-to-back to stun the creature's senses.\n";
	Cleric->use(1, *monster);
	Fighter->use(0, *monster);
	
	std::cout << std::endl << "Enraged, the creature tries to go for the Warlock's throat -- but with its left eye sunken under the weight of quickly expanding ice crystals, it misses, giving them just enough time to cast a second protection spell.\n";
	Warlock->use(0, *Warlock);
	
	std::cout << std::endl << "Its second attempt, however, is still successfull. With its long, bright teeth in full display, ";
	monster->use(0, *Warlock);
	
	//okay, i fixed the defense from shield a bit, cause it got exponentially unmanageable
	//next up, warlock shields fighter, cleric attacks, fighter is hit
	//cleric goes to heal warlock's wounds but gets hit and dies; warlock screams out of anger, attracts their ire. goes to protect themselves but is out of stamina, monster hits them and they die.
	//fighter finishes the fight on their own, death by a thousand cuts type beat
	
	std::cout << std::endl << "---------------------------------------------"<< std::endl << std::endl;
	
	std::cout << "-------------destruction break---------------"<< std::endl << std::endl;
	delete Wizard;
	delete Warlock;
	delete Fighter;
	delete Cleric;
	delete monster;
	delete Grimoire;
}
