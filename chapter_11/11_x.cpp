#include <iostream>
#include <cmath>
#include <string>
#include <string_view>      
#include <cassert>
#include <random>
#include <ctime>
#include <array>

// ++++++++++++++++++++++++++++++++ Question 1
class Point2d
{
private:
    double m_x{};
    double m_y{};
public:
    Point2d(double x=0.0, double y=0.0):m_x{x}, m_y{y}
    {}

    void print() const 
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")" << '\n';
    }

    double distance_to(const Point2d & point2d) const
    {
        return std::sqrt(std::pow((m_x - point2d.m_x), 2) + std::pow((m_y - point2d.m_y), 2));
    }
    friend double distance_from(const Point2d & point2d_1, const Point2d & point2d_2);
};

double distance_from(const Point2d & point2d_1, const Point2d & point2d_2)
{
    return std::sqrt(std::pow((point2d_2.m_x - point2d_1.m_x), 2) + std::pow((point2d_2.m_y - point2d_1.m_y), 2));
}

void question1()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << first.distance_to(second) << '\n';
    std::cout << "Distance between two points: " << distance_from(first, second) << '\n';
}

// ++++++++++++++++++++++++++++++++ Question 2
class HelloWorld
{
private:
	char *m_data{};
 
public:
	HelloWorld()
	{
		m_data = new char[14];
		const char *init{ "Hello, World!" };
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
	}
 
	~HelloWorld()
	{
        delete[] m_data;
	}
 
	void print() const
	{
		std::cout << m_data << '\n';
	}
 
};

void question2()
{
    HelloWorld hello{};
	hello.print();
}

// ++++++++++++++++++++++++++++++++ Question 3
class Monster
{
public:
    enum class Monster_t
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_t
    };
private:
    Monster_t m_monster_t;
    std::string m_name;
    std::string m_roar;
    int m_hit;
public:
    Monster(Monster_t monster_t, const std::string &name, const std::string &roar, int hit): m_monster_t{monster_t}, m_name{name}, m_roar{roar}, m_hit{hit}
    {}

    std::string get_type_string() const
    {
        switch(m_monster_t)
        {
		case Monster_t::dragon: return "dragon";
		case Monster_t::goblin: return "goblin";
		case Monster_t::ogre: return "ogre";
		case Monster_t::orc: return "orc";
		case Monster_t::skeleton: return "skeleton";
		case Monster_t::troll: return "troll";
		case Monster_t::vampire: return "vampire";
		case Monster_t::zombie: return "zombie";
        default:
            assert(false);
        }
    }
    
    void print() const
    {
        std:: cout << m_name<< " the "<< get_type_string() << " has "<< m_hit << " hit points and says " << m_roar << '\n';
    }
};

class Monster_generator
{
public:
    static int get_random_number(int min, int max )
    {
        static std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
        return std::uniform_int_distribution{ min, max }(mersenne);
    }

    static Monster generate_monster()
    {
        Monster::Monster_t monster_t{ static_cast<Monster::Monster_t>(get_random_number(0, (static_cast<int>(Monster::Monster_t::max_monster_t)-1)))};
 		static constexpr std::array s_names{ "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
		static constexpr std::array s_roars{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};
        auto name{ s_names[static_cast<std::size_t>(get_random_number(0, s_names.size()-1))] };
		auto roar{ s_roars[static_cast<std::size_t>(get_random_number(0, s_roars.size()-1))] };
        return Monster{monster_t, name, roar, get_random_number(0, 100)};
    }
};

void question3()
{
    Monster m{ Monster_generator::generate_monster() };
    m.print();
    // Monster skeleton{ Monster::Monster_t::skeleton, "Bones", "*rattle*", 4 };
}

// ++++++++++++++++++++++++++++++++ Question 4
void question4()
{
    //TODO: blackjack code
}

int main()
{
    question1();
    question2();    
    question3();
    question4();
    return 0;
}