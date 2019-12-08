
#include"commander.h"
//#include<cstdio>
//#include<stdexcept>
//#include<cstdlib>	// system()

int main() 
{	
	commander x;
	std::vector<std::string> folders;
	std::string output;
	
	//std::cout << x.exec("ls") << std::endl;
	//std::cout << x.exec("pwd") << std::endl;
	//std::cout << x.exec("cd " + x.currDir+"/../..") << std::endl;
		
	// Move to the  directory you want
	std::cout << "Move to this directory: " << x.exec("cd "+ x.currDir+"/../test") << std::endl;
	std::cout << "Current directory: " << x.currDir << std::endl;
	std::cout << "Current directory: " << x.exec("pwd") << std::endl;
	
	// Create folders to move files there
	std::cout << x.exec( "mkdir " + 	x.currDir+"/labels " + 
				x.currDir+"/labels/curvature_labels " + 
				x.currDir+"/labels/departure_labels " + 
				x.currDir+"/labels/lines_labels " + 
				x.currDir+"/labels/roadtype_labels ") << std::endl;
/*
	// Get the files in the current directory
	output = x.exec("ls " + x.currDir);
	std::cout << output << std::endl;
	x.extractEOLseparatedStrings(output, folders);
*/
	//for(int i = 0; i < folders.size(); i++) 
	//	std::cout << folders[i] << std::endl;
}

// Get a list of folders and parse it
// 3x { Use the previous list to rename (folderName_curvature_labels.txt) and move file to curvature labels
