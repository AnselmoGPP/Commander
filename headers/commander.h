// https://stackoverflow.com/questions/52164723/how-to-execute-a-command-and-get-return-code-stdout-and-stderr-of-command-in-c

#include<iostream>
#include<array>
#include<string>
#include<vector>

class commander{

	std::string input = "";
	std::string output = "";

	// This string contains the current directory   ->    currDir = x.exec("cd ..; pwd");
	std::string currDir;		

	// Modify the input, if necessary, before executing the command
	void check_special_cases_and_execute()
	{
		// Check:   cd any/directory	
		if(input[0] == 'c' && input[1] == 'd' && input[2] == ' ') 
		{
			input = "cd " + currDir + "; " + input + "; pwd";
			output = execute(input.c_str());	
			if(output.size() > 0) output.erase(output.size()-1);		// Delete the eol char
			currDir = output;
		}
		
		// Any other case	
		else
		{
			input = "cd " + currDir + "; " + input;
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
		currDir = execute("cd .; pwd");
		currDir.erase(currDir.size()-1);
		std::cout << "Original directory: " << currDir << std::endl;
	}

	// Execution call. Argument: Pointer to a null terminated array
	std::string exec(const char* cmd)
	{		
		input = std::string(cmd);	
		check_special_cases_and_execute();	
		return output;
	}

	// Execution call. Argument: std::string
	std::string exec(const std::string &cmd)
	{
		input = cmd;
		check_special_cases_and_execute();
		return output;
	}	
	
	// Given a string with sets of chars separated by '\n', this function gets all these sets (without '\n') and stores them as separated strings in a given vector<string>
	void extract_elements(std::string &inputStr, std::vector<std::string> &result)
	{
		if(inputStr.size() == 0) return;	

		std::string segment = "";
		const char *ch = inputStr.c_str();

		for( ; *ch != NULL; ch++)
		{
			if(*ch == '\n')
			{
				result.push_back(segment);
				segment = "";
				continue;
			}
			
			segment += *ch;	
		}
		
		result.push_back(segment);
	}	
};
