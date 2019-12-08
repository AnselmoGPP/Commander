// https://stackoverflow.com/questions/52164723/how-to-execute-a-command-and-get-return-code-stdout-and-stderr-of-command-in-c

#include<iostream>
#include<array>
#include<string>
#include<vector>

class commander{

	std::string input = "";
	std::string output = "";

	void check_special_cases_and_execute()
	{
		// Check:   pwd
		if(input[0] == 'p' && input[1] == 'w' && input[2] == 'd') output = currDir;
		
		// Check:   cd any/directory	
		else if(input[0] == 'c' && input[1] == 'd' && input[2] == ' ') 
		{
			input += std::string("; pwd");
			output = execute(input.c_str());	
			if(output.size() > 0) output.erase(output.size()-1);		// Delete the eol char
			currDir = output;
		}
		
		// Any other case	
		else
		{
			output = execute(input.c_str());
			if(output.size() > 0) output.erase(output.size()-1);		// Delete the eol char
		}
	}

	// Execute a command. If there is output, exec() will return it
	std::string execute(const char* cmd) {
		
		std::array<char, 128> buffer;
 		std::string result;

		// popen returns a pointer to an open stream that can be used to read or write to the pipe
		auto pipe = popen(cmd, "r");        
		if (!pipe) throw std::runtime_error("popen() failed!");

		while (!feof(pipe)) 
		{
			if (fgets(buffer.data(), 128, pipe) != nullptr)
		        result += buffer.data();
	       	}

        	auto rc = pclose(pipe);

		// What happens depending on whether the pipe closes successfuly or not
		if (rc == EXIT_SUCCESS)
		{
			// == 0	
		} 
		else if (rc == EXIT_FAILURE) 
		{  
			// EXIT_FAILURE is not used by all programs, maybe needs some adaptation.
		}
	
		return result;
	}

public:

	commander()
	{
		currDir = exec("cd .");
		std::cout << "Original directory: " << currDir << std::endl;
	}

	std::string currDir;		// This string is used to store the current directory   ->    currDir = x.exec("cd ..; pwd");

	std::string exec(const char* cmd)
	{		
		input = std::string(cmd);	
		check_special_cases_and_execute();	
		return output;
	}

	std::string exec(const std::string &cmd)
	{
		input = cmd;
		check_special_cases_and_execute();
		return output;
	}	
	
	void extractEOLseparatedStrings(std::string inputStr, std::vector<std::string> &result)
	{

	}	
};
