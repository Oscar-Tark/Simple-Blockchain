#include <stdio.h>
#include <stdlib.h>
#include <gcrypt.h>
#include "block.h"

//All function declarations
void newBlock(unsigned int, unsigned int, const char*);
void adjustQueueLength();
void getLatestBlock();

//Add the Queue struct pointer for global reference
struct Chain* waiting_queue;

int main(int argc, char* argv[]){
	//Initialize all queue based pointers and internal values
	printf("Initializing Shitcoin...");
	waiting_queue = (struct Chain*)malloc(sizeof(struct Chain));
	waiting_queue->current_internal_length = 0;
	newBlock(20, 158, "Henlo!");
	getLatestBlock();
	return 0;
}

void newBlock(unsigned int pow, unsigned int amount, const char* message){
	printf("\nCreating new coin...");
	struct Block* block = (struct Block*)malloc(sizeof(struct Block));

	//Zero out new block
	memset(block, 0, sizeof(struct Block));

	//Add data to block
	block->index = waiting_queue->current_internal_length;
	block->message = message;
	block->amount = amount;

	//Add block
	waiting_queue->block_addrs[waiting_queue->current_internal_length] = block;

	printf("\nCoin created.");
	adjustQueueLength();
}

void getLatestBlock(){
	printf("\nGetting latest block");
	struct Block* latest_block = waiting_queue->block_addrs[0];
	printf("{\nIndex: %lu\nMessage: %s\nAmount: %d\n Prev_hash: %s\n}\n", latest_block->index, latest_block->message, latest_block->amount, latest_block->prev_hash);
}

void adjustQueueLength(){
	waiting_queue->current_internal_length++;
}

void clear_mem(){

}
