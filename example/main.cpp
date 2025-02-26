
#include"commander.h"
//#include<cstdio>
//#include<stdexcept>
//#include<cstdlib>	// system()

int main() 
{	
	// Open a terminal
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

	// Copy and rename certain files in the folders created previously
	std::string file = "";
	std::vector<std::string> subfolders = { "curvature_labels", "departure_labels", "lines_labels" };

	for(int i = 0; i < folders.size(); i++) 
	{
		if(folders[i] == "labels" || folders[i] == "labels_done") continue;

		for(int j = 0; j < subfolders.size(); j++)
		{
			file = x.exec("ls " + folders[i] + "/labels/" + subfolders[j]);
			x.exec("cp " + folders[i] + "/labels/" + subfolders[j] + "/" + file + " labels/" + subfolders[j]);
			x.exec("mv labels/" + subfolders[j] + "/" + file + " labels/" + subfolders[j] + "/" + folders[i] + "_" + subfolders[j]); 
		}
	}	
	
	std::cout << "Everything done!" << std::endl;
}

// Get a list of folders and parse it
// 3x { Use the previous list to rename (folderName_curvature_labels.txt) and move file to curvature labels
