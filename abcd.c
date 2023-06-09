
// 

const uint8_t game_over_bitmaps[] =
{
	0x07, 0xFF, 0x80, 0x7F, 0x01, 0xF0, 0x0F, 0x1F, 0xFF, 0xF0, //      ############        #######       #####        ####   #################
	0x07, 0xFF, 0x80, 0x7F, 0x01, 0xF0, 0x0F, 0x1F, 0xFF, 0xF0, //      ############        #######       #####        ####   #################
	0x07, 0xFF, 0x80, 0xFF, 0x01, 0xF0, 0x1F, 0x1F, 0xFF, 0xF0, //      ############       ########       #####       #####   #################
	0x1F, 0x00, 0x03, 0xE3, 0xE1, 0xFE, 0x7F, 0x1F, 0x00, 0x00, //    #####              #####   #####    ########  #######   #####            
	0x1F, 0x00, 0x03, 0xE3, 0xC1, 0xFE, 0x7F, 0x1F, 0x00, 0x00, //    #####              #####   ####     ########  #######   #####            
	0xF8, 0x00, 0x0F, 0x00, 0xF9, 0xFF, 0xFF, 0x1F, 0x00, 0x00, // #####               ####        #####  #################   #####            
	0xF8, 0x00, 0x0F, 0x00, 0xF9, 0xFF, 0xFF, 0x1F, 0x00, 0x00, // #####               ####        #####  #################   #####            
	0xF8, 0x00, 0x0F, 0x00, 0xF9, 0xFF, 0xFF, 0x1F, 0x00, 0x00, // #####               ####        #####  #################   #####            
	0xF8, 0x3F, 0x8F, 0x00, 0xF9, 0xFF, 0xFF, 0x1F, 0xFF, 0x80, // #####     #######   ####        #####  #################   ##############   
	0xF8, 0x3F, 0x8F, 0x00, 0xF9, 0xFF, 0xFF, 0x1F, 0xFF, 0x80, // #####     #######   ####        #####  #################   ##############   
	0xF8, 0x0F, 0x8F, 0xFF, 0xF9, 0xFB, 0x9F, 0x1F, 0x00, 0x00, // #####       #####   #################  ###### ###  #####   #####            
	0xF8, 0x0F, 0x8F, 0xFF, 0xF9, 0xF3, 0x9F, 0x1F, 0x00, 0x00, // #####       #####   #################  #####  ###  #####   #####            
	0xFF, 0x0F, 0x8F, 0xFF, 0xF9, 0xF1, 0x9F, 0x1F, 0x00, 0x00, // ########    #####   #################  #####   ##  #####   #####            
	0x1F, 0x0F, 0x8F, 0x80, 0xF9, 0xF0, 0x1F, 0x1F, 0x00, 0x00, //    #####    #####   #####       #####  #####       #####   #####            
	0x1F, 0x0F, 0x8F, 0x80, 0xF9, 0xF0, 0x1F, 0x1F, 0x00, 0x00, //    #####    #####   #####       #####  #####       #####   #####            
	0x07, 0xFF, 0x8F, 0x80, 0xF9, 0xF0, 0x1F, 0x1F, 0xFF, 0xF0, //      ############   #####       #####  #####       #####   #################
	0x07, 0xFF, 0x8F, 0x80, 0xF9, 0xF0, 0x1F, 0x1F, 0xFF, 0xF0, //      ############   #####       #####  #####       #####   #################
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                                                             
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                                                             
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //                                                                             
	0x1F, 0xFC, 0x0F, 0x00, 0xF9, 0xFF, 0xFF, 0x1F, 0xFF, 0x80, //    ###########      ####        #####  #################   ##############   
	0x1F, 0xFE, 0x0F, 0x80, 0xF9, 0xFF, 0xFF, 0x1F, 0xFF, 0x80, //    ############     #####       #####  #################   ##############   
	0x1F, 0xFE, 0x0F, 0x80, 0xF9, 0xFF, 0xFF, 0x1F, 0xFF, 0x80, //    ############     #####       #####  #################   ##############   
	0xF8, 0x0F, 0xCF, 0x80, 0xF9, 0xF0, 0x00, 0x1F, 0x01, 0xF0, // #####       ######  #####       #####  #####               #####       #####
	0xF8, 0x0F, 0xCF, 0x80, 0xF9, 0xF0, 0x00, 0x1F, 0x01, 0xF0, // #####       ######  #####       #####  #####               #####       #####
	0xF8, 0x0F, 0xCF, 0x80, 0xF9, 0xF0, 0x00, 0x1F, 0x01, 0xF0, // #####       ######  #####       #####  #####               #####       #####
	0xF8, 0x0F, 0xCF, 0x80, 0xF9, 0xF0, 0x00, 0x1F, 0x01, 0xF0, // #####       ######  #####       #####  #####               #####       #####
	0xF8, 0x0F, 0xCF, 0x80, 0xF9, 0xF0, 0x00, 0x1F, 0x01, 0xF0, // #####       ######  #####       #####  #####               #####       #####
	0xF8, 0x0F, 0xCF, 0xE7, 0xF9, 0xFF, 0xFC, 0x1F, 0x07, 0xF0, // #####       ######  #######  ########  ###############     #####     #######
	0xF8, 0x0F, 0xCF, 0xE7, 0xF9, 0xFF, 0xFC, 0x1F, 0x07, 0xF0, // #####       ######  #######  ########  ###############     #####     #######
	0xF8, 0x0F, 0x83, 0xFF, 0xE1, 0xF0, 0x00, 0x1F, 0xFE, 0x00, // #####       #####     #############    #####               ############     
	0xF8, 0x0F, 0x83, 0xFF, 0xC1, 0xF0, 0x00, 0x1F, 0xFE, 0x00, // #####       #####     ############     #####               ############     
	0xF8, 0x0F, 0x83, 0xFF, 0xC1, 0xF0, 0x00, 0x1F, 0xFE, 0x00, // #####       #####     ############     #####               ############     
	0xF8, 0x0F, 0x80, 0x7F, 0x01, 0xF0, 0x00, 0x1F, 0x3F, 0x80, // #####       #####        #######       #####               #####  #######   
	0xF8, 0x0F, 0x80, 0x7F, 0x01, 0xF0, 0x00, 0x1F, 0x3F, 0x80, // #####       #####        #######       #####               #####  #######   
	0x1F, 0xFE, 0x00, 0x1C, 0x01, 0xFF, 0xFF, 0x1F, 0x07, 0xF0, //    ############            ###         #################   #####     #######
	0x1F, 0xFE, 0x00, 0x1C, 0x01, 0xFF, 0xFF, 0x1F, 0x07, 0xF0, //    ############            ###         #################   #####     #######
	0x1F, 0xFE, 0x00, 0x1C, 0x01, 0xFF, 0xFF, 0x1F, 0x07, 0xF0, //    ############            ###         #################   #####     #######
};




