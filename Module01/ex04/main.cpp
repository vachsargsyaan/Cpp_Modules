#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "you nedd to entern 3 argument\n";
        return (1);
    }
    std::ifstream	inFIle(argv[1]);
	std::string		line;
    if (!inFIle)
    {
        std::cout << "cant open the file\n";
		return 1;
    }
    std::string name = argv[1];
	std::ofstream outFile(name + ".replace");
	size_t pos = 0;
	while (getline(inFIle, line))
	{
		while ((pos = line.find(argv[2], pos)) != std::string::npos)
		{
			line.erase(pos, strlen(argv[2]));
			line.insert(pos, argv[3]);
			pos += strlen(argv[3]);
		}
		outFile << line << "\n";
		pos = 0;
	}
	return 0;
}