#include <iostream>
#include <cstring>
#include <fstream>
#include <bits/stdc++.h>

int main(int argc, char **argv)
{
	if (argc != 2)
		return 0;
	std::string file = argv[1];
	std::string s = file + "_hpp";
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);
	file = file + ".hpp";
	std::ofstream File(file.c_str(), std::ios::out);
	File << "#ifndef " << s << "\n# define " << s << "\n";
	File << "# include <iostream>\n\n\n";
	File << "class " << argv[1] << "\n";
	File << "{\n\tprivate:\n\t\tconst std::string _name;\n\tpublic:\n\t\t";
	File << argv[1] << "();\n\t\t";
	File << "~" << argv[1] << "();\n\t\t";
	File << argv[1] << "(const std::string &name);\n\t\t";
	File << argv[1] << "(const " << argv[1] << " &other);\n\t\t";
	File << argv[1] << " &operator=(const " << argv[1] << " &other);\n";
	File << "};\n\n#endif";
	File.close();
	
	std::string file2 = argv[1];
	file2 = file2 + ".cpp";
	std::ofstream File2(file2.c_str(), std::ios::out);
	File2 << "#include \"" << file << "\"\n\n";
	File2 << argv[1] << "::" << argv[1] << "()\n{\n\t";
	File2 << "std::cout << \"" << argv[1] << " default constructor called\\n\";\n}";
	File2 << "\n\n" << argv[1] << "::~" << argv[1] << "()\n{\n\t";
	File2 << "std::cout << \"" << argv[1] << " destructor called\\n\";\n}\n\n";
	File2 << argv[1] << "::" << argv[1] << "(const std::string &name)\n{\n\t";
	File2 << "std::cout << \"" << argv[1] << " constructor called\\n\";\n\t";
	File2 << "_name = name;\n}\n\n";
	File2 << argv[1] << "::" << argv[1] << "(const " << argv[1] << " &other)\n{\n\t_name = other.name;\n\t";
	File2 << "std::cout << \"" << argv[1] << " copy constructor called\\n\";\n}\n\n";
	File2 << argv[1] << "& " << argv[1] << "::operator=(const " << argv[1] << " &other)\n{\n\t";
	File2 << "if (this != &other)\n\t{\n\t\t_name = other.name;\n\t\t";
	File2 << "std::cout << \"" << argv[1] << " assignment operator called\\n\";\n\t}\n";
	File2 << "\treturn *this;\n}\n\n";
	File2.close();
}
