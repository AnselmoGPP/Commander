
#include"commander.h"
//#include<cstdio>
//#include<stdexcept>
//#include<cstdlib>	// system()

int main() 
{	
	commander x;

	// Move to the  directory you want
	x.exec("cd ../example/test");
	std::cout << "Moved to: " << x.exec("pwd") << std::endl;
	
	// Create folders to move files there
	x.exec("mkdir labels labels/curvature_labels labels/departure_labels labels/lines_labels labels/roadtype_labels");

	// Get the files in the current directory
	std::string output = "";	
	output = x.exec("ls .");
	
	std::vector<std::string> folders(0);
	x.extract_elements(output, folders);

	for(int i = 0; i < folders.size(); i++) 
		std::cout << folders[i] << std::endl;
	
	
}

// Get a list of folders and parse it
// 3x { Use the previous list to rename (folderName_curvature_labels.txt) and move file to curvature labels
