#include <string>
#include <vector>

#include "Init_value.h"
#include "split.h"

bool Init_value::init(std::istream& is)
{
	std::string str;
	std::vector<std::string> strs;
	while (std::getline(is,str))
	{
		if (str[0] == '/')
			continue;
		else
		{
			split(str,strs.begin());
			if (strs[0] == "FLOOR:")
				FLOOR =0;
		}
	}
}