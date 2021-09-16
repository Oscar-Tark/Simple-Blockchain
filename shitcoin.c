#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shitcoin.h"

//Add the Queue struct pointer for global reference
struct Chain* waiting_queue;

int main(int argc, char* argv[]){
	//Initialize all queue based pointers and internal values
	printf("Initializing Shitcoin...");
	newChain();

	//Create test blocks
	newBlock(20, 158, "Henlo!");
	newBlock(210, 16468, "Henlo!");
	newBlock(1565, 1, "Stonks");

	//Get blocks
	getBlock(0);
	getBlock(1);
	getBlock(2);

	clearChain();
	return 0;
}
