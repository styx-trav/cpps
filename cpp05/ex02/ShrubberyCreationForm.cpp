#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("target"), NoFileException(CustomException("the shrubbery file could not be created/opened !\n"))
{
	std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target), NoFileException(CustomException("the shrubbery file could not be created/opened !\n"))
{
	std::cout << "ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target), NoFileException(CustomException("the shrubbery file could not be created/opened !\n"))
{
	std::cout << "ShrubberyCreationForm copy constructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		std::cout << "ShrubberyCreationForm assignment operator called\n";
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		this->AForm::execute(executor);
		std::string file = _target + "_shrubbery";
		std::ofstream newFile(file.c_str(), std::ios::out);
		if (!newFile)
			throw NoFileException;
		for (int i = 0; i != 2; i++)
		{
			newFile << "                     ; ; ;\n";
			newFile << "                   ;        ;  ;     ;;    ;\n";
			newFile << "                ;                 ;         ;  ;\n";
			newFile << "                                ;\n";
			newFile << "                               ;                ;;\n";
			newFile << "               ;          ;            ;              ;\n";
			newFile << "               ;            ';,        ;               ;\n";
			newFile << "               ;              'b      *\n";
			newFile << "                ;              '$    ;;                ;;\n";
			newFile << "               ;    ;           $:   ;:               ;\n";
			newFile << "             ;;      ;  ;;      *;  @):        ;   ; ;\n";
			newFile << "                          ;     :@,@):   ,;**:'   ;\n";
			newFile << "              ;      ;,         :@@*: ;;**'      ;   ;\n";
			newFile << "                       ';o;    ;:(@';@*\"'  ;\n";
			newFile << "               ;  ;       'bq,;;:,@@*'   ,*      ;  ;\n";
			newFile << "                          ,p$q8,:@)'  ;p*'      ;\n";
			newFile << "                   ;     '  ; '@@Pp@@*'    ;  ;\n";
			newFile << "                    ;  ; ;;    Y7'.'     ;  ;\n";
			newFile << "                              :@):.\n";
			newFile << "                             .:@:'.\n";
			newFile << "                           .::(@:.      -Sam Blumenstein-\n\n";
		}
		newFile.close();	
	}
	catch (std::exception &e) {throw ;}
}
