#include <string.h>

//Function declarations
void newBlock(unsigned int, unsigned int, const char*);
void adjustQueueLength(void);
void getLatestBlock(void);
void clearChain(void);

//Object declarations
struct Chain* chain;

//MEAT!
//Initialize a new blockchain, allocate the memory necessary for the blockchain
void newChain(){
	//Allocate new memory for the chain
        chain = (struct Chain*)malloc(sizeof(struct Chain));
	//Zero out new chain
	memset(chain, 0, sizeof(struct Chain));

	//Set chain variables
        chain->length = 0;
	printf("\nChain created.");
}

//When done with your blockchain, clear the chain out to free any memory associated to it
void clearChain(){
	for(int i = 0; i < chain->length; i++){
		free(&chain[i]);
	}
	free(chain);
}

void newBlock(unsigned int pow, unsigned int amount, const char* message){
        //Get length
        int length = chain->length;

        printf("\nCreating new block on index %d...", length);
        struct Block* block = (struct Block*)malloc(sizeof(struct Block));

        //Zero out new block
        memset(block, 0, sizeof(struct Block));

        //Add data to block
        block->index = length;
        block->message = message;
        block->amount = amount;

        //Add block
        chain->block_addrs[length] = (void*)block;
	chain->length = ++length;

        printf("\nBlock created.");
}

void getBlock(int index){
        struct Block* latest_block = (struct Block*)chain->block_addrs[index];
        printf("\n\nBlock:\n{\nIndex: %lu\nMessage: %s\nAmount: %d\n Prev_hash: %s\n}\n", latest_block->index, latest_block->message, latest_block->amount, latest_block->prev_hash);
}
