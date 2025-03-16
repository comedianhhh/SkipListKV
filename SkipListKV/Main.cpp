#include<iostream>
#include<string>
#include<set>
#include<time.h>
#include "skip_list.h"
int main()
{
    {
        //use lambda
        auto cmp = [](const string& a, const string& b) {return a.length() < b.length(); };
        skip_list < string, int, decltype(cmp)> list(cmp);
        list.insert("aab", 1321);
        list.insert("hello", 54342);
        list.insert("world", 544);
        for (auto it = list.begin(); it != list.end(); it++) {
            cout << it->key << " " << it->value << endl;
        }
    }

    cout << "==================================" << endl;

    {
        //use functor
        struct cmp {
            bool operator()(int a, int b) {
                return a > b;
            }
        };
        skip_list < int, int, cmp> list{};
        for (int i = 1; i <= 10; i++)list.insert(rand() % 20, rand());
        for (auto it = list.find(10); it != list.end(); it++) {
            cout << it->key << " " << it->value << endl;
        }
    }

    cout << "==================================" << endl;

    {
		//default less
        skip_list<int, int>list;
        list.insert(1, 3);
        list.insert(1, 3);
        list.insert(4, 3);
        list.insert(5, 3);
        list.insert(1, 3);
        list.insert(4, 3);
        for (auto it = list.begin(); it != list.end(); it++) {
            cout << it->key << " " << it->value << endl;
        }

    }

    {
		// able to add T && to implement move semantics
		// overload []

        skip_list<int, std::string> list;
        list.insert(1, "one");
        list.insert(2, "two");
        list.insert(3, "three");

        // Using move semantics
        list.insert(4, std::move(std::string("four")));

        // Using operator[]
        cout << "Key 1: " << list[1] << endl;
        cout << "Key 2: " << list[2] << endl;
        cout << "Key 3: " << list[3] << endl;
        cout << "Key 4: " << list[4] << endl;


   
    }

}