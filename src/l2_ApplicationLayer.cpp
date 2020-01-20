/* Программа-заготовка для домашнего задания
*/

#include "hw/l2_ApplicationLayer.h"

using namespace std;

bool Application::performCommand(const vector<string> & args)
{
    if (args.empty())
        return false;

    if (args[0] == "l" || args[0] == "load")
    {
        string filename = (args.size() == 1) ? "hw.data" : args[1];

        if (!_col.loadCollection(filename))
        {
            _out.Output("Ошибка при загрузке файла '" + filename + "'");
            return false;
        }

        return true;
    }

    if (args[0] == "s" || args[0] == "save")
    {
        string filename = (args.size() == 1) ? "hw.data" : args[1];

        if (!_col.saveCollection(filename))
        {
            _out.Output("Ошибка при сохранении файла '" + filename + "'");
            return false;
        }

        return true;
    }

    if (args[0] == "c" || args[0] == "clean")
    {
        if (args.size() != 1)
        {
            _out.Output("Некорректное количество аргументов команды clean");
            return false;
        }

        _col.clean();

        return true;
    }

    if (args[0] == "a" || args[0] == "add")
    {
        if (args.size() != 5)
        {
            _out.Output("Некорректное количество аргументов команды add");
            return false;
        }

        _col.addItem(make_shared<EcoCard>(args[1].c_str(), stoul(args[2]), stoul(args[3]), args[4].c_str()));
        return true;
    }

    if (args[0] == "r" || args[0] == "remove")
    {
        if (args.size() != 2)
        {
            _out.Output("Некорректное количество аргументов команды remove");
            return false;
        }

        _col.removeItem(stoul(args[1]));
        return true;
    }

    if (args[0] == "u" || args[0] == "update")
    {
        if (args.size() != 6)
        {
            _out.Output("Некорректное количество аргументов команды update");
            return false;
        }

        _col.updateItem(stoul(args[1]), make_shared<EcoCard>(args[2].c_str(), stoul(args[3]), stoul(args[4]), args[5].c_str()));
        return true;
    }

    if (args[0] == "v" || args[0] == "view")
    {
        if (args.size() != 1)
        {
            _out.Output("Некорректное количество аргументов команды view");
            return false;
        }

        size_t count = 0;
        for(size_t i=0; i < _col.getSize(); ++i)
        {
            const EcoCard & item = static_cast<EcoCard &>(*_col.getItem(i));

            if (!_col.isRemoved(i))
            {
                _out.Output("[" + to_string(i) + "] "
                        + item.getCommName() + " "
                        + to_string(item.getCode()) + " "
                        + to_string(item.getNumberofPpl()) + " "
                        + item.getLevel());
                count ++;
            }
        }

        _out.Output("Количество элементов в коллекции: " + to_string(count));
        return true;
    }

    if (args[0] == "--help" || args[0] == "-h") {
        _out.Output("-h, --help - выводит доступные команды");
        _out.Output("-с, --card - выводит информацию о структуре карточки");
        _out.Output("l, load - загрузка коллекции из файла data.hw");
        _out.Output("s, save - сохранение коллекции в файл data.hw");
        _out.Output("c, clean - очистка текущей коллекции в буфере");
        _out.Output("a, add - добавление карточки в коллекцию");
        _out.Output("u, update - обновления карточки коллекции по индексу");
        _out.Output("r, remove - удаление карточки из коллекции по индексу");
        _out.Output("v, view - просмотр текущей коллекции в буфере");

        return true;
    }

    if (args[0] == "--card" || args[0] == "-c") {
        _out.Output("Эко карта: { название_пункта код_отако количество_людей уровень_загрязнения }");

        return true;
    }

    if (args[0] == "--exit" || args[0] == "-e") {
        _out.Output("Выполнение завершено успешно");

        return false;
    }

    if (args[0] != "")
        _out.Output("Недопустимая команда");

    return true;
}
