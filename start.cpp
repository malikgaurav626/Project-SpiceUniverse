#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
using namespace std;

// current player stats storage
struct playerData
{
    string playerName;
    string playerClass;
    string playerHome;
    string playerSpecial;
    string playerWeapon;
    int playerHP;
    int playerMaxHP;
    int playerdefense;
    int playerHeals;
    int playerSP;
    int playerSPTurns;
    int playerDMG;
    int playerspice;
} player1;

//player class stats
void warrior()
{
    player1.playerdefense = 17;
    player1.playerHeals = 1;
    player1.playerHP = 137;
    player1.playerMaxHP = 120;
    player1.playerSPTurns = 1;
    player1.playerSpecial = "Bronze Defense";
    player1.playerWeapon = "FireSword";
    player1.playerSP = 12;
    player1.playerDMG = 5;
}
void bandit()
{
    player1.playerdefense = 10;
    player1.playerHeals = 1;
    player1.playerHP = 125;
    player1.playerSpecial = "Sand Overdrive";
    player1.playerWeapon = "CrokedAxe";
    player1.playerSP = 14;
    player1.playerDMG = 7;
    player1.playerMaxHP = 115;
    player1.playerSPTurns = 2;
}
void thief()
{
    player1.playerdefense = 11;
    player1.playerHeals = 0;
    player1.playerHP = 101;
    player1.playerSpecial = "Snatch";
    player1.playerWeapon = "DesertEagle";
    player1.playerSP = 13;
    player1.playerDMG = 9;
    player1.playerMaxHP = 90;
    player1.playerSPTurns = 0;
}
void mage()
{
    player1.playerdefense = 9;
    player1.playerHeals = 2;
    player1.playerHP = 102;
    player1.playerSpecial = "Alpha Eyes";
    player1.playerWeapon = "BloodDagger";
    player1.playerSP = 14;
    player1.playerDMG = 6;
    player1.playerMaxHP = 93;
    player1.playerSPTurns = 3;
}

// current enemy stats storage
struct currentEnemy
{
    int enemyHP;
    int enemyMaxHP;
    int enemyHeals;
    int enemySP;
    int enemySPTurns;
    int enemyDMG;
    string enemySpecial;
} enemy1;

//multiple enemy builds

int enemybuildlvl0()
{
    enemy1.enemyHP=25;
    enemy1.enemyMaxHP=20;
    enemy1.enemyHeals=0;
    enemy1.enemySP=4;
    enemy1.enemyDMG=3;
    enemy1.enemySPTurns=1;
    enemy1.enemySpecial="ReRun";//Special are just for names for now, will be updated soon
    
}
int enemybuildlvl1()
{
    enemy1.enemyHP=48;
    enemy1.enemyMaxHP=40;
    enemy1.enemyHeals=1;
    enemy1.enemySP=50;
    enemy1.enemyDMG=4;
    enemy1.enemySPTurns=1;
    enemy1.enemySpecial="SelmonBhoi'sCar";//Special are just for names for now, will be updated soon
    
}
int enemybuildlvl2()
{
    enemy1.enemyHP=70;
    enemy1.enemyMaxHP=60;
    enemy1.enemyHeals=2;
    enemy1.enemySP=9;
    enemy1.enemyDMG=7;
    enemy1.enemySPTurns=2;
    enemy1.enemySpecial="CloneRush";//Special are just for names for now, will be updated soon
}
int enemybuildlvl3()
{
    enemy1.enemyHP=103;
    enemy1.enemyMaxHP=90;
    enemy1.enemyHeals=3;
    enemy1.enemySP=12;
    enemy1.enemyDMG=9;
    enemy1.enemySPTurns=3;
    enemy1.enemySpecial="System OverDrive";//Special are just for names for now, will be updated soon
    
}

//normal enemy fight mechanics

