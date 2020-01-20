/* Программа-заготовка для домашнего задания
*/

#include "hw/l3_DomainLayer.h"

using namespace std;


bool EcoCard::invariant() const
{
    return _code_okato >= MIN_CODE
           && _code_okato <= MAX_CODE
           && !_community_name.empty()
           && _community_name.size() <= MAX_NAME_LENGTH
           && !_level_of_pollution.empty()
           && _level_of_pollution.size() <= MAX_NAME_LENGTH
           && _number_of_people >= 1;
}

EcoCard::EcoCard(const string & community_name, int code_okato, int number_of_people, const string &  level_of_pollution)
        : _community_name(community_name), _code_okato(code_okato), _number_of_people(number_of_people), _level_of_pollution(level_of_pollution)
{
    assert(invariant());
}

const string & EcoCard::getCommName() const { return _community_name; }
const int & EcoCard::getCode() const { return _code_okato; }
const int & EcoCard::getNumberofPpl() const { return _number_of_people; }
const string & EcoCard::getLevel() const{return _level_of_pollution;}

bool   EcoCard::write(ostream& os)
{
    writeString(os, _community_name);
    writeNumber(os, _code_okato);
    writeNumber(os, _number_of_people);
    writeString(os, _level_of_pollution);

    return os.good();
}

shared_ptr<ICollectable> ItemCollector::read(istream& is)
{
    string   _community_name = readString(is, MAX_NAME_LENGTH);
    int   _code_okato = readNumber<int>(is);
    int _number_of_people = readNumber<int>(is);
    string _level_of_pollution = readString(is, MAX_NAME_LENGTH);

    return std::make_shared<EcoCard>(_community_name, _code_okato, _number_of_people, _level_of_pollution);
}
