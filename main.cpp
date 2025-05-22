#include <iostream>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <tuple>
using namespace std;

void find_any_byte(vector<vector<string>>::const_iterator& first, vector<vector<string>>::const_iterator& last, int byte)
{
    for (auto ip{ first }; ip != last; ++ip)
    {



        if ((atoi(ip->at(0).data()) == byte)|| (atoi(ip->at(1).data()) == byte) || (atoi(ip->at(2).data()) == byte) || (atoi(ip->at(3).data()) == byte) )
        {
            for (auto ip_part{ ip->begin() }; ip_part != ip->end(); ++ip_part)
            {

                if (ip_part != ip->cbegin())
                {
                    std::cout << ".";

                }
                std::cout << *ip_part;
            }
            cout << endl;
        }

    }
       

}

void find_some_byte(vector<vector<string>>::const_iterator& first, vector<vector<string>>::const_iterator& last, std::tuple<int,int> byte)
{
   
    
    for (auto ip{ first }; ip != last; ++ip)
    {
        
        
        
        if ((atoi(ip->at(0).data()) == get<0>(byte)) && (atoi(ip->at(1).data()) == get<1>(byte)))
        {
            for (auto ip_part{ ip->begin() }; ip_part != ip->end(); ++ip_part)
            {

                if (ip_part != ip->cbegin())
                {
                    std::cout << ".";

                }
                std::cout << *ip_part;
            }
            cout << endl;
        }





    }




}

    void find_byte(vector<vector<string>>::const_iterator & first, vector<vector<string>>::const_iterator & last, int value)
    {
        for (auto ip{ first }; ip != last; ++ip)
        {
            if (atoi(ip->at(0).data()) == 1)
            {
                for (auto ip_part{ ip->begin() }; ip_part != ip->end(); ++ip_part)
                {

                    if (ip_part != ip->cbegin())
                    {
                        std::cout << ".";

                    }
                    std::cout << *ip_part;
                }
                cout << endl;
            }
        }
    }



    void printData(vector<vector<string>>::const_iterator & first, vector<vector<string>>::const_iterator & last)
    {
        for (auto ip{ first }; ip != last; ++ip)
        {

            for (auto ip_part{ ip->begin() }; ip_part != ip->end(); ++ip_part)
            {
                if (ip_part != ip->cbegin())
                {
                    std::cout << ".";

                }
                std::cout << *ip_part;

            }
            cout << endl;

        }

    }

    std::vector<std::string> split(const std::string & str, char d) 
    {
        std::vector<std::string> r;

        std::string::size_type start = 0;
        std::string::size_type stop = str.find_first_of(d);
        while (stop != std::string::npos)
        {
            r.push_back(str.substr(start, stop - start));

            start = stop + 1;
            stop = str.find_first_of(d, start);
        }

        r.push_back(str.substr(start));

        return r; 
    }



    int main(int argc, char const* argv[])
    {

try
{


        string line;
        std::ifstream in("ip_filter.tsv", std::ios::in);
        std::vector<vector<string>> ip_pool;
        if (in.is_open())
        {

            while (std::getline(in, line))
            {
                std::vector<std::string> v = split(line, '\t'); // формируем вектор извлеченных данных -записываем строчку в вектор до первого символа табул¤ции
                ip_pool.push_back(split(v.at(0), '.'));
            }
        }

        in.close();

        auto it_first{ ip_pool.cbegin() };
        auto it_last{ ip_pool.cend() };

      

        ////////////////////////////////////////////////Сортировка по 4-м байтам
        auto compare_fhour_byte = [](vector<string> a, vector <string> b)
        {
            if (atoi(a.at(0).data()) == atoi(b.at(0).data()))// если первые байты равны, то переходим ко вторым, и так далее
            {
                if (atoi(a.at(1).data()) == atoi(b.at(1).data()))
                {
                    if (atoi(a.at(2).data()) == atoi(b.at(2).data()))
                    {
                        return  atoi(a.at(3).data()) > atoi(b.at(3).data());
                    }
                    else
                    {
                        return  atoi(a.at(2).data()) > atoi(b.at(2).data());
                    }
                }
                else
                {
                    return atoi(a.at(1).data()) > atoi(b.at(1).data());
                }
            }
            else
            {
                return  atoi(a.at(0).data()) > atoi(b.at(0).data());// если первые байты не равны, то срввниваем их между собой
            }
        };

        std::sort(ip_pool.begin(), ip_pool.end(), compare_fhour_byte);
       
        
        printData(it_first, it_last);//вывод адресов после сортировки по 4-м байтам


        find_byte(it_first, it_last, 1);// вывод элементов равных 1 в 1 байте

        tuple<int, int> byte;
        byte = make_tuple(46, 70);
        find_some_byte(it_first, it_last, byte);// вывод элементов равных 46 в 1 байте и 70 во втором байте
  

        find_any_byte(it_first, it_last, 46);// вывод элементов равных любой байт которыйх равен 46


    

}
    

        catch (const std::exception& e)// обработка исключения
        {
            std::cerr << e.what() << std::endl;
        }

        return 0;
    
}