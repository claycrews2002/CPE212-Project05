#include "dragon.hpp"

Dragon::Dragon(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid) : 
        Entity(builder, inventory, uid)
{
    weapon_damage = _builder.weapon_damage;

    std::cout << Name() << " the dragon has entered the battle" << std::endl;
}

void Dragon::WeaponAttack(Entity *target)
{
    Attack(target, this->weapon_damage, "WeaponAttack");
}

void Dragon::Firebreath(Entity * target)
{
    Attack(target, 20, "Firebreath");
}

void Dragon::OutputStatus() const
{
    std::cout << this->Race() << ": " << this->Name()
                << "\n\tCurrent HP: " << this->CurrentHP()
                << "\n\tHIDDEN INVENTORY"
                << std::endl;
}

void Dragon::UseAction(Entity * target, const std::string& spellName, const std::string & args)
{
    if(spellName == "weapon_attack")
    {
        WeaponAttack(target);
        return;
    }
    if(spellName == "Firebreath")
    {
        Firebreath(target);
        return;
    }
    
    errorFindingAbility(spellName);
}