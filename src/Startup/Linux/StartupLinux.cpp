#include <cstdint>

extern int32_t GenericMain();

//TODO: This is just a mock to see if linux code won't be compiled on Windows.
int main(int argc, char** argv)
{
	int32_t ErrorLevel = 0;
	
	ErrorLevel = GenericMain();

	return ErrorLevel;
}