//
// Created by tillw on 18/01/2024.
//

#ifndef TEXOR_FILE_H
#define TEXOR_FILE_H

#include <vector>
#include <string>


class File
{
public:
	std::vector<std::string> data = { "" };
};

typedef std::vector<File*> Files;

#endif //TEXOR_FILE_H
