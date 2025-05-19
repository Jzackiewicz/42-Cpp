#include <iostream>
#include <string>
#include <cstring>

class Megaphone
{
	public:
		Megaphone()
		{
			;
		}

		~Megaphone()
		{
			;
		}

		Megaphone(Megaphone& obj)
		{
			(void)obj;
		}
		
		void to_upper_string(std::string text)
		{
			for (long unsigned int i = 0; i < text.size(); i++)
			{
				text[i] = toupper(text[i]);
			}
			std::cout << text;
		}
};

int main(int argc, char **argv)
{
	Megaphone phone1;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";	
	for (int i = 1; i < argc; i++)
	{
		phone1.to_upper_string(argv[i]);
	}
	return (0);
}