int fight()
{
    int playermove, enemymove, won, trigger = 0;
    srand(time(0));
    start:

    cout << "Enter you move it's your turn" << endl;
    cin >> playermove;
    if (playermove == 1)
    {
        cout << "Enemy's turn" << endl;
        sleep(2);
        enemymove = 1 + rand() % 5;
        if (enemymove == 2)
        {
            cout << "Enemy selected : Block\n"; sleep(1);
            enemy1.enemyHP -= 2;
            cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
            cout << "Player's HP : [" << player1.playerHP << "]" << endl;
        }
        else if (enemymove == 1)
        {
            cout << "Enemy selected : Hit\n"; sleep(1);
            enemy1.enemyHP -= player1.playerDMG;
            player1.playerHP -= enemy1.enemyDMG;
            cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
            cout << "Player's HP : [" << player1.playerHP << "]" << endl;
        }
        else if (enemymove == 3)
        {
            cout << "Enemy selected : Dodge\n"; sleep(1);
            cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
            cout << "Player's HP : [" << player1.playerHP << "]" << endl;
        }
        else if (enemymove == 4)
        {
            if (enemy1.enemyHeals > 0)
            {
                cout << "Enemy selected : Heal\n";
                sleep(1);
                enemy1.enemyHeals--;
                enemy1.enemyHP += 40;
                if (enemy1.enemyHP > enemy1.enemyMaxHP)
                {
                    enemy1.enemyHP = enemy1.enemyMaxHP;
                }
                cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
                cout << "Player's HP : [" << player1.playerHP << "]" << endl;
            }
            else
            {
                enemy1.enemyHP-=player1.playerDMG;
                cout << "Enemy wasted one move, no heals to use\n";
                cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
                cout << "Player's HP : [" << player1.playerHP << "]" << endl;
            }
        }
        else if (enemymove == 5)
        {
            if (enemy1.enemySPTurns > 0)
            {
                cout << "Enemy selected : Special Move - " << enemy1.enemySpecial << endl;
                sleep(1);
                enemy1.enemySPTurns--;
                player1.playerHP -= enemy1.enemySP;
                enemy1.enemyHP-=player1.playerDMG;
                cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
                cout << "Player's HP : [" << player1.playerHP << "]" << endl;
            }
            else
            {
                enemy1.enemyHP-=player1.playerSP;
                cout << "Enemy wasted one move, no SpTurns\n";
                cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
                cout << "Player's HP : [" << player1.playerHP << "]" << endl;
            }
        }
        if (player1.playerHP <= 0)
        {
            won = 1;
            trigger = 0;
            cout << "You Died!\n";
        }
        else if (enemy1.enemyHP <= 0)
        {
            won = 0;
            trigger = 1;
            cout << "You defeated the enemy!\n";
        }
        else
        {
            goto start;
        }
    }
    else if (playermove == 2)
    {
        cout << "Enemy's turn" << endl;
        sleep(2);
        enemymove = 1 + rand() % 5;
        if (enemymove == 2)
        {
            cout << "Enemy selected : Block\n";
            sleep(1);
            cout << "Enemy wasted one move, block is incompatible with block\n";
        }
        else if (enemymove == 1)
        {
            cout << "Enemy selected : Hit\n"; sleep(1);
            player1.playerHP -= 2;
            cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
            cout << "Player's HP : [" << player1.playerHP << "]" << endl;
        }
        else if (enemymove == 3)
        {
            cout << "Enemy selected : Dodge\n"; sleep(1);
            cout << "Enemy wasted one move, Block is incompatible with Dodge\n";
        }
        else if (enemymove == 4)
        {
            if (enemy1.enemyHeals > 0)
            {
                cout << "Enemy selected : Heal\n";
                sleep(1);
                enemy1.enemyHeals--;
                enemy1.enemyHP += 40;
                if (enemy1.enemyHP > enemy1.enemyMaxHP)
                {
                    enemy1.enemyHP = enemy1.enemyMaxHP;
                }
                cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
                cout << "Player's HP : [" << player1.playerHP << "]" << endl;
            }
            else
            {
                cout << "Enemy wasted one move\n";
            }
        }
        else if (enemymove == 5)
        {
            if (enemy1.enemySPTurns > 0)
            {
                cout << "Enemy selected : Special Move - " << enemy1.enemySpecial << endl;
                sleep(1);
                enemy1.enemySPTurns--;
                player1.playerHP -= enemy1.enemySP;
                cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
                cout << "Player's HP : [" << player1.playerHP << "]" << endl;
            }
            else
            {
                cout << "Enemy wasted one move\n";
            }
        }
        if (player1.playerHP <= 0)
        {
            won = 1;
            trigger = 0;
            cout << "You Died!\n";
        }
        else if (enemy1.enemyHP <= 0)
        {
            won = 0;
            trigger = 1;
            cout << "You defeated the enemy!\n";
        }
        else
        {
            goto start;
        }
    }
    else if (playermove == 3)
    {
        cout << "Enemy's turn" << endl;
        sleep(2);
        enemymove = 1 + rand() % 5;
        if (enemymove == 1)
        {
            cout << "Enemy selected : Hit\n"; sleep(1);
            cout << "You dodged the attack\n";
            cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
            cout << "Player's HP : [" << player1.playerHP << "]" << endl;
        }
        else if (enemymove == 2)
        {
            cout << "Enemy selected : Block\n";
            sleep(1);
            cout << "Enemy wasted one move, Dodge is incompatible with Dodge\n";
        }
        else if (enemymove == 3)
        {
            cout << "Enemy selected : Dodge\n"; sleep(1);
            cout << "Enemy wasted one move, Dodge is incompatible with Dodge\n";
        }
        else if (enemymove == 4)
        {
            if (enemy1.enemyHeals > 0)
            {
                cout << "Enemy selected : Heal\n";
                sleep(1);
                enemy1.enemyHeals--;
                enemy1.enemyHP += 40;
                if (enemy1.enemyHP > enemy1.enemyMaxHP)
                {
                    enemy1.enemyHP = enemy1.enemyMaxHP;
                }
                cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
                cout << "Player's HP : [" << player1.playerHP << "]" << endl;
            }
            else
            {
                cout << "Enemy wasted one move\n";
            }
        }
        else if (enemymove == 5)
        {
            if (enemy1.enemySPTurns > 0)
            {
                cout << "Enemy selected : Special Move - " << enemy1.enemySpecial << endl;
                sleep(1);
                enemy1.enemySPTurns--;
                player1.playerHP -= enemy1.enemySP;
                cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
                cout << "Player's HP : [" << player1.playerHP << "]" << endl;
            }
            else
            {
                cout << "Enemy wasted one move\n";
            }
        }
        if (player1.playerHP <= 0)
        {
            won = 1;
            trigger = 0;
            cout << "You Died!\n";
        }
        else if (enemy1.enemyHP <= 0)
        {
            won = 0;
            trigger = 1;
            cout << "You defeated the enemy!\n";
        }
        else
        {
            goto start;
        }
    }
    else if (playermove == 4)
    {
        if (player1.playerHeals>0){
        player1.playerHeals--;
        player1.playerHP+=40;
        }
        else {
            cout << "You wasted your move, not enough heal available\n";
        }
        if (player1.playerHP>player1.playerMaxHP){
            player1.playerHP=player1.playerMaxHP;
        }
        cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
        cout << "Player's HP : [" << player1.playerHP << "]" << endl;
        sleep(1);
        cout << "Enemy's turn" << endl;
        sleep(2);
        enemymove = 1 + rand() % 5;
        if (enemymove == 1)
        {
            cout << "Enemy selected : Hit\n"; sleep(1);
            player1.playerHP-=enemy1.enemyDMG;
            cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
            cout << "Player's HP : [" << player1.playerHP << "]" << endl;
        }
        else if (enemymove == 2)
        {
            cout << "Enemy selected : Block\n";
            sleep(1);
            cout << "Enemy wasted one move, Block is kinda incompatible with Heal\n";
        }
        else if (enemymove == 3)
        {
            cout << "Enemy selected : Dodge\n"; sleep(1);
            cout << "Enemy wasted one move, Dodge is kinda incompatible with Heal\n";
        }
        else if (enemymove == 4)
        {
            if (enemy1.enemyHeals > 0)
            {
                cout << "Enemy selected : Heal\n";
                sleep(1);
                enemy1.enemyHeals--;
                enemy1.enemyHP += 40;
                if (enemy1.enemyHP > enemy1.enemyMaxHP)
                {
                    enemy1.enemyHP = enemy1.enemyMaxHP;
                }
                cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
                cout << "Player's HP : [" << player1.playerHP << "]" << endl;
            }
            else
            {
                cout << "Enemy wasted one move, no available heals\n";
            }
        }
        else if (enemymove == 5)
        {
            if (enemy1.enemySPTurns > 0)
            {
                cout << "Enemy selected : Special Move - " << enemy1.enemySpecial << endl;
                sleep(1);
                enemy1.enemySPTurns--;
                player1.playerHP -= enemy1.enemySP;
                cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
                cout << "Player's HP : [" << player1.playerHP << "]" << endl;
            }
            else
            {
                cout << "Enemy wasted one move\n";
            }
        }
        if (player1.playerHP <= 0)
        {
            won = 1;
            trigger = 0;
            cout << "You Died!\n";
        }
        else if (enemy1.enemyHP <= 0)
        {
            won = 0;
            trigger = 1;
            cout << "You defeated the enemy!\n";
        }
        else
        {
            goto start;
        }
    }
    else if (playermove == 5)
    {
        cout << "Enemy's turn" << endl;
        sleep(2);
        enemymove = 1 + rand() % 5;
      if (player1.playerSPTurns>0){
        if (enemymove == 1)
        {
            cout << "Enemy selected : Hit\n"; sleep(1);
            if (player1.playerSPTurns>0){
            enemy1.enemyHP-=player1.playerSP;
            player1.playerSPTurns--;
            }
            else {
                cout << "You wasted one move, not enough SP Turns\n";
            }
            player1.playerHP-=enemy1.enemyDMG;
            cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
            cout << "Player's HP : [" << player1.playerHP << "]" << endl;
        }
        else if (enemymove == 2)
        {
            cout << "Enemy selected : Block\n"; sleep(1);
            if (player1.playerSPTurns>0){
            enemy1.enemyHP-=player1.playerSP;
            player1.playerSPTurns--;
            }
            else {
                cout << "You wasted one move, not enough SP Turns\n";
            }
            cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
            cout << "Player's HP : [" << player1.playerHP << "]" << endl;
        }
        else if (enemymove == 3)
        {
            cout << "Enemy selected : Dodge\n"; sleep(1);
            if (player1.playerSPTurns>0){
            enemy1.enemyHP-=player1.playerSP;
            player1.playerSPTurns--;
            }
            else {
                cout << "You wasted one move, not enough SP Turns\n";
            }
            cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
            cout << "Player's HP : [" << player1.playerHP << "]" << endl;
        }
        else if (enemymove == 4)
        {
            
            if (player1.playerSPTurns>0){
            enemy1.enemyHP-=player1.playerSP;
            player1.playerSPTurns--;
            }
            else {
                cout << "You wasted one move, not enough SP Turns\n";
            }
            if (enemy1.enemyHeals > 0)
            {
                cout << "Enemy selected : Heal\n";
                sleep(1);
                enemy1.enemyHeals--;
                enemy1.enemyHP += 40;
                if (enemy1.enemyHP > enemy1.enemyMaxHP)
                {
                    enemy1.enemyHP = enemy1.enemyMaxHP;
                }
                cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
                cout << "Player's HP : [" << player1.playerHP << "]" << endl;
            }
            else
            {
                cout << "Enemy wasted one move\n";
                cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
                cout << "Player's HP : [" << player1.playerHP << "]" << endl;
            }
        }
        else if (enemymove == 5)
        {
            if (enemy1.enemySPTurns > 0)
            {
                cout << "Enemy selected : Special Move - " << enemy1.enemySpecial << endl;
                sleep(1);
                enemy1.enemySPTurns--;
                player1.playerHP -= enemy1.enemySP;
                player1.playerSPTurns--;
                enemy1.enemyHP-= player1.playerSP;
                cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
                cout << "Player's HP : [" << player1.playerHP << "]" << endl;
            }
            else
            {
                cout << "Enemy wasted one move\n";
                enemy1.enemyHP-=player1.playerSP;
                cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
                cout << "Player's HP : [" << player1.playerHP << "]" << endl;
            }
        }
      }
      else {
          if (enemy1.enemySPTurns > 0)
            {
                cout << "Enemy selected : Special Move - " << enemy1.enemySpecial << endl;
                sleep(1);
                enemy1.enemySPTurns--;
                cout << "You wasted a move, not enough SpTurns\n";
                player1.playerHP -= enemy1.enemySP;
                cout << "Enemy's HP : [" << enemy1.enemyHP << "]" << endl;
                cout << "Player's HP : [" << player1.playerHP << "]" << endl;
            }
            else
            {
                cout << "Enemy wasted one move, not enough SpTurns\nYou wasted one move, not enough SpTurns\n";
            }
      }
        if (player1.playerHP <= 0)
        {
            won = 1;
            trigger = 0;
            cout << "You Died!\n";
        }
        else if (enemy1.enemyHP <= 0)
        {
            won = 0;
            trigger = 1;
            cout << "You defeated the enemy!\n";
        }
        else
        {
            goto start;
        }

    }
    else {
        cout << "You entered Wrong Choice\n";
        goto start;
    }
    return trigger;
}

