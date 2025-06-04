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
    for (auto ip{ first }; ip != last-1; ++ip)
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
   
    
    for (auto ip{ first }; ip != last-1; ++ip)
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
        for (auto ip{ first }; ip != last-1; ++ip)
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
        for (auto ip{ first }; ip != last-1; ++ip)
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
                std::vector<std::string> v = split(line, '\t'); 
                ip_pool.push_back(split(v.at(0), '.'));
            }
        }

        in.close();

        auto it_first{ ip_pool.cbegin() };
        auto it_last{ ip_pool.cend() };

      
                  // 4-byte sort
        auto compare_fhour_byte = [](vector<string> a, vector <string> b)
        {
            if (atoi(a.at(0).data()) == atoi(b.at(0).data()))
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
                return  atoi(a.at(0).data()) > atoi(b.at(0).data());
            }
        };

        std::sort(ip_pool.begin(), ip_pool.end(), compare_fhour_byte);
       
        
        printData(it_first, it_last); //ip output after sorting by 4 bytes


        find_byte(it_first, it_last, 1);//output of ip  equal to 1 in one byte

        tuple<int, int> byte;
        byte = make_tuple(46, 70);
        find_some_byte(it_first, it_last, byte);// output ip equal 46 (1 byte) 70 (2byte)
  

        find_any_byte(it_first, it_last, 46);// output of ip any byte is 46


    

}
    

        catch (const std::exception& e)// îáðàáîòêà èñêëþ÷åíèÿ
        {
            std::cerr << e.what() << std::endl;
        }

        return 0;
    
}
