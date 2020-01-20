/* 
MIT License 

Copyright (c) 2019 МГТУ им. Н.Э. Баумана, кафедра ИУ-6, Михаил Фетисов, 

Программа-заготовка для домашнего задания
*/

#ifndef HW_L3_DOMAIN_LAYER_H
#define HW_L3_DOMAIN_LAYER_H

#include "hw/l4_InfrastructureLayer.h"

const size_t MAX_NAME_LENGTH    = 50;
const size_t MIN_CODE  = 0;
const size_t MAX_CODE  = 9999;

class EcoCard : public ICollectable
{
    std::string   _community_name;
    int   _code_okato;
    int _number_of_people;
    std::string _level_of_pollution;

protected:

    bool invariant() const;

public:
    EcoCard() = delete;

    EcoCard(const std::string & community_name, int code_okato, int number_of_people, const std::string &  level_of_pollution);
    
    const std::string & getCommName() const;
    const int & getCode() const;
    const int & getNumberofPpl() const;
    const std::string & getLevel() const;

    virtual bool   write(std::ostream& os) override;
};


class ItemCollector: public ACollector
{
public:
    virtual std::shared_ptr<ICollectable> read(std::istream& is) override;
};

#endif // HW_L3_DOMAIN_LAYER_H