//random enemy generator from 4 differnet stats of enemies
int enemygenerate()
{
    int build;
    srand(time(0));
    build = 1 + rand() % 4;
    if (build == 1)
    {
        enemybuildlvl0();
    }
    else if (build == 2)
    {
        enemybuildlvl1();
    }
    else if (build == 3)
    {
        enemybuildlvl2();
    }
    else if (build == 4)
    {
        enemybuildlvl3();
    }
}
//As the name suggest combatpopup
int combatpopup()
{
    cout << "1 for Hit\n2 for Block\n3 for Dodge\n4 for Heal\n";
}
int rest(){
    player1.playerHP=player1.playerMaxHP;
}

//mining function
int mine(){
    cout << "\t\t\tkeep hitting [enter] to mine\n";
    while (true){
        player1.playerspice++;
        cout << "SpiceCrystals +" << player1.playerspice << endl;
        kbhit();
        cin.get();
        getch();
        system("cls");
        if (player1.playerspice==30){
            cout << "\nMaximum capacity reached";
            break;
        }
    }
}

//Main story of the SpiceUniverse
int main(){
    int t,pathfightvariable,wins;
    initial:

    char a,pathresponse;
    cout << "Warning! new user detected" << endl;
    sleep(1);
    cout << "Deleting Old User Data" << endl;
    sleep(1);
    cout << "Initializing New Sequence";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << "." << endl;
    cout << "Initialization successful" << endl;
    sleep(1);
    cout << "    \t\t\t----- Welcome To The Spice Universe -----" << endl;
    sleep(1);
    cout << "Spice Universe the violent yet happy, barbaric yet soothing, chaotic yet hopeful such a different place\n";
    sleep(1);
    cout << "We hope you enjoy your stay with us\n";
    sleep(1);
    cout << "Enter Your Character's Name : ";
    cin >> player1.playerName;
    sleep(2);
    cout << "\nThe classes in the Spice Universe can decide your fate depending upon the environmnet you're in\n choose your class wisely.\n\n";
    sleep(1);
    cout << "1. [Warrior] : Warrior class will provide your character to have some previous experience in combat and defensive abilities\nThe warrior class provides these different equipment upon starting:\n";
    sleep(1);
    cout << "Primary Weapon: FireSword(5 Dmg)\nNumber of Heals: 1 Heal\nHealth: 120\nDefense: 17\nSpecial Ability: Bronze Defense (12 DMG)\nSpecial Ability Uses: 1\n";
    sleep(2);
    cout << "2. [Bandit] : Bandits class will provide your character to have some combat experience and he's seen some of the stuff we can't even describe\n The bandit class provides these different equipment upon starting:\n";
    sleep(1);
    cout << "Primary Weapon: CrokedAxe(7 Dmg)\nNumber of Heals: 1 Heal\nHealth: 115\nDefense: 10\nSpecial Ability: Spice Rush (14 DMG)\nSpecial Ability Uses: 2\n\n";
    sleep(2);
    cout << "3. [Thief] : Thief class will provide your character to have some stealing and stealth experience and he's always been on his own from the very start\n The Thief class provides these different equipment upon starting:\n";
    sleep(1);
    cout << "Primary Weapon: DesertEagle(9 Dmg)\nNumber of Heals: 0 Heal\nHealth: 90\nDefense: 11\nSpecial Ability: Snatch (13 DMG)\nSpecial Ability Uses: 0\n\n";
    sleep(2);
    cout << "4. [Mage] : Mages class will provide your character to have some magic experience and some knowledge of the old gods\n The mage class provides these different equipment upon starting:\n";
    sleep(1);
    cout << "Primary Weapon: BloodDagger(6 Dmg)\nNumber of Heals: 2 Heal\nHealth: 93\nDefense: 9\nSpecial Ability: Alpha Eyes (14 DMG)\nSpecial Ability Uses: 3\n\n";
    sleep(2);
    cout << "1. [Warrior]\n2. [Bandit]\n3. [Thief]\n4. [Mage]\n \n\nNote: Use the exact words given i.e, for ex. enter -> Warrior\n";
    cout << "Enter Your Class: ";
    cin >> player1.playerClass;
    if (player1.playerClass == "Warrior")
    {
        warrior();
    }
    else if (player1.playerClass == "Bandit")
    {
        bandit();
    }
    else if (player1.playerClass == "Thief")
    {
        thief();
    }
    else if (player1.playerClass == "Mage")
    {
        mage();
    }
    cout << "The SpiceUniverse is very big choose your Character's BirthPlace\n";
    cout << "1. [SpiceCommon] 2. [BountyStreet] 3. [Iced] 4. [Tectonac]\n";
    cout << "Enter the Character's Birth Planet: ";
    cin >> player1.playerHome;
    sleep(2);
    cout << ".";
    sleep(2);
    cout << ".";
    sleep(2);
    cout << "." << endl;
    cout << "Ah! The planet " << player1.playerHome << ", The definition of good and bad clearly fits it\n";
    sleep(2);
    cout << "press [enter] to continue\n";
    cin.get();
    cin.get();
    cout << "The big industries that engulf half of the planet only to dig the most important mineral in the universe" << endl;
    sleep(3);
    cout << "The mineral is called : [Spice], ";
    sleep(1);
    cout << "used to provide life to whole universe and it's inhabitants, Pure Power as per say" << endl;
    sleep(1);
    cout << "Whole universe runs on a mere mineral enabling the use of ancient technologies which are present in the ruins of the planets" << endl;
    cout << "press[enter] to continue\n";
    cin.get();
    cout << player1.playerName << " is born on the harsh planet known as " << player1.playerHome << endl;
    cout << "Luckiely on a little better side of the planet as the air is the least toxic on this side of the planet\n";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".\n";
    cout << player1.playerName << " turned 14 years old today, he's going out of his home village for the first time\n";
    sleep(2);
    cout << " Sure, he has gone outside of his village but never on his own\n Today he will bring some [Spice], that is leaking from the sky touching machines of the old gods that beings from other planets\nuse to extract [Spice] from the heart of the planet";
    cout << "\nThis is the life that people on this planet live, they sell [Spice] illegally to people for price that's lower than market\n";
    cout << player1.playerName << " started his journey today in the morning ";
    sleep(2);
    cout << player1.playerName << " sees a man on the path he's taking to the [Spice]factories.";
    cout << "\nDo you want to approach him [Y/N]: ";
    cin >> a;
    if (a == 'Y')
    {
        cout << "\nYou approach this man, and ask him name, he replies 'my name is Papa69' here's a gift of appreciation for talking to me: ";
        sleep(1);
        cout << "[hands out a heal to you] Heal +1\n";
        sleep(1);
        player1.playerHeals += 1;
    }
    cout << player1.playerName << " moves on forward on the path ";
    sleep(2);
    cout << "As he moves further the day comes to an end and dangerous beings starts to come out and \n one dark figure has been following him from the very start\nhe suddenly attacks the dark figure and catches him off guard with his " << player1.playerWeapon << endl;
    sleep(2);
    cout << "\n\nYou and Your enemy each get one move to choose and do what you want so choose your move carefully\n";
    sleep(2);
    cout << "\n";
    combatpopup();
    int fightrslt;
    char response;
    enemygenerate();
    fightrslt=fight();
    if (fightrslt==0){
        cout << "Press Y to start again and N to exit from the game, [Y/N] : ";
        cin >> response;
        if (response=='Y'){
            goto initial;
        }
        else{
            cout << "Thank You for Playing The Spice Universe\n";
            goto end;
        }
        sleep(2);
    }
    else {
        sleep(2);
        cout << "You've defeated your first enemy on SpiceCommon\n";
    }
    char respo;
    cout << "Press [Y] to rest, [N] to continue: ";
    cin >> respo;
    if (respo=='Y'){
        rest();
    }
    cout << "press [enter] to continue\n";
    cin.get();
    cout << "You are tired after fighting such a fearsome being that too came from the stars in search of [Spice] \nYou feel what can be so much important that beings are ready to kill other beings for it\n";
    sleep(4);
    cout << "You rest for the remaining night which is not very much,[resting restores MaxHP]\n";
    rest();
    cout << ".";
    sleep(2);
    cout << ".";
    sleep(2);
    cout << ".\n";
    sleep(2);
    cout << "You wake up and quickly head for the [Spice] factories \nas they will be releasing their shipment and that is the only time when \nthe [Spice] can be accessed from the detached nossels, You must hurry\n";
    sleep(3);
    cout << "As you pass through the challenging terrain of SpiceCommon\nYou reach at what people of SpiceCommon call it [TheSplit]\nIt is a split in land which seems like someone sliced through the land and ate a portion of the land\n";
    sleep(4);
    cout << "press [enter] to continue\n";
    cin.get();
    cout << "Some even say that this is the scar from the old times which occured due to the conflict between the old gods\n";
    sleep(4);
    cout << "You've arrived at [TheSplit], You've never seen the split but you have heard stories about how the two paths besides the split decide your fate\n";
    sleep(5);
    cout << "But seeing this with your own eyes feels....";
    sleep(2);
    cout << "Surreal, something you can't express in words, something you can never get away from\n";
    sleep(2);
    cout << "press [enter] to continue\n";
    cin.get();
    cout << "You have reached at the two paths : ";
    sleep(1);
    cout << "the path on the right side of you, it seems somewhat dangerous yet attractive it's pulling...";
    sleep(3);
    cout << "\nIt's pulling you, it feels like everything you've ever dreamed of lies on that right path\n";
    sleep(2);
    cout << "While the path on the left side of you, seems rather bland, it reeks of death and sorrow\n";
    sleep(2);
    cout << "press [enter] to continue\n";
    cin.get();
    split:

    cout << "Left[L] or Right[R] both leads to the [Spice] factories, chose your path [L/R] : ";
    cin >> pathresponse;
    if (pathresponse=='L'){
        cout << "As you move through the left path you see a herd of multiple hostile beings\n";
        combatpopup();
        srand(time(0));
        pathfightvariable=1+rand()%6;
        cout << "You see closely and find out there are " << pathfightvariable << "hostile beings\n";
        for (int i=1; i<pathfightvariable; i++){
            enemygenerate();
            wins=fight();
            if (wins==0){
                cout << "Press Y to start again and N to exit from the game, [Y/N] : ";
                cin >> response;
                if (response=='Y'){
                    goto initial;
                }
                else{
                    cout << "Thank You for Playing The Spice Universe\n";
                goto end;
                }
                sleep(2);
            }
        }

    }
    else if (pathresponse=='R'){
        cout << "As you move through the Right path you see a herd of multiple hostile beings\n";
        combatpopup();
        srand(time(0));
        combatpopup();
        pathfightvariable=1+rand()%6;
        cout << "You see closely and find out there are " << pathfightvariable << "hostile beings\n";
        for (int i=1; i<pathfightvariable; i++){
            enemygenerate();
            wins=fight();
            if (wins==0){
                cout << "Press Y to start again and N to exit from the game, [Y/N] : ";
                cin >> response;
                if (response=='Y'){
                    goto initial;
                }
                else{
                    cout << "Thank You for Playing The Spice Universe\n";
                goto end;
                }
                sleep(2);
            }
        }
    }
    else {
        goto split;
    }
    if (wins==pathfightvariable){
        cout << "Congratulations for winning your fearsome battle with the enemies of your cause\nHere are the things you acquired : \n";
        cout << "+2 Heals\n+4 SpTurns\n";
        player1.playerHeals+=2;
        player1.playerSPTurns+=4;
    }
    cout << "press [enter] to continue\n";
    cin.get();
    cin.get();
    if (pathresponse=='L'){
        cout << "After taking the Left path you finds out that there is no difference between Left or Right both leads to [Spice] factories";
    }
    else if (pathresponse=='R'){
        cout << "After taking the Right path you finds out that there is no difference between Left or Right both leads to [Spice] factories";
    }
    sleep(2);
    cout << "Finally You have arrived at the sky reaching ancient [Spice] extractors which span across half the globe, \nthe air is so thick with [Spice] you can't breathe, \nabsolutely majestic and heartbreaking at the same time\n";
    sleep(2);
    player1.playerspice=0;
    cout << "You have arrived at the [Spice] factories\n";
    sleep(4);
    cout << "You reach to the nearest nossel of the [Spice] and start mining the [Spice]Crystals\n";
    mine();
    sleep(3);
    cout << ".";sleep(2);cout << ".";sleep(2);cout << ".";sleep(2);cout << ".";sleep(2);cout << ".\n";
    cout << "After mining you look around yourself and think what is going on in this world\n";
    sleep(4);
    cout << "You think about [Spice] which is so important to the world, yet so destructive, so violent to life";
    sleep(4);
    cout << "So many species fight to have control over [Spice],";
    sleep(3);
    cout << "And Questions yourself if [Spice] is a light of gods or a chaos of demons\n";
    sleep(2);
    cout << "You start moving back to your home village\n";
    sleep(1);
    cout << "You wonder if it was the [Spice] that destroyed so called 'The Old Gods' \n";
    cout << ".";sleep(2);cout << ".";sleep(2);cout << ".";sleep(2);cout << ".\n";
    cout << "You go through the [split] and back to the path from where you came from";
    cout << ".";sleep(2);cout << ".";sleep(2);cout << ".";sleep(2);cout << ".\n";
    cout << "You see the cliff from where you can see your whole village and you start moving fast towards it\n";
    sleep(3);
    cout << "You see some people shouting, some cries,";
    sleep(2);
    cout << " Suddenly you heard a big eye blinding explosion\n";
    sleep(2);
    cout << "You run towards the cliff with all your energy, you leave behind all the things you had on your back including [Spice] Crystals\n";
    sleep(4);
    cout << "As you reach the top of the cliff A truely horrific scene awaits you,\n You see you whole village in flames\n";
    sleep(2);
    cout << "You dont know what to do, as a shock flows through your whole body\n";
    sleep(2);
    cout << "You look above as a giant ship of the beings from the sky disappears in an instant\n";
    cout << "\n\n\n\n\n";
    cout << "TO BE CONTINUED\n";
    cout << "\n\n\n";
    cout << "Press [Y] to Restart game, [N] to exit the game [Y/N]: ";
    char endresponse;
    cin >> endresponse;
    if (endresponse=='Y') goto initial;
    else goto end;
    

    
    end:
    
    int c;
}


