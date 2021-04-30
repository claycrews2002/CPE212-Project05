#ifndef DRAGON_HPP
#define DRAGON_HPP

#include "JsonEntityBuilder.hpp"
#include "entity.hpp"


class Dragon : public Entity
{
private:
    uint32_t weapon_damage;

    void Firebreath(Entity * target);

public:
    Dragon(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid);
    ~Dragon() = default;

    virtual void OutputStatus() const override;
    virtual void WeaponAttack(Entity * target) override;
    virtual void UseAction(Entity * target, const std::string& spellName, const std::string & args) override;

};



#endif