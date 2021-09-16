#include <gcrypt.h>

//Exclude any depreciated modules from Gcrypt
#define GCRYPT_NO_DEPRECATED
const char* version;

void startHasher(){
	version = gcry_check_version("");
}

const char* hashBlock(void* block){
	return "";
}
